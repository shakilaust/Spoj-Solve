
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
       int sum,min_val;
};
abc tree[3*N];
char inp[N];
void Bulid(int node,int lt,int rt)
{
       if(lt==rt)
       {
              if(inp[lt]=='(')  tree[node].min_val=1;
              else tree[node].min_val=-1;
              tree[node].sum=tree[node].min_val;
 
       }
       else
       {
       int mid=(lt+rt)/2;
       Bulid(2*node,lt,mid);
       Bulid(2*node+1,mid+1,rt);
       tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
       tree[node].min_val=min(tree[node*2].min_val,tree[2*node].sum+tree[2*node+1].min_val);
       }
}
void Update(int node,int lt,int rt,int pos)
{
      if(lt==pos && pos==rt)
       {
              tree[node].min_val*=-1;
              tree[node].sum=tree[node].min_val;
 
       }
       else
       {
       int mid=(lt+rt)/2;
       if(pos<=mid)
       Update(2*node,lt,mid,pos);
       else
       Update(2*node+1,mid+1,rt,pos);
       tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
       tree[node].min_val=min(tree[node*2].min_val,tree[2*node].sum+tree[2*node+1].min_val);
       }
}
 
int main()
{
 
   int cs=1,n,q,in;
   while(scanf("%d",&n)==1)
   {
          scanf("%s",&inp);
          Bulid(1,0,n-1);
          scanf("%d",&q);
          printf("Test %d:\n",cs++);
          while(q--)
          {
                 scanf("%d",&in);
                 if(in)
                 {
                        Update(1,0,n-1,in-1);
                 }
                 else
                 {
                        if(tree[1].min_val==0 && tree[1].sum==0) puts("YES");
                        else puts("NO");
                 }
          }
 
 
   }
 
 
}
 
