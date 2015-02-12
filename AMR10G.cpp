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
const int MX = 1e5 + 10 ;
int inp[MX];
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int n = II , k = II ;
        rep(i , n ) inp[i] = II ;
        sort( inp , inp + n );
        int ans = ( inp[k-1] - inp[0] );
        int i ;
        for ( i = 1 ; i <= n - k ; i++ )
            ans = min( ans , inp[i+k-1] - inp[i] );
        printf("%d\n",ans);

    }
    return 0;
}
