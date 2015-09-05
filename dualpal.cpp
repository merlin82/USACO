/*
ID: merlinf1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool isPalindromic(const string& str)
{
	int s = str.size()/2;
	for(int i = 0; i < s; ++i)
	{
		if(str[i] != str[str.size()-1-i])
		{
			return false;
		}
	}

	return true;
}
char letters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N','O', 'P'};
void changeBase(int source, string& dest, int base)
{

	int remainder = 0;
	do 
	{
		remainder = source%base;
		source = source/base;
		
		dest.insert(dest.begin(), letters[remainder]);		
	} while(source > 0);
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int base, num, start;
    fin >> num >> start;
	
	int find = 0;

	for(int i = start+1; find < num; ++i)
	{
		int dualpal = 0;
		for(base = 2; base <=10; ++base)
		{
			string str;
			changeBase(i, str, base);
			if(isPalindromic(str))
			{
				++dualpal;
				if(dualpal >= 2)
				{
					fout << i << endl;
					++find;
					break;
				}
			}
		}
	}
    return 0;
}

