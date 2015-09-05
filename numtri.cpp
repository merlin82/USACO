/*
ID: merlinf1
PROG: numtri
LANG: C++
*/

#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    vector< vector<int> > numtri;
	int line = 0;
    fin >> line;
	int i = 0,j;
	vector<int> tmpArray;
	int tmp;
	for(; i < line; ++i)
	{
		for(j = 0; j <= i; ++j)
		{
			fin >> tmp;
			tmpArray.push_back(tmp);
		}
		numtri.push_back(tmpArray);
		tmpArray.clear();
	}
	
	for(i=numtri.size()-2;i>=0;--i)
	{
		for(j=0; j<numtri[i].size();++j)
		{
			numtri[i][j] += max(numtri[i+1][j], numtri[i+1][j+1]);
		}
	}

	fout << numtri[0][0] << endl;
    return 0;
}

