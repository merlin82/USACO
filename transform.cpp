/*
ID: merlinf1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX_SIZE 10

void transform90(char* in, char* out, int num)
{
	int i,j,m,n;
	for(i = 0; i < num; ++i)
	{
		n = num-i-1;
		m = 0;
		for(j = 0; j < num; ++j)
		{
			out[m*num+n] = in[i*num+j];
			++m;
		}
	}
}

void transform180(char* in, char* out, int num)
{
	int i,j,m,n;
	for(i = 0; i < num; ++i)
	{
		n = num-1;
		m = num-i-1;
		for(j = 0; j < num; ++j)
		{
			out[m*num+n] = in[i*num+j];
			--n;
		}
	}
}

void transform270(char* in, char* out, int num)
{
	int i,j,m,n;
	for(i = 0; i < num; ++i)
	{
		n = i;
		m = num-1;
		for(j = 0; j < num; ++j)
		{
			out[m*num+n] = in[i*num+j];
			--m;
		}
	}	
}
void Reflection(char* in, char* out, int num)
{
	int i,j,m,n;
	for(i = 0; i < num; ++i)
	{
		n = num-1;
		m = i;
		for(j = 0; j < num; ++j)
		{
			out[m*num+n] = in[i*num+j];
			--n;
		}
	}
}

bool isEqual(char* in, char* out, int num)
{
	for(int i = 0; i < num*num;++i)
	{
		if(in[i] != out[i])
		{
			return false;
		}
	}

	return true;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int num;
    fin >> num;
	
	char in[MAX_SIZE*MAX_SIZE];
	char reslut[MAX_SIZE*MAX_SIZE];

    int j,k;

	for(j = 0; j < num; ++j)
	{
		for(k = 0; k < num; ++k)
		{
			fin >> in[j*num+k];
		}
	}
	for(j = 0; j < num; ++j)
	{
		for(k = 0; k < num; ++k)
		{
			fin >> reslut[j*num+k];
		}
	}

	char out[MAX_SIZE*MAX_SIZE], out2[MAX_SIZE*MAX_SIZE];

	do {

		transform90((char*)in, (char*)out, num);
		if(isEqual(out, reslut, num))
		{
			fout << 1 << endl;
			break;
			
		}
		transform180((char*)in, (char*)out, num);
		if(isEqual(out, reslut, num))
		{
			fout << 2 << endl;
			break;
		}
		transform270((char*)in, (char*)out, num);
		if(isEqual(out, reslut, num))
		{
			fout << 3 << endl;
			break;
		}
		Reflection((char*)in, (char*)out, num);
		if(isEqual(out, reslut, num))
		{
			fout << 4 << endl;
			break;
		}	
		
		transform90((char*)out, (char*)out2, num);
		if(isEqual(out2, reslut, num))
		{
			fout << 5 << endl;
			break;
		}
		transform180((char*)out, (char*)out2, num);
		if(isEqual(out2, reslut, num))
		{
			fout << 5 << endl;
			break;
		}
		transform270((char*)out, (char*)out2, num);
		if(isEqual(out2, reslut, num))
		{
			fout << 5 << endl;
			break;
		}	
		if(isEqual(in, reslut, num))
		{
			fout << 6 << endl;
			break;
		}
		fout << 7 << endl;
	} while(0);

    return 0;
}

