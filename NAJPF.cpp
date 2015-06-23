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
const int NX = 1e6 + 10 ;

char t[NX] , p[NX] ;

int match[NX] ;

vector < int > ans ;

void kmp( )
{
    ans.clear();
    match[0] = match[1] = 0 ;
    int sz = strlen(p);
   // cout << t << " " << p << " len " << sz << endl ;
    int i , j = 0 ;
    for ( i = 2 ; i <= sz ; i++ )
    {
        if( j && p[j] != p[i - 1] ) j = match[j];
        if( p[j] == p[i - 1] ) j++;
        match[i] = j ;
    }
    //printf("here\n");
    int sza = strlen( t );
    j = 0 ;
    for ( i = 0 ; i < sza ; i++ )
    {
        while( j && p[j] != t[i] ) j = match[j];
        if( p[j] == t[i] ) j++;
        if( j == sz )
        {
            ans.pb( i - sz + 2 );
            j = match[j];
        }
    }
}


int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , tt = II ;
   // getchar();
   for ( cs = 0 ; cs < tt ; cs++ )
   {
       if( cs ) printf("\n");
       scanf("%s %s",t,p);
       // getchar();
      // printf(" how \n");
       kmp();
       if( ans.size() == 0 )
       {
           puts("Not Found");
       }
       else
       {
           int sz = ans.size();
           cout << sz << endl ;
           rep( i , sz - 1 ) printf("%d ",ans[i]);
           printf("%d\n",ans[sz-1]);
       }
   }

    return 0;
}
