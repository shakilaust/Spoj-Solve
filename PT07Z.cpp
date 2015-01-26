//BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define pb push_back
#define MAX 10005
 
using namespace std;
int dist[MAX],mx;
bool vis[MAX];
vector <int> adj[MAX];
void dfs(int node)
{
       int i;
       vis[node]=1;
       for(i=0;i<adj[node].size();i++)
       {
              if(!vis[adj[node][i]])
              {
                     dist[adj[node][i]]=dist[node]+1;
                     dfs(adj[node][i]);
              }
       }
}
void solve()
{
       int n,i,nd,mx=0;
       cin>>n;
       for(i=1;i<n;i++)
       {
              int x,y;
              cin>>x>>y;
              adj[x].pb(y);
              adj[y].pb(x);
       }
       memset(dist,0,sizeof(dist));
       memset(vis,0,sizeof(vis));
       dfs(1);
       for(i=1;i<=n;i++)
       {
              if(mx<dist[i])
              {
                     mx=dist[i];
                     nd=i;
              }
       }
       memset(dist,0,sizeof(dist));
       memset(vis,0,sizeof(vis));
       dfs(nd);mx=0;
          for(i=1;i<=n;i++)
              if(mx<dist[i])
                     mx=dist[i];
       cout<<mx<<endl;
 
}
int main()
{
       solve();
 
} 
