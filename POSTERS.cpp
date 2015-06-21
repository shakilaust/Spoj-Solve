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

const int MX = 1e7 + 10 ;
const int NX = 40000 + 10 ;
bool seg[ 8 * NX ] , lazy [ 8 * NX ] ;
int num[ MX ] , inp[MX][2] , n;
set < int > s ;
int lc( int x )
{
    return 2*x ;
}
int rc( int x)
{
    return ( 2 * x ) + 1 ;
}
bool query( int node , int  x , int y , int lft , int rgt )
{
    if( lazy[node] )
    {
        seg[node] = 1;
        lazy[lc(node)] = lazy[node];
        lazy[rc(node)] = lazy[node];
        lazy[node] = 0 ;
    }

    if( x >= lft && y <= rgt ) return seg[node];
    if( x > rgt || y < lft ) return 1 ;
    bool ret = 1 ;
    int mid = ( x + y )/2 ;
    ret &= query( lc(node) , x , mid , lft , rgt );
    ret &= query( rc(node) , mid + 1 , y , lft , rgt );
    return ret ;
}

void update( int node , int x , int y , int lft , int rgt )
{

    if( lazy[node] )
    {
        seg[node] = 1;
        lazy[lc(node)] = lazy[node];
        lazy[rc(node)] = lazy[node];
        lazy[node] = 0 ;
    }
     if( x > rgt || y < lft ) return ;
     if( x >= lft && y <= rgt )
     {
         seg[node] = 1 ;
         if( x != y )
         {
             lazy[lc(node)] = lazy[rc(node)] =  1 ;
         }
         lazy[node] = 0 ;
         return ;
     }

    int mid = ( x + y )/2 ;
    update( lc(node) , x , mid , lft , rgt );
    update( rc(node) , mid + 1 , y , lft , rgt );
   
    int xx =  seg[lc(node)];
    int yx =  seg[rc(node)];
    seg[node] = (xx & yx);

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       s.clear();
       n = II ;
       rep ( i , n )
       {
           int x = II , y = II ;
           s.insert( x );
           s.insert( y );
           inp[i][0] = x ;
           inp[i][1] = y ;
       }
       int idx = 1 ;
       forstl( it , s )
       {
           num[*it] = idx++;
       }

       ms( seg , 0 );
       ms( lazy , 0 );
       int i , ans = 0 ;
       for ( i = n - 1 ; i >= 0 ; i-- )
       {
           if( query( 1 , 1 ,idx - 1 , num[inp[i][0]] , num[inp[i][1]] ) == 0 )
           {
               update( 1 , 1 , idx - 1 , num[inp[i][0]] , num[inp[i][1]] );
               ans++;
           }
       }
       printf("%d\n",ans);

   }


    return 0;
}
