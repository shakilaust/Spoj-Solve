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
const int MX = 100000 ;
const int INF = 1e9 + 10 ;
vector <int> seg[3*MX+10];
int inp[MX+10];
void build(int lft , int rgt , int node)
{
    if( lft == rgt )
    {
        seg[node].pb(inp[lft]);
        return ;
    }
    int mid = ( lft + rgt )/ 2 ;
    build(lft,mid,node*2);
    build(mid+1,rgt,node*2+1);
    int lfsz = seg[node*2].size() , szrt = seg[node*2+1].size() , i , j ;
    for ( i = 0 , j = 0 ; i < lfsz && j < szrt ; )
    {
        if( seg[2*node][i] < seg[2*node+1][j] )
            seg[node].pb(seg[2*node][i++]);
        else seg[node].pb(seg[2*node+1][j++]);
    }
    while( i < lfsz )  seg[node].pb(seg[2*node][i++]);
    while(j < szrt ) seg[node].pb(seg[2*node+1][j++]);
}
int query(int node , int lft , int rgt , int x , int y , int val )
{
    if ( rgt < x || lft > y ) return 0;
    if( x <= lft && rgt <= y )
    {
        return upper_bound(seg[node].begin(),seg[node].end(),val) - seg[node].begin();
    }
    int mid = ( lft + rgt ) / 2 ;
    return query(node*2,lft,mid,x,y,val) + query(node*2+1,mid+1,rgt,x,y,val);
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int n = II , q = II , i , hi = -INF , lo = INF ;
   rep(i,n)
   {
       inp[i] = II ;
       hi = max( inp[i] , hi );
       lo = min( inp[i] , lo );
   }
   build(0,n-1,1);
   rep(i,q)
   {
       int x = II , y = II , val = II ;
       x-- , y-- ;
       int low = lo , high = hi , ans , mid ;
       while( low <= high )
       {
           int mid = ( low + high )/ 2 ;
           if( query(1,0,n-1,x,y,mid) >= val )
           {
               ans = mid ;
               high = mid - 1 ;
           }
           else low = mid + 1 ;
       }
       printf("%d\n",ans);
   }
    return 0;
}
