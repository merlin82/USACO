/*
ID: merlinf1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isSame(char a, char b)
{
	if(a == b)
	{
		return true;
	}
	if( b == 'w')
	{
		return true;
	}
	return false;
}


struct Beads
{
	Beads(char b, int c)
	{
		beads = b;
		count = c;
	}
	char beads;
	int count;
};

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int num;
	string necklace;
    fin >> num >> necklace;
	if(num <= 0)
	{
		fout << 0 << endl;
		return 0;		
	}
	int state = 0;
	int max = 0;
	int cur = 0;
	char c;
	for(int i = 0; i < num; ++i)
	{
		c = (char) necklace[i];
		
		if(necklace[i] == 'w')
		{
			state = 0;
		}
		else
		{
			state = 1;
		}
		cur = 1;

		for(int j = i+1; j < num+i; ++j)
		{
			if(necklace[j%num] == c || necklace[j%num] == 'w')
			{
				++cur;
			}
			else
			{
				c = necklace[j%num];
				++state;
				if(state > 2)
				{
					break;
				}
				++cur;
			}
		}

		if(cur > max)
		{
			max = cur;
		}
	}

/*

	vector<Beads> CollectArray;
	int count = 1;
	int i;
	for(i = 1; i < num; ++i)
	{
		if(necklace[i-1] == necklace[i])
		{
			++count;
		}
		else
		{
			CollectArray.push_back(Beads(necklace[i-1], count));
			count = 1;
		}
		if(i == num - 1)
		{
			if((necklace[0] == necklace[i]) && (CollectArray.size() > 1))
			{
				CollectArray[0].count += count;
			}
			else
			{
				CollectArray.push_back(Beads(necklace[i], count));
			}
		}
	}
	int j;
	int max = CollectArray[0].count;
	bool bOk;
	char curbeads;
	for(i = 0; i < CollectArray.size()-1; ++i)
	{
		cout << CollectArray[i].beads << " " << CollectArray[i].count << endl;
		count = CollectArray[i].count;
		curbeads = CollectArray[i].beads;
		bOk = false;
		for(j = i+1; j < CollectArray.size()+i; ++j)
		{
			if(isSame(curbeads, CollectArray[j%CollectArray.size()].beads))
			{
				if(curbeads == 'w' && CollectArray[j%CollectArray.size()].beads != 'w')
				{
					curbeads = CollectArray[j%CollectArray.size()].beads;
				}
				count += CollectArray[j%CollectArray.size()].count;
			}
			else
			{
				if(!bOk)
				{
					bOk = true;
					count += CollectArray[j%CollectArray.size()].count;
					curbeads = CollectArray[j%CollectArray.size()].beads;
				}
				else
				{
					break;
				}
			}
		}
		if(count > max)
		{
			max = count;
		}
		
	}
	cout << max << endl;
*/
    fout << max << endl;
	
    return 0;
}

