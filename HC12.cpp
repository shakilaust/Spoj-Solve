 
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
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
 
double const EPS=3e-8;
using namespace std;
 
#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)
 
typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;
 
// For loop
 
#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
 
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
 
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
/* **************************************  My code start here ****************************************** */
const int MX = 10000 + 5  ;
Long inp[MX];
const Long mod = 1000000007;
long long fact[MX];
void pre()
{
       int i;
       fact[0]=fact[1]=1;
       for(i=1;i<MX;i++)
         fact[i]=(fact[i-1]*i)%mod;
 
}
long long BigMod(long long a,long long b,long long m)
{
       if(b==0) return 1;
       long long x=BigMod(a,b/2,m);
       x=(x*x)%m;
       if(b%2)
       x=(x*a)%m;
       return x;
}
long long ModInverse(long long a,long long m)
{
       return BigMod(a,m-2,m);
}
Long combination(int n , int r)
{
    Long Ans = ((fact[n]*ModInverse(fact[r],mod))%mod * ModInverse(fact[n-r],mod))%mod;
    return Ans;
}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
   int cs , t , n , k ;
   pre();
   read(t);
   for ( cs =  1  ; cs <= t ; cs++ )
   {
       read(n) , read(k);
       int i ;
       For(i,n)
       {
           read(inp[i]);
       }
       Long ans = 0 ;
       sort(inp+1,inp+n+1);
       for ( i = n ; i >= k ; i--)
       {
           ans = ( ans + (((combination(i-1,k-1)%mod) * (inp[i]%mod))%mod))%mod;
       }
       printf("Case #%d: %lld\n",cs,ans);
 
   }
 
    return 0;
} 
