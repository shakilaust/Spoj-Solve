 
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
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
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
 
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
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
/* **************************************  My code start here ****************************************** */
const int MX = 111111;
int inp[MX] , dis[10][10];
bool vis[10][10];
bool ok(int x , int y)
{
    if( x < 0 || x > 7 || y < 0 || y > 7 || vis[x][y] ) return 0 ;
    return 1;
}
int dijkstra( pii s , pii d )
{
    priority_queue < pair < int , pii > > pq ;
    int i , j ;
    for ( i = 0 ; i <= 7 ; i++ )
    {
        for ( j = 0 ; j <= 7 ; j++ )
        {
            vis[i][j] = 0 ;
            dis[i][j] = (1<<29);
        }
    }
    pq.push( mp(0,s)) ;
    dis[s.ff][s.ss] = 0 ;
    pair < int , pii > u  ;
    while(!pq.empty())
    {
        u = pq.top();
        int c = -u.ff ;
        int x = u.ss.ff;
        int y = u.ss.ss;
        pq.pop();
        if( x == d.ff && y == d.ss ) return c ;
        if( vis[x][y] ) continue;
        vis[x][y] = 1 ;
        int k ;
        for( k = 0 ; k < 8 ; k++ )
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if( ok(nx,ny))
            {
                int cc = nx*x + ny*y + c ;
                //printf("nx:: %d ny :: %d cc")
                if( dis[nx][ny] > cc )
                {
                    dis[nx][ny] = cc ;
                    pq.push(mp(-cc,mp(nx,ny)));
                }
            }
        }
 
    }
    return -1;
}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int x , y , x1 , y1 ;
    while(scanf("%d %d %d %d",&x,&y,&x1,&y1)==4)
    {
        printf("%d\n",dijkstra(mp(x,y),mp(x1,y1)));
    }
 
 
    return 0;
} 
