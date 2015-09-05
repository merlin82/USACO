/*
ID: merlinf1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int vnum;
int vreq[25];
int feednum;
int vfeed[15][25];
vector<int> min_given;


int meet(int begin, const vector<int>& had)
{
	for(int i = begin; i < feednum; i++)
	{
		int j = 0;
		for(j = 0; j < vnum; j++)
		{
			if (had[j] + vfeed[i][j] < vreq[j])
			{
				break;
			}
		}
		if (j == vnum)
		{
			return i;
		}
	}

	return -1;
}
void join(int index, vector<int>& had)
{
	for(int i = 0; i < vnum; i++)
	{
		had[i] += vfeed[index][i];
	}
}
void find(int begin, vector<int> had, vector<int> given)
{
	if (!min_given.empty() && (min_given.size() - given.size() < 2))
	{
		return;
	}

	int n = meet(begin, had);
	if (n >= 0)
	{
		given.push_back(n+1);
		min_given = given;
		return;
	}

	vector<int> given2;
	vector<int> had2;
	for(int i = begin; i < feednum; i++)
	{
		given2 = given;
		given2.push_back(i+1);
		had2 = had;
		join(i, had2);
		find(i+1, had2, given2);
	}

}
int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
	fin >> vnum;
	int i,j;
	for(i = 0; i < vnum; i++)
	{
		fin >> vreq[i];
	}

	fin >> feednum;
	for(i = 0; i < feednum; i++)
	{
		for(j = 0; j < vnum; j++)
		{
			fin >> vfeed[i][j];
		}
	}
	vector<int> had;
	for(i = 0; i < vnum; i++)
	{
		had.push_back(0);
	}
	vector<int> given;
	find(0, had, given);

	fout << min_given.size() << " ";
	for (i = 0; i < min_given.size()-1; i++)
	{
		fout << min_given[i] << " ";
	}

	fout << min_given[i] << endl;
    return 0;
}
