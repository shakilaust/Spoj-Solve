#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define MAX 2005
using namespace std;
int a[MAX],dp[MAX][MAX];
bool vis[MAX][MAX];
int DP(int s,int e,int val)
{
       if(s>e) return 0;
       if(vis[s][e]) return dp[s][e];
       vis[s][e]=1;
       dp[s][e]=max(a[s]*val+DP(s+1,e,val+1),a[e]*val+DP(s,e-1,val+1));
       return dp[s][e];
}
int main()
{
       int n,i;
       cin>>n;
       for(i=0;i<n;i++)
          cin>>a[i];
       memset(vis,0,sizeof(vis));
       cout<<DP(0,n-1,1);
 
} 
