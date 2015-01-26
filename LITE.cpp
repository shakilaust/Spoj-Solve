
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
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
 
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
 
/* **************************************  My code start here ****************************************** */
typedef long long ll;
const int maxn = 100005 ;
ll tree[4*maxn + 7] ;
bool  Lazy[4*maxn+7] ;
ll Update(ll node , ll lft , ll rgt , ll l , ll r)
{
    if ( Lazy[node] )
    {
        Lazy[node] = !Lazy[node];
        if(lft!=rgt)
        {
            Lazy[2*node] = !Lazy[2*node];
            Lazy[2*node+1] = !Lazy[2*node+1];
        }
        tree[node] = (rgt - lft + 1 ) - tree[node];
    }
    if( l > rgt || r < lft  ) return tree[node];
    if( l <= lft && r >= rgt )
    {
        if( lft != rgt )
        {
            Lazy[2*node] = !Lazy[2*node];
            Lazy[2*node+1] = !Lazy[2*node+1];
        }
        tree[node] = ( rgt - lft + 1 ) - tree[node];
        return tree[node];
    }
    int mid = ( lft + rgt ) / 2 ;
    return tree[node] = Update(2*node , lft , mid , l , r ) + Update(2*node+1 , mid+1 , rgt , l , r );
}
ll Query(ll node , ll lft , ll rgt , ll l , ll r )
{
      if ( Lazy[node] )
    {
        Lazy[node] = !Lazy[node];
        if(lft!=rgt)
        {
            Lazy[2*node] = !Lazy[2*node];
            Lazy[2*node+1] = !Lazy[2*node+1];
        }
        tree[node] = (rgt - lft + 1 ) - tree[node];
    }
     if( l > rgt || r < lft  ) return 0;
    if( l <= lft && r >= rgt ) return tree[node];
    int mid = ( lft + rgt ) / 2 ;
    return Query(2*node,lft,mid,l,r) + Query(2*node+1,mid+1,rgt,l,r);
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int n , m , op , x , y ;
     read(n) , read(m) ;
     int i ;
     while(m--)
     {
         read(op) , read(x) , read(y);
         if(!op)
         {
             Update(1,0,n,x,y);
         }
         else printf("%lld\n",Query(1,0,n,x,y));
     }
 
 
   return 0;
}
 
