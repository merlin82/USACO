/*
ID: merlinf1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class CRoom
{
public:
	void add(int no)
	{
		squares.insert(no);
	}

	void add(CRoom* pRoom)
	{
		squares.insert(pRoom->squares.begin(), pRoom->squares.end());
	}
	bool has(int no)
	{
		return squares.find(no) != squares.end();
	}
	int getSize()
	{
		return squares.size();
	}
private:
	set<int> squares;
	
};

class CRooms
{
public:
	CRoom* getRoom(int no)
	{
		for(int i = 0; i < m_rooms.size(); i++)
		{
			if (m_rooms[i]->has(no))
			{
				return m_rooms[i];
			}
		}
		return NULL;
	}
	void merger(CRoom* a, CRoom* b)
	{
		vector<CRoom*>::iterator it = find(m_rooms.begin(), m_rooms.end(),b);
		m_rooms.erase(it);
		a->add(b);
		delete b;
		b = NULL;
	}
	void addNewRoom(int no)
	{
		CRoom* pRoom = new CRoom();
		pRoom->add(no);
		m_rooms.push_back(pRoom);
	}
	int getRoomCount() 
	{
		return m_rooms.size();
	}
	int getMaxRoomSize()
	{
		int maxsize = 0;
		for(int i = 0; i < m_rooms.size(); i++)
		{
			if (m_rooms[i]->getSize() > maxsize)
			{
				maxsize = m_rooms[i]->getSize();
			}
		}
		return maxsize;
	}

private:
	vector<CRoom*> m_rooms;
};

CRooms rooms;
int m,n;
int walls[50][50];

//1: wall to the west
//2: wall to the north
//4: wall to the east
//8: wall to the south

int NUMBER(int i, int j)
{
	return i*m+j;
}
void genRoom()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//no wall on north
			if ((walls[i][j] & 2) == 0)
			{
				CRoom* pRoom = rooms.getRoom(NUMBER(i-1,j));
				pRoom->add(NUMBER(i,j));
				if ((walls[i][j] & 1) == 0)
				{
					CRoom* pRoom2 = rooms.getRoom(NUMBER(i,j-1));
					if (pRoom != pRoom2)
					{
						rooms.merger(pRoom, pRoom2);
					}
				}
			}
			//no wall on west
			else if ((walls[i][j] & 1) == 0)
			{
				CRoom* pRoom = rooms.getRoom(NUMBER(i,j-1));
				pRoom->add(NUMBER(i,j));
			}
			else
			{
				rooms.addNewRoom(NUMBER(i,j));
			}
		}
	}
}

int removeMax = -1;
int removeI;
int removeJ;
char direction;
void genResult(int i, int j, char dir, int size)
{
	if (size > removeMax)
	{
		removeMax = size;
		removeI = i;
		removeJ = j;
		direction = dir;
	}
}

void findWall()
{
	for(int j = 0; j < m; j++)
	
	{
		for(int i = n-1; i >= 0; i--)
		{
			//north
			if ((walls[i][j] & 2) && i!=0)
			{
				CRoom* pRoom = rooms.getRoom(NUMBER(i,j));
				CRoom* pRoom2 = rooms.getRoom(NUMBER(i-1,j));
				if (pRoom != pRoom2)
				{
					genResult(i+1,j+1,'N',pRoom->getSize()+pRoom2->getSize());
				}
			}//east
			else if ((walls[i][j] & 4)  && j!=(m-1))
			{
				CRoom* pRoom = rooms.getRoom(NUMBER(i,j));
				CRoom* pRoom2 = rooms.getRoom(NUMBER(i,j+1));
				if (pRoom != pRoom2)
				{
					genResult(i+1,j+1,'E', pRoom->getSize()+pRoom2->getSize());
				}
			}
		}
	}
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");

    fin >> m >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			fin >> walls[i][j];
		}
	}


	genRoom();
	findWall();



    fout << rooms.getRoomCount() << endl;
	fout << rooms.getMaxRoomSize() << endl;
	fout << removeMax << endl;
	fout << removeI << " " << removeJ << " " << direction << endl;
    return 0;
}

