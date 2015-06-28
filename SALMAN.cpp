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

template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}


//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int NX = 1e5 + 10  ;
vector < int > adj[NX] ;
Long Salary[NX] ;
int ID[NX] , starting[NX] , ending[NX] , n , q  ;
struct abc
{
    Long sum , mn , lazy ;
};

abc seg[4*NX];

int id ;

void dfs( int x )
{
    ID[++id] = x ;
    starting[x] = id ;
    int sz = adj[x].size();
    rep ( i , sz )
    {
        int u = adj[x][i];
        dfs( u );
    }
    ending[x] = id ; // range peye jacchi
}

void ini( int node , int lft , int rgt )
{
    if( lft == rgt )
    {
        seg[node].sum = seg[node].mn = Salary[ ID[lft] ] ;
        seg[node].lazy = 0 ;
        return ;
    }
    int mid = ( lft + rgt )/2 ;
    ini( node * 2 , lft , mid );
    ini( ( 2 * node ) + 1 , mid + 1 , rgt );
    seg[node].lazy = 0 ;
    seg[node].sum = ( seg[2*node].sum + seg[(2*node)+1].sum);
    seg[node].mn = min( seg[2*node].mn , seg[(2*node)+1].mn);

}
void LazyPropagate( int node , int lft , int rgt )
{
        Long add = (Long) ( rgt - lft + 1 ) * seg[node].lazy ;
        Long up = seg[node].lazy ;
        seg[node].sum += add ;
        seg[node].mn += up ;
        if( lft != rgt )
        {
        seg[(2*node)].lazy += seg[node].lazy ;
        seg[(2*node)+1].lazy += seg[node].lazy;
        }


        seg[node].lazy = 0 ;
}
abc marge( abc x , abc y )
{
    abc res ;
    res.sum = x.sum + y.sum;
    res.mn = min( x.mn , y.mn );
    res.lazy = 0 ;
    return res ;
}
abc query( int node , int lft , int rgt , int x , int y )
{
    if( seg[node].lazy ) LazyPropagate( node , lft , rgt );
    if( lft >= x && y >= rgt ) return seg[node] ;
    int mid = ( lft + rgt )/2 ;
    if( mid >= y ) return query( 2*node , lft , mid , x , y );
    else if( mid < x ) return query((2*node)+1 ,mid + 1 , rgt , x , y );
    else return marge( query( 2*node , lft , mid , x , y ) , query((2*node)+1 ,mid + 1 , rgt , x , y ) );

}
void update( int node , int lft , int rgt , int x , int y , Long val)
{
      if( seg[node].lazy ) LazyPropagate( node , lft , rgt );
      if( lft > y || rgt < x ) return ;
      if( lft >= x && y >= rgt )
      {
          seg[node].lazy += val ;
          seg[node].sum += ((Long) ( rgt - lft + 1 ) * seg[node].lazy );
          seg[node].mn += seg[node].lazy ;
          if( lft != rgt )
          {
              seg[(2*node)].lazy += seg[node].lazy ;
              seg[(2*node)+1].lazy += seg[node].lazy  ;
          }
          seg[node].lazy = 0 ;
          return ;
      }
      int mid = ( lft + rgt )/2 ;

          update( node * 2 , lft , mid , x , y , val );
          update( ( 2 * node) + 1 , mid + 1 , rgt , x , y , val );

      seg[node] = marge( seg[node*2] , seg[(2*node)+1]);


}
void pre()
{
    rep( i , n + 2 )
    {
        adj[i].clear();
    }
}
int main()
{
  // FI ;
 //  FO ;
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        printf("Case %d:\n",cs);
        n = II , q = II ;
        pre();
        For( i , n )
        {
            int x = II ;
            Salary[i] = LL ;
            adj[x].pb(i);
        }
        id = 0 ;
        dfs( 1 );
        ini( 1 , 1 , id );
        rep( i , q )
        {
             int c = II , x = II ;
             int lft = starting[x] , rgt = ending[x];
             abc res = query( 1 , 1 , id , lft , rgt );
            if( c == 1 )
            {
                printf("%lld\n", res.sum );
            }
            else
            {
                Long val = min( (Long) 1000 , res.mn );
                update( 1 , 1 , id , lft , rgt , val );
            }
        }

    }

   return 0;
}
