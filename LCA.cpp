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

int deg[NX] , adj[NX][NX] , parnt[NX][20] , Level[NX] , canRoot[NX] ;
int n ;

void init()
{
    rep( i , n + 3 )
    {
        canRoot[i] = 1 ;
        deg[i] = 0 ;
    }
}

void dfs( int x , int par , int lvl )
{
    Level[x] = lvl ;
    parnt[x][0] = par ;
    int i ;
    rep( i , deg[x] )
    {
        int y = adj[x][i];
        if( y == par ) continue ;
        dfs( y , x , lvl + 1 );
    }
}

void ini(int root )
{
    int i , j ;
    for ( i = 0 ; i <= n ; i++ )
    {
        for( j = 0 ; ( 1 << j ) <= n ; j++ ) parnt[i][j] = -1 ;
    }
    dfs( root , -1 , 0 );
    for ( j = 1 ; ( 1 << j ) <= n ; j++ )
    {
        for ( i = 1 ; i <= n ; i++ )
        {
            if( parnt[i][j-1] != -1 )
            {
                parnt[i][j] = parnt[ parnt[i][j-1]][j-1];
            }
        }
    }
}

int LCA( int a , int b )
{
    if( Level[a] < Level[b] ) swap( a , b );
    int lg ;
    for ( lg = 0 ; ( 1 <<lg ) <= Level[a] ; lg++ ) ;
    lg--;
    for (int i = lg ; i >= 0 ; i-- )
    {
        if( Level[a] - ( 1 << i ) >= Level[b] )
        {
            a = parnt[a][i];
        }
    }
    if( a == b ) return a ;
    for ( int i = lg ; i >= 0 ; i-- )
    {
        if( parnt[a][i] != -1 && parnt[a][i] != parnt[b][i] )
        {
            a = parnt[a][i];
            b = parnt[b][i];
        }
    }
    return parnt[a][0];
}
int main()
{

     int cs , t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         n = II ;
         init();
         For( i , n )
         {
             int y = II ;
             rep ( h , y )
             {
                 int x = II ;
                 adj[i][deg[i]++] = x ;
                 canRoot[x] = 0 ;
             }
         }
         int root = 1 ;
         for (int i = 1 ; i <= n ; i++ )
         {
             if( canRoot[i] )
             {
                 root = i ;
                 break ;
             }
         }
         ini( root );
         int q = II ;
         printf("Case %d:\n",cs);
         while( q-- )
         {
             int x = II , y = II ;
             cout << LCA(x,y) << endl ;
         }
     }


    return 0;
}
