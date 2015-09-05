/*
ID: merlinf1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct T_NP
{
	string name;
	int money;
};

T_NP np[10];
int getNpIndex(int npNum, const string& NpName)
{
	int i;
	for(i = 0; i < npNum; ++i)
	{
		if(np[i].name == NpName)
		{
			return i;
		}
	}
	return -1;
}
int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int npNum;
    fin >> npNum;
    int i = 0;
    for(; i < npNum; ++i)
    {
    	fin >> np[i].name;
    }
    
    string giver;
    string recipienter;
    int initMoney;
    int gNum;
    for(i = 0; i < npNum; ++i)
    {
    	fin >> giver;
    	fin >> initMoney >> gNum;
  		int index = getNpIndex( npNum, giver);
  		
    	if(gNum > 0)
    	{
    		int givingMoney = initMoney/gNum;
    		np[index].money -= givingMoney*gNum;
    		int j = 0;
    		for (; j <  gNum; ++j)
    		{
    			fin >> recipienter;
    			int gi = getNpIndex( npNum, recipienter);
    			np[gi].money += givingMoney;
    		}  		
    	}
    }
    
    for(i = 0; i < npNum; ++i)
    {
    	fout << np[i].name << " " << np[i].money << endl;
    }
    
    return 0;
}

