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

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 105 ;
int dis[NX][NX][1 << 5] , vis[NX][NX][ 1 << 5] , r , c ;
char grid[NX][NX];
struct abc
{
    int x , y , mask ;
    abc() {}
    abc(int _x , int _y , int _mask )
    {
        x = _x , y = _y , mask = _mask ;
    }
};
bool out( int x , int y )
{
    if ( x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == '#') return 1 ;
    return 0 ;
}
bool isdoor( int x , int y )
{
    if( grid[x][y] == 'B' || grid[x][y] == 'Y' || grid[x][y] == 'R' || grid[x][y] == 'G' ) return 1 ;
    return 0 ;
}
bool isKey( int x , int y )
{
    if( grid[x][y] == 'b' || grid[x][y] == 'y' || grid[x][y] == 'r' || grid[x][y] == 'g' ) return 1 ;
    return 0 ;
}
int keyval( char ch )
{
    if( ch == 'b' ) return 0 ;
    if( ch == 'y' ) return 1 ;
    if( ch == 'r' ) return 2 ;
    return 3 ;
}
int doorval( char ch )
{
    if( ch == 'B' ) return 0 ;
    if( ch == 'Y' ) return 1 ;
    if( ch == 'R' ) return 2 ;
    return 3 ;
}

int bfs(int x , int y )
{
    ms( dis , -1 );
    ms( vis , 0 );
    abc prv , cur ;
    queue < abc > q ;
    q.push( abc( x , y , 0 ) );
    dis[x][y][0] = 0 ;
    vis[x][y][0] = 1 ;
    while( !q.empty() )
    {
        prv = q.front();
      //  cout << " bow " << prv.x << " " << prv.y << endl ;
        q.pop();
        rep( i , 4 )
        {
            cur.x = prv.x + dx[i];
            cur.y  = prv.y + dy[i];
           // cout << cur.x << " " << cur.y << endl ;
            if( out(cur.x , cur.y ) ) continue ;

            if( isKey(cur.x , cur.y ) )
            {
                cur.mask = prv.mask ;
                cur.mask |= (1 << keyval(grid[cur.x][cur.y]));
                if( vis[cur.x][cur.y][cur.mask] ) continue ;
                vis[cur.x][cur.y][cur.mask] = 1 ;
                dis[cur.x][cur.y][cur.mask] = 1 + dis[prv.x][prv.y][prv.mask];
                q.push(cur);
            }
            else if( isdoor( cur.x , cur.y ) )
            {
                  if( vis[cur.x][cur.y][prv.mask] ) continue ;
                  if( !(prv.mask & ( 1 << doorval(grid[cur.x][cur.y] ) ) )) continue ;
                  vis[cur.x][cur.y][prv.mask] = 1 ;
                  dis[cur.x][cur.y][prv.mask] = 1 + dis[prv.x][prv.y][prv.mask];
                  cur.mask = prv.mask ;
                  q.push(cur);

            }
            else
            {
                if( vis[cur.x][cur.y][prv.mask] ) continue ;
                vis[cur.x][cur.y][prv.mask] = 1 ;
                dis[cur.x][cur.y][prv.mask] = 1 + dis[prv.x][prv.y][prv.mask];
                if( grid[cur.x][cur.y] == 'X' ) return dis[cur.x][cur.y][prv.mask];
                cur.mask = prv.mask ;
                q.push( cur );

            }

        }
    }
    return -1 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    while( scanf("%d %d",&r,&c)==2)
    {
        if( r == 0 && c == 0 ) break ;
        rep( i , r ) scanf("%s",grid[i]);
        int cnt = 0 , x , y ;
        rep( i , r )
        {
            rep( j , c )
            {
                if( grid[i][j] == '*' )
                {
                    x = i ;
                    y = j ;
                    grid[i][j] = '.';
                }
                cnt += ( grid[i][j] == 'X' );
            }
        }
        if( cnt == 0 )
        {
            puts("The poor student is trapped!");
            continue ;
        }
        int ans = bfs( x , y );
        if( ans == -1 )  puts("The poor student is trapped!");
        else printf("Escape possible in %d steps.\n",ans);
    }
    return 0;
}
