/*
ID: merlinf1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n;
bool rprime(int a, int b){
   int r = a % b;
   while(r != 0){
       a = b;
       b = r;
       r = a % b;
   }
   return(b == 1);
}
/*
int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
	bool b = rprime(2,7);
    fin >> n;

	map<float, string> mmap;
	char tmp[20];
	float f;
	for(float i = n; i >= 1; i--)
	{
		for(float j = 0; j <=i; j++)
		{
			 f = j/i;
			 //if (mmap.find(f) == mmap.end())
			 {
				 sprintf(tmp, "%d/%d", (int)j, (int)i);
				 mmap[f] = tmp;
			 }
		}
	}

	map<float, string>::iterator it = mmap.begin();
	while(it != mmap.end())
	{
		fout << it->second << endl;
		it++;
	}
    return 0;
}
*/
FILE *fout;
void
genfrac(int n1, int d1, int n2, int d2)
{
	if(d1+d2 > n)	/* cut off recursion */
		return;

	genfrac(n1,d1, n1+n2,d1+d2);
	fprintf(fout, "%d/%d\n", n1+n2, d1+d2);
	genfrac(n1+n2,d1+d2, n2,d2);
}

void
main(void)
{
	FILE *fin;

	fin = fopen("frac1.in", "r");
	fout = fopen("frac1.out", "w");
//	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d", &n);

	fprintf(fout, "0/1\n");
	genfrac(0,1, 1,1);
	fprintf(fout, "1/1\n");
}
