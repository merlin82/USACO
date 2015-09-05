/*
ID: merlinf1
PROG: milk3
LANG: C++
*/

#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
char possible[21] = {0};
map<string, int> checkDup;
int a_size, b_size, c_size;

enum MOVETYPE
{
	A2B,
	A2C,
	B2A,
	B2C,
	C2A,
	C2B
};

void addPossible(int c)
{
	possible[c] = 1;
}

bool isDup(const string& tmp)
{
	if (checkDup.find(tmp) != checkDup.end())
	{
		return true;
	}
	checkDup[tmp] = 1;
	return false;
}
void move(int& src, int& dest, int dest_size)
{
	if((dest_size-dest) > src)
	{
		dest += src;
		src = 0;		
	}
	else
	{
		src -= (dest_size-dest);
		dest = dest_size;
	}
}
void pourMilk(int a, int b, int c, MOVETYPE t)
{
	switch(t)
	{
	case A2B:
		move(a,b,b_size);
		break;
	case A2C:
		move(a,c,c_size);
		break;
	case B2A:
		move(b,a,a_size);
		break;
	case B2C:
		move(b,c,c_size);
		break;
	case C2A:
		move(c,a,a_size);
		break;
	case C2B:
		move(c,b,b_size);
		break;
	}

	if(a == 0)
	{
		addPossible(c);
	}
	string tmp;
	tmp += a+'0';
	tmp += " ";
	tmp += b+'0';
	tmp += " ";
	tmp += c+'0';

	if (!isDup(tmp))
	{
		if(a > 0)
		{
			pourMilk(a, b, c, A2B);
			pourMilk(a, b, c, A2C);
		}
		if(b > 0)
		{
			pourMilk(a, b, c, B2A);
			pourMilk(a, b, c, B2C);
		}
		if(c > 0)
		{
			pourMilk(a, b, c, C2A);
			pourMilk(a, b, c, C2B);
		}
	}
	

}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    
    fin >> a_size >> b_size >> c_size;
	
	addPossible(c_size);
	pourMilk(0, 0, c_size, C2A);
	pourMilk(0, 0, c_size, C2B);
	
	bool first = true;
	for(int i = 0; i < 21; ++i)
	{
		if (possible[i])
		{
			if(!first)
			{
				fout << " ";
			}
			fout << i;
			first = false;
		}
	}
	fout << endl;
    return 0;
}

