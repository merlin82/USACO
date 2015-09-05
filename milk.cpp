/*
ID: merlinf1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class farmer
{
public: 
	int price;
	int count;
};

bool pr(farmer f1, farmer f2)
{
	return f1.price < f2.price;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int need, farmersnum;
    fin >> need >> farmersnum;
	vector<farmer> farmerarray;
	int i = 0;
	for(; i < farmersnum; ++i)
	{
		farmer f;
		fin >> f.price >> f.count;
		farmerarray.push_back(f);
	}

	std::sort(farmerarray.begin(), farmerarray.end(), pr);
	i = 0;
	int sum = 0;
	while(need > 0)
	{
		if(need > farmerarray[i].count)
		{
			sum += farmerarray[i].count*farmerarray[i].price;
			need -= farmerarray[i].count;
		}
		else
		{
			sum += need*farmerarray[i].price;
			break;
		}
		++i;
	}
    fout << sum << endl;
    return 0;
}

