/*
ID: merlinf1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct WorkTime
{
	WorkTime(int s, int e)
	{
		sTime = s;
		eTime = e;
	}
	int sTime;
	int eTime;
};
vector<WorkTime> workArray;

void combine(int pos)
{
	vector<WorkTime>::iterator iter = workArray.begin()+pos+1;
	while(iter != workArray.end())
	{
		if(workArray[pos].eTime > iter->eTime)
		{
			iter = workArray.erase(iter);
			continue;
		}
		else
		{
			if(workArray[pos].eTime >= iter->sTime && workArray[pos].eTime <= iter->eTime)
			{
				workArray[pos].eTime = iter->eTime;
				workArray.erase(iter);
			}
		}
		break;
	}
	if(pos != 0)
	{
		iter = workArray.begin()+pos-1;
		if(iter->eTime >= workArray[pos].sTime)
		{
			if(iter->eTime < workArray[pos].eTime)
			{
				iter->eTime = workArray[pos].eTime;
			}
			workArray.erase(workArray.begin()+pos);
		}	
	}
}
int main() 
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int num;
    fin >> num;
	int begintime, endtime;

	int i,j;
	for(i = 0; i < num; ++i)
	{
		fin >> begintime >> endtime;
		
		for(j = 0; j < workArray.size(); ++j)
		{
			if(begintime <= workArray[j].sTime)
			{
				break;
			}
		}
		workArray.insert(workArray.begin()+j, WorkTime(begintime, endtime));
		combine(j);
	}	
	int max = 0, min = 0;
	for(i = 0; i < workArray.size(); ++i)
	{
		WorkTime *p = &workArray[i];
		if(workArray[i].eTime - workArray[i].sTime > max)
		{
			max = workArray[i].eTime - workArray[i].sTime;
		}
		if(i > 0)
		{
			if(workArray[i].sTime - workArray[i-1].eTime > min)
			{
				min = workArray[i].sTime - workArray[i-1].eTime;
			}
		}
	}
    fout << max << " " << min << endl;
    return 0;
}

