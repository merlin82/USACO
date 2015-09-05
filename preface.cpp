/*
ID: merlinf1
PROG: preface
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
 
const int a[10][10]={{0},{1},{2},{3},{1,1},{0,1},{1,1},{2,1},{3,1},{1,0,1}};
const char b[]="IVXLCDM";
int n,ans[10]={0};
 
void work(int x)
{
     for(int i=0;x!=0;i++,x/=10){
         int y=x%10;
         for(int j=0;j<=6;j++)
             ans[j+2*i]+=a[y][j]; 
     }
}
 
int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
 
    scanf("%d",&n);
 
    for(int i=1;i<=n;i++) work(i);
 
    for(int i=0;i<=6;i++)
        if(ans[i]!=0)
           printf("%c %d\n",b[i],ans[i]);
 
    return 0;
}
