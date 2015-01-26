#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool vis[1005][1005];
double dp[1005][1005];
double DP(int n,int k)
{
       if(k==0) return 0;
       if(vis[n][k]) return dp[n][k];
       vis[n][k]=1;
       return dp[n][k]=(double)n/(double)k+DP(n,k-1);
}
int main()
{
       int cs,t;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              int n;
              scanf("%d",&n);
              memset(vis,0,sizeof(vis));
              printf("%.2lf\n",DP(n,n));
       }
} 
