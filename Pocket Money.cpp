//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.


 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair

// Macro
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
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

template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//Fast Reader
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

ull toInt(string s)
{
    ull r = 0 ;
    istringstream sin(s);
    sin>>r;
    return r;
}
const ull INF = ( 1 << 64 )  - 1 ;
const int NX = 105 ;


typedef pair < ull , ull > pul ;

int cs , vis[ NX ][ NX ] ;

pul dp[ NX ][ NX ];

char Operator[ NX ] ;
ull inp[ NX ];
int OpIdx , ValIdx ;
char str[ NX + NX ];
pul DP( int s , int e )
{
    if( s == e ) return mp( inp[s] , inp[s] );
    pul &ret = dp[s][e];
    if( vis[s][e] == cs ) return ret ;
    vis[s][e] = cs ;
    ret = mp( 0 , 0 );
    bool first = 0 , second = 0;
    for ( int i = s ; i < e ; i++ )
    {
        if( Operator[ i ] == '+' )
        {
            if( first )
            {
                ret.ff = max( ret.ff , DP( s , i ).ff + DP( i + 1 , e ).ff );
                ret.ss = min( ret.ss , DP( s , i ).ss + DP( i + 1 , e ).ss );
            }
            else
            {
                ret.ff = DP( s , i ).ff + DP( i + 1 , e ).ff ;
                ret.ss = DP( s , i ).ss + DP( i + 1 , e ).ss ;
                first = 1 ;
            }

        }
        else
        {
            if( first )
            {
                ret.ff = max( ret.ff , DP( s , i ).ff * DP( i + 1 , e ).ff );
                ret.ss = min( ret.ss , DP( s , i ).ss * DP( i + 1 , e ).ss );

            }
            else
            {
                ret.ff = DP( s , i ).ff * DP( i + 1 , e ).ff ;
                ret.ss = DP( s , i ).ss * DP( i + 1 , e ).ss ;
                first = 1 ;

            }

        }
    }
    return ret ;
}


int main()
{
    // I will always use scanf and printf
    // May be i won't be a good programmer but i will be a good human being
    int t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        scanf("%s",str);
        OpIdx = 0 , ValIdx = 0 ;
        int len = strlen(str);
        for ( int i = 0; i < len; ++i )
        {
            Long tmp = 0;
            while ( i < len && isdigit( str[i] ) )
            {
                tmp = tmp * 10 + ( str[i] - '0' );
                ++i;
            }
            inp[ ValIdx++ ] = tmp;
            if ( i < len )
                Operator[ OpIdx++ ] = str[i];
        }
        pul ans = DP( 0 , ValIdx - 1 );
        printf("%llu %llu\n",ans.ff , ans.ss );
    }

    return 0;
}
