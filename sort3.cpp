/*
ID: merlinf1
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
	int n;
	int count[3] = {0};
	int num[1000];
    fin >> n;
	int i = 0, j = 0;
	for (; i < n; i++)
	{
		fin >> num[i];
		count[num[i]-1]++;
	}
	
	int c1 = 0, c2 = 0, c3 = 0;
	for(i = 0; i < count[0]; i++)
	{
		if(num[i] == 2)
		{
			c2++;
		}
		else if(num[i] == 3)
		{
			c3++;
		}
	}

	for(i = 0; i < count[1]; i++)
	{
		if(num[i+count[0]] == 1)
		{
			c1++;
		}
		else if(num[i+count[0]] == 3)
		{
			c3++;
		}
	}

	if (c2 > c1)
	{
		c3+=c2;
	}
	else
	{
		c3+=c1;
	}
	fout << c3 << endl;
    return 0;
}
