/*
ID: merlinf1
PROG: palsquare
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin >> base;
	
	for(int i = 1; i <= 300; ++i)
	{
		string str;
		changeBase(i*i, str, base);
		if(isPalindromic(str))
		{
			string str2;
			changeBase(i, str2, base);
			fout << str2 << " " << str << endl;
		}
	}
    return 0;
}

