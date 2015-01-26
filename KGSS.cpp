 
 
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
const int maxn = 200005;
typedef long long ll ;
 
struct abc
{
    ll first , second ;
} tree[4*maxn];
ll inp[maxn];
abc Pre(int node,int lft,int rgt)
{
     abc X ;
     X.first = 0 ;
     X.second = 0 ;
    if( lft > rgt ) return X;
    if(lft == rgt )
    {
 
        X.first = inp[lft];
        X.second = 0 ;
        tree[node] = X ;
        return X;
    }
    int mid = ( lft + rgt ) / 2 ;
    abc p = Pre(2*node,lft,mid);
    abc q = Pre(2*node+1,mid+1,rgt);
    ll arr[] = {p.first,p.second,q.first,q.second};
    sort(arr,arr+4);
    tree[node].first = arr[3];
    tree[node].second = arr[2];
    return tree[node];
}
abc Update(int node,int lft,int rgt,int x , int y, int val)
{
     abc X ;
     X.first = 0 ;
     X.second = 0 ;
     if( lft > y || rgt < x ) return tree[node] ;
    if(lft == x && rgt == lft)
    {
 
        X.first = val ;
        X.second = 0 ;
        tree[node] = X ;
        return X;
    }
    int mid = (lft+rgt)/2 ;
    abc p , q ;
    p.first = p.second = q.first = q.second = 0 ;
   p = Update(node*2,lft , mid , x, y , val );
   q = Update(2*node+1 , mid+1,rgt , x , y , val );
    ll arr[] = { p.first , p.second , q.first , q.second };
    sort(arr,arr+4);
    tree[node].first = arr[3];
    tree[node].second = arr[2];
    return tree[node];
}
abc Query(int node,int lft , int rgt , int x , int y)
{
     abc X ;
     X.first = 0 ;
     X.second = 0 ;
     if( lft > y || rgt < x ) return X ;
    if ( x <= lft && y >= rgt ) return tree[node];
    int mid = ( lft + rgt ) / 2 ;
    abc p , q ;
    p.first = p.second = q.first = q.second = 0 ;
    //int mid = ( x + y ) / 2 ;
    p = Query(2*node,lft,mid,x,y);
    q = Query(2*node+1,mid+1,rgt,x,y);
    ll arr[] = { p.first , p.second , q.first , q.second };
    sort(arr,arr+4);
    abc ans ;
    ans.first = arr[3];
    ans.second = arr[2];
    return ans;
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int i , n , q , x , y ;
     char ch[3];
     read(n);
     for ( i = 0 ; i < n ; i++ ) read(inp[i]);
     Pre(1,0,n-1);
     read(q);
     while(q--)
     {
         scanf("%s %d %d",&ch,&x,&y);
         if(ch[0] == 'Q' )
         {
             abc X = Query(1,0,n-1,x-1,y-1);
             printf("%lld\n",X.first + X.second );
         }
         else
         {
             Update(1,0,n-1,x-1,x-1,y);
 
         }
     }
   return 0;
}
 
