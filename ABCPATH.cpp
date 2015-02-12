//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
#define mp make_pair
using namespace std;
typedef long long Long ;
typedef pair <int ,int > pii ;
#define II ( { int a ; read(a) ; a; } )
#define LL ( { long long int a ; read(a) ; a ; } )
#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int MX = 55 ;
char str[MX][MX];
int vis[MX][MX];
int n , m  , now ;
bool ok( int x , int y , int idx )
{
    if ( x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == idx ) return 0 ;
    return 1 ;
}
int dfs( int x , int y , int idx )
{
    vis[x][y] = idx ;
    int i , r = 1 , mx = 0 ;
    for ( i = 0 ; i < 8 ; i++ )
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( ok(nx,ny,idx) && str[x][y] + 1 == str[nx][ny] )
        {
            int rr = dfs(nx,ny,idx);
            if( rr > mx ) mx = rr ;

        }
    }
    return r + mx ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs = 1 ;
   while( scanf("%d %d",&n,&m) == 2 )
   {
       if( n == 0 && m == 0 ) break ;
       int i , j ;
       rep ( i , n ) scanf("%s",str[i]);
       rep( i , n ) rep( j , m ) vis[i][j] = -1 ;
       int ans = 0 , idx = 0 ;
       rep(i,n)
       {
           rep( j , m)
           {
               if( str[i][j] == 'A' )
               {
                   idx++;
                   ans = max( ans , dfs(i,j,idx) );
               }
           }
       }
       printf("Case %d: %d\n",cs++,ans);
   }
    return 0;
}
