/*
ID: merlinf1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N, B, D;
int maxnum;

vector<int> result;
int diff(int a, int b)
{
	int d = 0;
	int c = a^b;
	while(c != 0)
	{
		if(c % 2)
		{
			d++;
		}

		c >>= 1;
	}

	return d;
}
bool isMeet(int num)
{
	for(int i = 0; i < result.size(); ++i)
	{
		if(diff(result[i], num) < D)
		{
			return false;
		}
	}

	return true;
}



bool find(int begin)
{
	for(int i = begin; i < maxnum; i++)
	{
		if (isMeet(i))
		{
			result.push_back(i);
			if (result.size() == N)
			{
				return true;
			}
			if(find(i+1))
			{
				return true;
			}
			result.pop_back();
		}
	}

	return false;
}
/*
int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
	fin >> N >> B >> D;
	maxnum = (1<<B);

	find(0);
	for(int i = 0; i < result.size(); ++i)
	{
		if (i%10 == 9 || i == result.size()-1)
		{
			fout << result[i] << endl;
		}
		else
		{
			fout << result[i] << " ";
		}
	}
    return 0;
}
*/

#define SIZE 200000
#define MAX(x,y) ((x)>(y)?(x):(y))
int     best[SIZE];        // best[] holds values of the optimal sub-sequence
 
int main (void) {
    FILE *in  = fopen ("hamming.in", "r");
    FILE *out = fopen ("hamming.out", "w");
    int     i, n, k, x, sol = -1;
 
    fscanf (in, "%d", &n);	// N = how many integers to read in
    for (i = 0; i < n; i++) {
	best[i] = -1;
	fscanf (in, "%d", &x);
	for (k = 0; best[k] > x; k++)
	    ;
	best[k] = x;
	sol = MAX (sol, k + 1);
    }
    fprintf (out, "best is %d\n", sol);
    return 0;
}
