/*
ID: merlinf1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



bool isEqual(char a, char b)
{
	if(a >= 'a')
		a += 'A'-'a';
	if(b >= 'a')
		b += 'A'-'a';
	return a == b;
}
bool isPalindrome(const char* pStr, int start, int end)
{
	char a = pStr[start];
	char b = pStr[end];
	if(!isalpha(a) || !isalpha(b))
	{
		return false;
	}
	while(start < end)
	{
		a = pStr[start];
		b = pStr[end];
		if(!isalpha(a))
		{
			start++;
			continue;
		}
		if(!isalpha(b))
		{
			end--;
			continue;
		}
		if(!isEqual(a,b))
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}
int maxstart = 0;
int maxend = 0;
int maxsize = 0;
void getPalindromefromstartend(const string& str, int start, int end, int sss)
{
	int invalidstart = 0;
	int invalidend = 0;
	while(start >=0 && end < str.size())
	{
		char a = str[start];
		char b = str[end];
		if(!isalpha(a))
		{
			start--;
			invalidstart++;
			continue;
		}
		if(!isalpha(b))
		{
			end++;
			invalidend++;
			continue;
		}
		if(!isEqual(a,b))
		{
			break;
		}
		
		invalidstart = 0;
		invalidend = 0;
			
		sss += 2;
		
		start--;
		end++;
	}
	if(sss > maxsize)
	{
		maxsize = sss;
		maxstart = start+1+invalidstart;
		maxend = end-1-invalidend;
	}
}
void getPalindromefrommid(const string& str, int mid)
{
	int sss = 1;
	int start = mid-1;
	int end = mid+1;
	getPalindromefromstartend(str,start, end, sss);
}

void getPalindromefrommidex(const string& str, int mid)
{
	int sss = 0;
	int start = mid;
	int end = mid+1;
	getPalindromefromstartend(str, start, end, sss);
}
/*
void getPalindrome(const string& str)
{
	for(int i = 0; i < str.size()-1; ++i)
	{
		for(int j = str.size()-1; j > i; --j)
		{
			if(j-i > maxend-maxstart)
			{
				if(isPalindrome(str.c_str(), i, j))	
				{
					maxend = j;
					maxstart = i;
				}

			}
			else
			{
				break;
			}
		}
	}
}
*/
void getPalindrome(const string& str)
{
	for(int i = 0; i < str.size()-maxsize; ++i)
	{
		getPalindromefrommid(str, i);
		getPalindromefrommidex(str, i);
	}
}
int main() 
{

    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    string str,str2;
	char line[81];
	while (!fin.eof())
	{
		fin.getline(line, 81);
		str += line;
		str += '\n';

	}


	if(str.size() > 0)
	{
		getPalindrome(str);
	}

	string palStr;
	palStr = str.substr(maxstart, maxend-maxstart+1);

	fout << maxsize << endl;
	
	int ss = 0;
	for(int i = 0; i < palStr.size(); ++i)
	{
		if(isalpha(palStr[i]))
		{
			++ss;
		}
	}



    
	fout << palStr << endl;
    return 0;
}

