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

int ddx[]={1,0,-1,0};int ddy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 1e6 + 10 ;

Long tree[NX] ;
int n , inp[NX] ;
struct abc
{
    int c , x , y , id ;
};
void add( int idx , Long val )
{
    while( idx <= NX )
    {
        tree[idx] += val ;
        idx += ( idx & -idx);
    }
}

Long sum( int idx)
{
    Long ans = 0 ;
    while( idx )
    {
        ans += tree[idx];
        idx -= ( idx & -idx);
    }
    return ans ;
}
Long ans[NX];
abc q[NX];

int main()
{
    n = II ;
    rep ( i , n )
    {
        inp[i] = II ;
    }
    int qq = II ;
    int now = 0 ;
    stack < int > s ;
    rep( i , qq )
    {
        q[i].c = II ;
        if( q[i].c == 1 )
        {
            q[i].x = II ;
            q[i].y = II ;
            q[i].id = now++;
        }
        else
        {
            q[i].x = II ;
            s.push( q[i].x );
        }
    }
    int id = 1 ;

    while( !s.empty() )
    {
        add( id++ , s.top() );
        s.pop();
    }
    rep( i , n ) add( id++ , inp[i] );
    int add = 0 ;
    int i ;
    for ( i = qq - 1 ; i >= 0 ; i-- )
    {
        if( q[i].c == 1 )
        {
            ans[q[i].id] = sum( q[i].y + add ) - sum( q[i].x + add - 1 );
        }
        else add++;
    }
    rep( i , now ) printf("%lld\n",ans[i]);
    return 0;
}
