//BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1<<29
#define rep(i,n) for(i=0;i<n;i++)
#define FOR(i,j,k) for(i=j;i<=k;i++)
 
using namespace std;
void solve()
{
       int  col;
       while(scanf("%d",&col) && col)
       {
              char str[220],ans[22][22];
              scanf("%s",str);
              int idx=0,i,j;
              int row=strlen(str)/col;
 
              for(i=0;i<row;i++)
              {
                     if(i%2)
                        for(j=col-1;j>-1;j--)
                        ans[i][j]=str[idx++];
                     else
                        for(j=0;j<col;j++)
                         ans[i][j]=str[idx++];
              }
              for(i=0;i<col;i++)
                 for(j=0;j<row;j++)
                     printf("%c",ans[j][i]);
              puts("");
       }
 
}
 
int main()
{
   solve();
} 
