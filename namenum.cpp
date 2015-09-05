/*
ID: merlinf1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void convert(const string& in, string& out)
{
	out.resize(in.size(), 0);
	for(int i = 0; i < in.size(); ++i)
	{
		if(in[i] >= 'A' && in[i] <= 'C')
		{
			out[i] = '2';
		}
		else if (in[i] >= 'D' && in[i] <= 'F')
		{
			out[i] = '3';
		}
		else if (in[i] >= 'G' && in[i] <= 'I')
		{
			out[i] = '4';
		}
		else if (in[i] >= 'J' && in[i] <= 'L')
		{
			out[i] = '5';
		}
		else if (in[i] >= 'M' && in[i] <= 'O')
		{
			out[i] = '6';
		}
		else if (in[i] >= 'P' && in[i] <= 'S' && in[i] != 'Q')
		{
			out[i] = '7';
		}
		else if (in[i] >= 'T' && in[i] <= 'V')
		{
			out[i] = '8';
		}
		else if (in[i] >= 'W' && in[i] <= 'Y')
		{
			out[i] = '9';
		}
		else
		{
			out[i] = '?';
		}
	}
}

int main() 
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    string name, in, out;
    fin >> name;
	
	bool bfind = false;
	ifstream fdict("dict.txt");
    while(!fdict.eof())
	{
		fdict >> in;
		convert(in, out);
		if(out == name)
		{
			bfind = true;
			fout << in << endl;
		}
	}
	if(!bfind)
		fout << "NONE" << endl;
    return 0;
}

