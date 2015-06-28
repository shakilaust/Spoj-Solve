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

template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}

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

int dx[]={-1,0,1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 1005 ;

int dp[NX][NX] , SZ[NX] , adj[NX][NX] , deg[NX] ;
int W[NX] , CW[NX] , n , lim , vis[NX] ;

void ini()
{
    rep( i , n + 2 )
    {
        vis[i] = 0 ;
        deg[i] = 0 ;
        SZ[i] =  0 ;
        CW[i] = 0 ;
    }
}
void dfs( int x , int idx )
{
    CW[idx] += W[x];
    SZ[idx]++;
    vis[x] = 1 ;
    rep( i , deg[x] )
    {
        int u = adj[x][i];
        if( vis[u] ) continue ;
        dfs( u , idx );
    }
}
int DP( int idx , int w )
{
    if( idx < 0 ) return 0 ;
    int &ret = dp[idx][w];
    if( ret != -1 ) return ret ;
    ret = DP( idx - 1 , w );
    if( CW[idx] <= w ) ret = max( ret , SZ[idx] + DP( idx - 1 , w - CW[idx] ) );
    return ret ;
}
int main()
{
    while( scanf("%d %d",&n,&lim)==2)
    {
        if( n == 0 && lim == 0 ) break ;
        ini();
        rep( i , n )
        {
            W[i] = II ;
        }
        rep( i , n )
        {
            int k = II ;
            rep ( j , k )
            {
                int y = II ;
                adj[i][deg[i]++] = y - 1 ;
                adj[y - 1][deg[y - 1]++] = i ;
            }
        }
        int id = 0 ;
        rep( i , n )
        {
            if( vis[i] == 0 )
            {
                dfs( i , id );
              //  printf(" id :: %d CW:: %d SZ:: %d\n" , id , CW[id] , SZ[id] );
                id++;
            }
        }
        ms( dp , -1 );
        printf("%d\n",DP( id - 1 , lim ) ) ;
    }

    return 0;
}
