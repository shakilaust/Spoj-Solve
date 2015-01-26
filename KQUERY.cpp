//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
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
const int N = 30000 ;
const int Q = 200000 ;
#define input 1
#define query 2
int n , q , tree[N + 10] , ans[Q + 10];
struct abc
{
    int s , e , val , type , num;
}inp[N+Q+10];
 
bool cmp( abc A , abc B )
{
    if( A.val == B.val ) return A.type > B.type ;
    return A.val > B.val ;
}
void Read(int idx)
{
    while( idx <= n )
    {
        tree[idx] += 1 ;
        idx += ( idx & -idx);
    }
}
int write(int idx)
{
    int sum = 0  ;
    while( idx )
    {
        sum += tree[idx];
        idx -= ( idx & -idx);
    }
    return sum ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    n = II ;
    rep(i,n)
    {
        inp[i].val = II ;
        inp[i].s = i + 1 ;
        inp[i].type = 1 ; // input
    }
    q  = II ;
    int i ;
    for ( i = n ; i < n + q ; i++ )
    {
        inp[i].s = II , inp[i].e = II , inp[i].val = II ;
        inp[i].type = 2 ; // query
        inp[i].num = i - n ;
    }
    sort ( inp , inp + n + q , cmp ) ;
    for ( i = 0 ; i < n + q ; i++ )
    {
        if ( inp[i].type == 1 )  Read(inp[i].s);
        else ans[inp[i].num] = write(inp[i].e) - write( inp[i].s - 1 );
    }
    rep( i , q )
    {
        printf("%d\n",ans[i]);
    }
 
    return 0;
}
 
