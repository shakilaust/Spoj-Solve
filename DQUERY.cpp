 
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
#define MAX3(a,b,c) max(a,max(b,c))
 
double const EPS=3e-8;
using namespace std;
 
 
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
const int N=30005;
 
struct abc
{
       int lt,rt,op,num;
};
abc inp[200000+N+10];
int Prev[1000005],ans[200000+10],tree[3*N];
bool cmp(abc a,abc b)
{
       if(b.rt==a.rt) return a.op<b.op;
       else return a.rt<b.rt;
}
void Update(int node,int lt,int rt,int pos,int val)
{
       if(lt==rt)
       {
              tree[node]=val;
              return ;
       }
       int mid=(lt+rt)/2;
       if(pos<=mid) Update(2*node,lt,mid,pos,val);
       else Update(2*node+1,mid+1,rt,pos,val);
       tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int lt,int rt,int st,int ed)
{
       if(lt>rt) return 0;
       if(st>rt || ed<lt) return 0;
       if(lt>=st && rt<=ed) return tree[node];
       int mid=(lt+rt)/2;
       int x=query(2*node,lt,mid,st,ed);
       x+=query(2*node+1,mid+1,rt,st,ed);
       return x;
}
int main()
{
 
    //freopen("in.txt", "r", stdin);
    int n,i,q;
    while(scanf("%d",&n)==1)
    {
           for(i=0;i<n;i++)
           {
                  scanf("%d",&inp[i].lt);
                  inp[i].rt=i+1;
                  inp[i].op=1;
           }
           scanf("%d",&q);
           for(i=n;i<n+q;i++)
           {
                  scanf("%d %d",&inp[i].lt,&inp[i].rt);
                  inp[i].op=2;
                  inp[i].num=i-n;
           }
           memo(tree,0);
           memo(Prev,0);
           sort(inp,inp+n+q,cmp);
           for(i=0;i<n+q;i++)
           {
                  if(inp[i].op==1)
                  {
                         if(!Prev[inp[i].lt])
                         {
                                Update(1,1,n,inp[i].rt,1);
                                Prev[inp[i].lt]=inp[i].rt;
                         }
                         else
                         {
                                Update(1,1,n,Prev[inp[i].lt],0);
                                Update(1,1,n,inp[i].rt,1);
                                Prev[inp[i].lt]=inp[i].rt;
                         }
                  }
                  else
                  {
                         ans[inp[i].num]=query(1,1,n,inp[i].lt,inp[i].rt);
                  }
           }
           for(i=0;i<q;i++) printf("%d\n",ans[i]);
    }
 
 
 
}
 
