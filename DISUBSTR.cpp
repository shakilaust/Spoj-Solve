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
const int N = 10005 ;
struct entry
{
    int nr[2] , p ;
}L[N] ;
int SA[32][N] , stp , cnt , sz;
char inp[N];
bool cmp(entry A , entry B )
{
    if( A.nr[0] == B.nr[0] ) return A.nr[1] < B.nr[1] ;
    return A.nr[0] < B.nr[0] ;
}
int Value(int i)
{
    if( i > 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1] ) return SA[stp][L[i-1].p];
    return i;
 
}
void Suffix()
{
    scanf("%s",inp);
    sz = strlen(inp);
    int i ;
    for ( i = 0 ; i < sz ; i++ )
    {
        SA[0][i] = inp[i]-'a';
    }
    for ( stp = 1 , cnt = 1 ; cnt >> 1 < sz ; cnt <<= 1 , stp++ )
    {
        for ( i = 0 ; i < sz ; i++ )
        {
            L[i].nr[0] = SA[stp-1][i];
            L[i].nr[1] = i + cnt < sz ? SA[stp-1][cnt+i] : -1 ;
            L[i].p = i ;
        }
        sort(L,L+sz,cmp);
        for ( i = 0 ; i < sz ; i++ )
        {
            SA[stp][L[i].p] = Value(i);
        }
    }
}
int LCP(int x , int y)
{
    int ans = 0 , k ;
    if( x == y ) return sz - x ;
    for ( k = stp-1 ; k >=0 && x < sz && y < sz ; k-- )
    {
        if(SA[k][x] == SA[k][y] ) x += (1<<k) , y += ( 1 << k ) , ans += (1<<k);
    }
    return ans;
 
}
void solve()
{
    int ans = 0 , i;
    int a = 0 , b = sz ;
    for ( i = 0 ; i < sz ; i++ )
    {
        int minus = i > 0 ? LCP(L[i].p , L[i-1].p) : 0 ;
        int tmp = sz - L[i].p ;
        int add = tmp - minus ;
        if( add > 0 ) ans += add ;
    }
    printf("%d\n",ans);
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int cs , t ;
     read(t);
     for ( cs  = 1 ; cs <= t ; cs++ )
     {
         Suffix();
         solve();
     }
   return 0;
}
 
