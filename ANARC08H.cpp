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
int josheplus(int n , int k)
{
    int ans = 0 , i ;
    for ( i = 2 ; i <= n ; i++ )
        ans = ( ans + k ) % i ;
    return ans + 1 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int n , k ;
   while( n = II , k = II )
   {
       if( n  == 0 && k == 0 ) break ;
       printf("%d %d %d\n",n,k,josheplus(n,k));
   }
    return 0;
}
