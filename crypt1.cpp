/*
ID: merlinf1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//  2 2 2
//x   2 2
//------
//  4 4 4
//4 4 4
//---------
//4 8 8 4

int count = 0;
int num[9] = {0};
bool isValid(int n)
{
	for(int i = 0; i < count; ++i)
	{
		if(n == num[i])
		{
			return true;
		}
	}
	return false;
}

bool isValidNum(int n)
{
	int t = n/1000;
	if(t != 0)
	{
		if(!isValid(t))
		{
			return false;
		}
	}
	int t1 = n/100 - t*10;
	if(!isValid(t1))
	{
		return false;
	}
	int t2 = n/10 - t*100 - t1*10;
	if(!isValid(t2))
	{
		return false;
	}
	int t3 = n%10;
	if(!isValid(t3))
	{
		return false;
	}
	return true;
}

int getValidNum()
{
	int result = 0;
	int i,j,k;
	int value = 0, value2 = 0;
	int max = 1000;
	int base = 0, base2=0;
	int m,n;
	for(m = 0; m < count; ++m)
	{	
		base = num[m];
		for(i = 0; i < count; ++i)
		{
			value = (num[i]*100)*base;
			if(value >= max)
			{
				break;
			}
			for(j = 0; j < count; ++j)
			{
				value = (num[i]*100 + num[j]*10)*base;
				if(value >= max)
				{
					break;
				}
				for(k = 0; k < count; ++k)
				{
					value = (num[i]*100 + num[j]*10 + num[k])*base;
					if(value >= max)
					{
						break;
					}
					if(isValidNum(value))
					{
						for(n = 0; n < count; ++n)
						{
							base2 = num[n];
							value2 = (num[i]*100+num[j]*10+num[k])*base2;
							if(value2 < max)
							{
								if(isValidNum(value2) && isValidNum(value*10+value2))
								{
									result++;
									if(result == 199)
									{
										result = 199;
									}
								}
							}
							else
							{
								break;
							}
						}

					}
				}
			}
		}
	}

	return result;
}

int comp(const void *p, const void *q)
{
    return (*(int *)p - *(int *)q);
}

int main() 
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    fin >> count;
	int i;
	for(i = 0; i < count; ++i)
	{
		fin >> num[i];
	}
	qsort(num, count, sizeof(int), comp);
	
	int result = getValidNum();




    fout << result << endl;
    return 0;
}

