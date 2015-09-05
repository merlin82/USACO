/*
ID: merlinf1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long countvalue(const string& str)
{
	long long ret = 1;
	int i = 0;
	for(; i < str.size(); ++i)
	{
		ret *= (str[i]-'A'+1);
	}
	
	return ret;
}
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet;
    string name;
    char a;
    fin >> comet >>  name;
    
    int iComet = countvalue(comet)%47;
    int iName = countvalue(name)%47;
    if(iComet == iName)
    {
    	fout << "GO" << endl;
    }
    else
    {
    	fout << "STAY" << endl;
    }
    
    return 0;
}

