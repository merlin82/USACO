/*
ID: merlinf1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

char board[13][50] = {0};
int start = 25;
int count = 0;
int size = 6;
int solution[13] = {0};
int colUse[50] = {0};
//void mark(int r, int c, int value)
#define  mark(r,c,value) \
{ \
	colUse[c] += value; \
	for(int i = 0; i < size; ++i) \
	{ \
		int gap = r-i;\
		board[i][c-gap] += value;\
		board[i][c+gap] += value;\
	}\
}

ofstream fout ("checker.out");
ifstream fin ("checker.in");
void search(int r)
{
	if(r == size)
	{
		//ok
		if (count < 3)
		{
			int i = 0;
			for(i = 0; i < size-1; ++i)
			{
				fout << solution[i] << " ";
			}
			fout << solution[i] << endl;
		}
		++count;
		return;
	}

	for(int c = 0; c < size; ++c)
	{
		int p = c+start;
		if(board[r][p] == 0 && colUse[p] == 0)
		{
			solution[r] = c+1;
			mark(r, p, 1);
			search(r+1);
			mark(r, p, -1);
		}
		
	}
}
int main() {

    //int s = clock();
    fin >> size;

	search(0);
    fout << count << endl;

	//int e = clock();
	//cout << e-s<< endl;
    return 0;
}

