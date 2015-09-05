/*
ID: merlinf1
PROG: sprime
LANG: C++
*/

#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int first[]={2,3,5,7};
int next[]={1,3,7,9};

bool isPrime(int n)
{
	int m = sqrt(n)+1;
	for(int i = 2; i < m; ++i)
	{
		if(n%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    
	int len;
    fin >> len;
	
	int total = pow(4,len-1);
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < total; ++j)
		{
			int num = first[i];
			int k = len-2;
			for(; k >=0 ; --k)
			{
				int index = (j&(3<<(2*k))) >> (2*k);
				num = num*10+next[index];
				if(!isPrime(num))
				{
					break;
				}
				
			}
			if(k<0)
			{
				fout << num << endl;
			}
		}

	}

    return 0;
}

