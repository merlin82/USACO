/*
ID: merlinf1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int cmp(const void *a, const void *b)
{
	int p1 = *(int*)a;
	int p2 = *(int*)b;

	if(p1 > p2)
	{
		return -1;
	}
	else if(p1 == p2)
	{
		return 0;
	}
	return 1;
}


int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int maxboards, totalstalls, totalcows, tmp, i;
	int cows[200] = {0};
	int dist[200] = {0};

    fin >> maxboards >> totalstalls >> totalcows;
	for(i = 0; i < totalcows; ++i)
	{
		fin >> tmp;
		cows[tmp-1] = 1;
	}
	
	int j = 0;
	int start = -1;
	int end = -1;
	int rs = 0;
	int re = 0;
	for(i = 0; i < totalstalls; ++i)
	{
		if(cows[i] == 0)
		{
			if(start == -2)
			{
				start = i;
			}
		}
		else
		{
			if(start == -1)
			{
				start = -2;
				rs = i;
			}
			else if(start > 0)
			{
				dist[j] = i - start;
				++j;
				start = -2;
			}
			re = i;
		}
	}
	int num = re - rs + 1;
	if(j+1 < maxboards)
	{
		for(i = 0; i < j; ++i)
		{
			num -= dist[i];
		}
	}
	else
	{
		qsort(dist, j, sizeof(int), cmp);
		for(i = 0; i < maxboards-1; ++i)
		{
			num -= dist[i];
		}
	}

    fout << num << endl;
    return 0;
}

