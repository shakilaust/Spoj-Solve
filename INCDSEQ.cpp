//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
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
const int MX = 1e5 + 10 ;
const int mod = 5000000 ;
int tree[55][MX] , n , k , inp[MX];
map < int , int > ID ;
void write(int x , int y , int val)
{
    while( y  <= n )
    {
        tree[x][y] += val ;
        if( tree[x][y] >= mod ) tree[x][y] -= mod ;
        y += ( y & -y);
    }
}
int sum(int x , int y)
{
    int res = 0 ;
    while( y )
    {
        res += tree[x][y];
        if( res >= mod ) res -= mod ;
        y -= ( y & -y);
    }
    return res ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    n = II , k = II ;
    set < int > s ;
    rep( i , n )
    {
        inp[i] = II ;
        s.insert(inp[i]);
    }
    int idx = 0 , val ;
    forstl( it , s ) ID[*it] = ++idx ;
    rep ( i , n )
    {
        if( !(sum( 1 , ID[inp[i]] ) - sum( 1 , ID[inp[i]] - 1 ) ) )
            write( 1 , ID[inp[i]] , 1 ) ; // find the distinc single element
         for ( int j = 2 ; j <= k ; j++ )
        {
              int val = sum( j - 1 , ID[inp[i]] - 1 ) ;
              int val2 = sum( j , ID[inp[i]] ) - sum( j , ID[inp[i]] - 1 ) ;
              if( val2 < 0 ) val2 += mod ;
              if ( val - val2 >=  0 ) write( j , ID[inp[i]] , val - val2 );
              else write( j , ID[inp[i]] , val - val2 + mod ) ;

        }
    }
    int ans = sum(k,n);
    if( ans < 0 ) ans += mod ;
    printf("%d\n",ans);
    return 0;
}
