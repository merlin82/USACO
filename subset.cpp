/*
ID: merlinf1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

using namespace std;
 
int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");
 
    int n,max;
    unsigned long dp[10000];
    fin>>n;
    max=(n*(n+1))/2;
    if (max&1==1) 
    {
                  fout<<0<<endl;
                  return 0;
                  }
    max/=2;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=max;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];
    }
    fout<<dp[max]/2<<endl;
    return 0;
}
/*
int validnum = 0;
int n;
void check(int num, int sum){

	if (num > sum)
	{
		check(sum, sum);
		return;
	}
	else
	{
		int totlesum = ((1+num)*num) >> 1;
		if (sum > totlesum)
		{
			return;
		}
		if (sum == totlesum)
		{
			validnum+=1;
			return;
		}

		//选num的
		{
			check(num-1, sum-num);
		}
		//不选num的
		{
			check(num-1, sum);
		}
	}

	/*
	if (num == sum)
	{
		validnum++;
		return;
	}
	else if (num < sum)
	{
		sum -= num;
		int i = num-1;
		if (i > sum)
		{
			i = sum;
		}

		int totlesum = ((1+i)*i) >> 1;
		if (sum > totlesum)
		{
			return;
		}
		if (sum == totlesum)
		{
			validnum++;
			return;
		}
		
		for(; i >=1; --i)
		{
			check(i, sum);
		}
	}
	*//*
}

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    
    fin >> n;

	validnum = 0;
	int totlesum = ((1+n)*n) >> 1;
	if (totlesum % 2)
	{
		fout << 0 << endl;
		return 0;
	}

	int sum = totlesum >> 1;
	
	
	check(n-1, sum-n);
	

    fout << validnum << endl;

	return 0;
}

*/