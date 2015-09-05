/*
ID: merlinf1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int month[13] = 
{
	0,
	31,
	31+28,
	31+28+31,
	31+28+31+30,
	31+28+31+30+31,
	31+28+31+30+31+30,
	31+28+31+30+31+30+31,
	31+28+31+30+31+30+31+31,
	31+28+31+30+31+30+31+31+30,
	31+28+31+30+31+30+31+31+30+31,
	31+28+31+30+31+30+31+31+30+31+30,
	31+28+31+30+31+30+31+31+30+31+30+31,
};

int Day[7] = {0};
int countDay(int year, int beginDay)
{
	int leap = 0;
	if((year%4 == 0 && year%100!=0) || year%400 == 0)
	{
		leap = 1;
	}
	int i = 0;
	int weekday = 0;
	int day;
	for(; i < 12; ++i)
	{
		day = (month[i] + 12 + beginDay);
		if(i > 1)
		{
			day += leap;
		}
		weekday = day%7;
		++Day[weekday];
	}

	return month[12]+leap;
}

int main() 
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int nyear;
    fin >> nyear;
	
	int i;
	int beginDay = 0;
	for(i = 0; i < nyear; ++i)
	{
		beginDay += countDay(1900+i, beginDay);
	}

	fout << Day[5] << " " << Day[6];
	
	for(i = 0; i < 5; ++i)
	{
		fout <<  " ";
		fout << Day[i];
	}
	fout << endl;
    return 0;
}

