 
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
const int maxn = 200000 + 100 ;
#define imax 1023456789
/* struct abc
{
    ll val , id ;
}take;
bool cmp( abc A , abc B )
{
    if( A.val == B.val ) return A.id < B.id ;
    return A.val < B.val ;
} */
class things {
	public :
        ll val ;
		ll id ;
 
};
 
bool operator < ( things a , things b ) {
	if( a.val != b.val ) return a.val < b.val ;
	return false ;
}
 
ll inp[maxn] , cnt[maxn] , n , q , row ;
vector < things > Inp[maxn];
char str[10];
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     read(n) , read(q) ;
     int i , j , k  , x , y , v , now ;
     int idx = 0  , lim = sqrt(n) + 1 ;
     row = 0 ;
     things take ;
     for ( i = 0 ; i < n ; i++ )
     {
         read(inp[i]);
         take.val = inp[i];
         take.id = i ;
         Inp[row].pb(take);
         cnt[row]++;
         idx++;
         if(idx == lim  )
         {
             idx = 0 ;
             row++;
         }
     }
     if( idx ) row++;
     for ( i = 0 ; i < row ; i++ ) sort(Inp[i].begin(),Inp[i].end());
     while(q--)
     {
         ll ans = 0 ;
         scanf("%s",str);
         if(str[0] == 'C' )
         {
             scanf("%d %d %d",&x,&y,&v);
             x-- ;
             y-- ;
           //  printf("x:: %d y::  %d\n",x,y);
             now = x / lim ;
             if ( (x / lim) == ( y / lim )) {
             for ( i = 0 ; i < cnt[now] ; i++ )
             {   //  printf("Id ::%d val :: %d \n", Inp[now][i].id , Inp[now][i].val);
                 if(Inp[now][i].id >= x && Inp[now][i].id <= y && Inp[now][i].val <= v ) ans++;
             }
             }
             else
             {
               //  printf("now :: %d\n",now);
                 for ( i = 0 ; i < cnt[now] ; i++ )
                 if(Inp[now][i].id >= x && Inp[now][i].id <= y && Inp[now][i].val <= v ) ans++;
                 j = y / lim ;
                 for ( i = now + 1 ; i < j ; i++ )
                 {
                     things take ;
                    take.val = v ;
                    take.id = imax  ;
 
                    ans += upper_bound(Inp[i].begin() , Inp[i].end() , take ) - Inp[i].begin() ;
                   // printf("Ans :: %lld\n",ans);
                 }
                 now = j ;
                 for ( i = 0 ; i < cnt[now] ; i++ )
                 {
                     if(Inp[now][i].id >= x && Inp[now][i].id <= y && Inp[now][i].val <= v ) ans++;
                 }
 
 
             }
              printf("%lld\n",ans);
 
         }
         else
         {
             scanf("%d %d",&x,&v);
             x--;
             now = x / lim ;
             for ( i = 0 ; i < cnt[now] ; i++ )
             {
                 if ( Inp[now][i].id == x )
                 {
                     Inp[now][i].val = v ;
                     break;
                 }
             }
             sort(Inp[now].begin(),Inp[now].end());
 
 
         }
 
     }
   return 0;
}
 
