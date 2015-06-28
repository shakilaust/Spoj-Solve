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
const int NX = 30 ;
const int INF = ( 1 << 29 );

char inp[NX][NX] ;

int n , m , vis[NX][NX] , dis[NX][NX] ;

bool ok( int x , int y )
{
    if( x < 0 || x >= n || y < 0 || y >= m ) return 0 ;
    if( inp[x][y] == 'X' || vis[x][y] ) return 0 ;
    return 1 ;
}


void dijkstra( int sx , int sy , int dx , int dy )
{

    dis[sx][sy] = 0 ;
    priority_queue < pair < int , pii > > pq ;
    pq.push( mp( 0 , mp( sx , sy ) ) ) ;
    while( !pq.empty() )
    {
        pair < int , pii > prv = pq.top();
        pq.pop();
        int c = prv.ff * ( -1 );
        int x = prv.ss.ff ;
        int y = prv.ss.ss ;
        if( vis[x][y] ) continue ;
        if( x == dx && y == dy )
        {
            printf("%d\n",dis[x][y]);
            break ;
        }
        vis[x][y] = 1 ;
        rep( i , 4 )
        {
            int nx = x + ddx[i];
            int ny = y + ddy[i];
            int cc ;
            if( ok(nx,ny) )
            {
                if( inp[nx][ny] >= '0' && inp[nx][ny] <= '9' )
                cc = inp[nx][ny] - '0' ;
                else
                cc = 0 ;
                if( dis[nx][ny] > c + cc )
                {
                    dis[nx][ny] = c + cc ;
                    pq.push( mp(-dis[nx][ny] , mp( nx,ny) ) );
                }

            }
        }
    }
}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   while( scanf("%d %d",&m,&n) == 2 )
   {
       if( n == 0 && m == 0 ) break ;
       rep( i , n ) scanf("%s",inp[i]);
       int sx , sy , dx , dy ;
       rep( i , n )
       {
           rep( j , m )
           {
               vis[i][j] = 0 ;
               dis[i][j] = INF ;
               if( inp[i][j] == 'S' )
               {
                   sx = i ;
                   sy = j ;
               }
               if( inp[i][j] == 'D' )
               {
                   dx = i ;
                   dy = j ;
               }
           }
       }
       dijkstra( sx , sy , dx , dy );
   }


    return 0;
}
