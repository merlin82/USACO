/*
ID: merlinf1
PROG: clocks
LANG: C++
*/
#pragma warning(disable:4786)


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <string.h>
using namespace std;

class Clocks
{

private:
	char m_orgClock[9];
	
};

class Info
{
public:
	char clocks[9];
	string way;
	bool operator==(const Info& i)
	{
		return clocks == i.clocks;
	}
};

int action[9][9] = {
	{3,3,0,3,3,0,0,0,0},
	{3,3,3,0,0,0,0,0,0},
	{0,3,3,0,3,3,0,0,0},
	{3,0,0,3,0,0,3,0,0},
	{0,3,0,3,3,3,0,3,0},
	{0,0,3,0,0,3,0,0,3},
	{0,0,0,3,3,0,3,3,0},
	{0,0,0,0,0,0,3,3,3},
	{0,0,0,0,3,3,0,3,3}
};
void transform(int move, const Info& org, Info& dest)
{
	dest.way = org.way;
	char w = '1' + move;
	dest.way += w;
	
	for(int i = 0; i < 9; ++i)
	{
		char tmp = org.clocks[i] + action[move][i];
		if (tmp > 12)
		{
			tmp -= 12;
		}
		dest.clocks[i] = tmp;
	}
	
	
}

int pos(const string& str)
{
	int t = 0;
	for(int i = 0; i < 9; ++i)
	{
		t*=4;
		t+=str[i]/3-1;
	}
	return t;
}
int main() {
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");
    int t;
	string dest;
	string org;
	int i = 0;
	for(i = 0; i < 9; ++i)
	{
		fin >> t;
		org += char(t);
		dest += char(12);
	}

    if (org == dest)
	{
		return 0;
	}
	
	
	Info* begin = new Info();
	Info* tmp = new Info();
	memcpy(begin->clocks,org.c_str(), 9);
	list<Info*> stt;
	list<Info*> cache;
	stt.push_back(begin);
	
	char* dup = new char[262144];
	memset(dup, 0, 262144);
	dup[pos(org)] = 1;

	i = 0;
	while(1)
	{
		int j = 0;
		
		for(; j < 9; ++j)
		{
			transform(j, **stt.begin(), *tmp);
			if (memcmp(tmp->clocks, dest.c_str(), 9) == 0)
			{
				break;
			}
			else
			{
				int p = pos(tmp->clocks);
				if(dup[p] == 0)
				{
					stt.push_back(tmp);
					dup[p] = 1;
					if(!cache.empty())
					{
						tmp = *cache.begin();
						cache.erase(cache.begin());
					}
					else
					{
						tmp = new Info();
					}
				}

			}
		}
		if(j != 9)
		{
			break;
		}
		Info* p = *stt.begin();
		stt.erase(stt.begin());
		cache.push_back(p);

		++i;
	}

	for(i = 0; i < tmp->way.size(); ++i)
	{
		fout << tmp->way[i];
		if(i != tmp->way.size()-1)
		{
			fout << " ";
		}
	}
	fout << endl;
    return 0;
}
