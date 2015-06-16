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

const int MX = 1e7 + 10 ;
const int XX =  50000 + 10 ;
const int open = 1 ;
const int point = 2 ;
const int close = 3 ;

struct abc
{
    int x , y , val ,  priority , lim ;
};

abc inp[MX];
Long tree[MX];
Long ans[XX];
bool cmp( abc A  , abc B )
{
    if( A.x == B.x )
    {
        if( A.y == B.y )
        {
            return A.priority < B.priority ;
        }
        else return A.y < B.y ;
    }
    return A.x < B.x ;
}
void add( int x , int v )
{
    while( x < MX )
    {
        tree[x] += v ;
        x += ( x & -x );
    }
}
Long sum( int x )
{
    Long ans = 0 ;
    while( x )
    {
        ans += tree[x];
        x -= ( x & -x );
    }
    return ans ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int n = II ;
        rep( i , n )
        {
            inp[i].x = II , inp[i].y = II , inp[i].val = II ;
            inp[i].x++;
            inp[i].y++;
            inp[i].priority = point ;
        }
        int idx = n ;
        int r = II ;
        rep( i , r )
        {
            inp[idx].x = II ;
            inp[idx].y = II ;
            inp[idx].x++;
            inp[idx].y++;
            inp[idx].priority = open ;
            inp[idx].val = i ;
            idx++;
            inp[idx].x = II ;
            inp[idx].y = II ;
            inp[idx].x++;
            inp[idx].y++;
            inp[idx].priority = close ;
            inp[idx].val = i ;
            inp[idx-1].lim = inp[idx].y ;
            inp[idx].lim = inp[idx-1].y ;
            idx++;
        }
        sort ( inp , inp + idx , cmp );
        ms( tree , 0 );
        ms( ans , 0 );
        rep( i , idx )
        {
            if(inp[i].priority == point ) add( inp[i].y , inp[i].val );
            else if( inp[i].priority == open ) ans[inp[i].val] -= ( sum( inp[i].lim ) - sum( inp[i].y - 1 ) );
            else ans[inp[i].val] += ( sum(inp[i].y ) -  sum( inp[i].lim - 1 ) );
        }
        rep( i , r ) printf("%lld\n",ans[i]);
    }
    return 0;
}
