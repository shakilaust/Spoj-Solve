// BISMILLAHIRRAHIM
// Problem H
 
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string a,b;
int dp[2005][2005];
int DP()
{
       int i,j,len1=a.size(),len2=b.size();
       for(i=1;i<=len1;i++) dp[i][0]=i;
       for(j=1;j<=len2;j++) dp[0][j]=j;
       for(i=1;i<=len1;i++)
          for(j=1;j<=len2;++j)
          {
 
                        if(a[i-1]==b[j-1])
                        {
                              dp[i][j]=dp[i-1][j-1];
                        }
                        else
                        {
                               dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                        }
          }
       return dp[len1][len2];
 
}
int main()
{
   int n,cs;
   scanf("%d",&n);
   for(cs=1;cs<=n;cs++)
   {
          cin>>a>>b;
          printf("%d\n",DP());
 
   }
 
 
} 
