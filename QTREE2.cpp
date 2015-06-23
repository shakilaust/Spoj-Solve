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
const int NX = 10000 + 10 ;
vector < int > adj[NX] , cost[NX] ;
int  Level[NX] , parnt[NX][20] , n ;
Long dist[NX] ;
char str[100];
void dfs( int x , int frm , int lvl )
{
    Level[x] = lvl ;
    parnt[x][0] = frm ;
    if( frm == -1 ) dist[x] = 0 ;
    int sz = adj[x].size();
    rep( i , sz )
    {
        int u = adj[x][i];
        if( u == frm ) continue ;
        dist[u] = dist[x] + cost[x][i];
        dfs( u , x , lvl + 1 );
    }
}

void ini()
{
    int i , j ;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 0 ; ( 1 << j ) < n ; j++ ) parnt[i][j] = -1 ;
    }
    dfs( 1 , -1 , 0 );
    for ( j = 1 ; ( 1 << j ) < n ; j++ )
    {
        for ( i = 1 ; i <= n ; i++ )
        {
            if( parnt[i][j-1] != -1 )
            {
                parnt[i][j] = parnt[parnt[i][j-1]][j-1] ;
            }
        }
    }
}
int LCA(int a , int b)
{
    if( Level[a] < Level[b] ) swap( a , b );
    int lg , i ;
    for ( lg = 1 ; ( 1 << lg ) <= Level[a] ; lg++ );
    lg--;
    for ( i = lg ; i >= 0 ; i-- )
    {
        if( Level[a] - ( 1 << i ) >= Level[b] )
        {
            a = parnt[a][i];
        }
    }
    if( a == b ) return a ;
     for ( i = lg ; i >= 0 ; i-- )
    {
        if ( parnt[a][i] !=-1 && parnt[a][i] != parnt[b][i])
        {
            a = parnt[a][i] ;
            b = parnt[b][i] ;
        }
    }
    return parnt[a][0] ;
}
int go( int u , int to )
{
    int i = 0 ;
    while( to )
    {
        if( to & 1 )
        {
            u = parnt[u][i];
        }
        i++;
        to >>= 1 ;
    }
    return u ;
}
void cleankori()
{
    int i ;
    for ( i = 0 ; i <= n + 1 ; i++ )
    {
        adj[i].clear();
        cost[i].clear();
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        n = II ;
        cleankori() ;
        rep( i , n - 1 )
        {
            int x = II , y = II , c = II ;
            adj[x].pb(y);
            adj[y].pb(x);
            cost[x].pb(c);
            cost[y].pb(c);
        }
        ini();
        while( scanf("%s" , str) && strcmp( str , "DONE" ) )
        {
            if( !strcmp( str , "DIST") )
            {
                int x = II , y = II ;
                int l = LCA( x , y );
                printf("%lld\n",dist[x] + dist[y] - 2 * dist[ LCA( x , y ) ] );
            }
            else
            {
                int x = II , y = II , k = II ;
                k--;
                int l = LCA( x , y );
                int len1 = Level[x] - Level[l];
                int len2 = Level[y] - Level[l];
                if( len1 >= k )
                {
                    printf("%d\n",go( x , k ) );
                }
                else printf("%d\n",go( y , len2 - ( k - len1 ) ) );
            }
        }


    }



    return 0;
}
