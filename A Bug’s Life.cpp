 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
 
 
using namespace std;
 
 
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int adj[2005][2005],deg[2005],color[2005];
bool Ok(int u,int col)
{
       color[u]=col;
       int i;
       for(i=0;i<deg[u];++i)
       {
              int child=adj[u][i];
              if(color[child]==-1)  // ekhono kono color dei nai
              {
                     if(!Ok(child,(col+1)%2)) // deowa possible hocche na
                     return false;
              }
              else if(color[child]==col) return false; // same hoye ache
       }
       return true;
}
 
int main()
{
 
    //freopen("in.txt", "r", stdin);
    int cs,T;
    sc(T);
    FOR(cs,1,T)
    {
           int n,m,i,j;
           scanf("%d %d",&n,&m);
           FOR(i,1,n) {
           deg[i]=0;
           color[i]=-1;
           }
 
           rep(i,m)
           {
                  int u,v;
                  scanf("%d %d",&u,&v);
                  adj[u][deg[u]++]=v;
                  adj[v][deg[v]++]=u;
           }
           bool flag=true;
           FOR(i,1,n)
           {
                  if(color[i]==-1)
                  {
                         if(!Ok(i,0))  // possible hocche na
                         {
                                flag=false;
                                break;
                         }
                  }
           }
            printf("Scenario #%d:\n",cs);
        if ( !flag )
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }
 
 
 
}
 
