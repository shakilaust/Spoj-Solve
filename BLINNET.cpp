//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
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
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

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
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 1e6 + 10 ;
int n , par[NX] ;
struct abc
{
    int x , y ;
    Long cst ;
};
abc inp[NX];
bool cmp( abc A , abc B )
{
    return A.cst < B.cst ;
}
int findparnt( int x )
{
    if( x == par[x] ) return x ;
    else return par[x] = findparnt( par[x] );
}
void ini()
{
    int i ;
    for ( i = 0 ; i <= n + 1 ; i++ ) par[i] = i ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       n = II ;
       ini();
       int idx = 0 , i ;
       Long ans = 0 ;
       Long c ;
       map < string , int > Id ;
       int now = 1 ;
       for ( int i = 1 ; i <= n ; i++ )
       {
           string a ;
           cin >> a ;
           if( Id.find(a) == Id.end() ) Id[a] = now++;
           int xx = Id[a];
           int lim = II ;
           while( lim-- )
           {
               int yy = II ;
               c = LL ;

                   inp[idx].x = xx ;
                   inp[idx].y = yy ;
                   inp[idx++].cst = c ;

           }
       }
       int cut = 0 ;
       sort ( inp , inp + idx , cmp );
       for ( i = 0 ; i < idx && cut < n - 1 ; i++ )
       {
           int x = findparnt( inp[i].x );
           int y = findparnt( inp[i].y );
           if( x != y )
           {
               par[x] = y ;
               cut++;
               ans += inp[i].cst ;
           }
       }
       cout << ans << endl ;
   }

    return 0;
}
/*
4 5
1 2 3 4
4 1 4
1 1 3 10
4 1 4
2 2 4 2
4 1 4
*/
