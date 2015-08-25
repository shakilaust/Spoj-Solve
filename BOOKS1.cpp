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
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
const int N=505;
long long int a[N];
bool mark[N];
bool check(long long int lim,int k,int m)
{
       int cnt=0,i;
       long long int sum=0;
       for(i=0;i<m;i++)
       {      if(a[i]>lim) return 0;
              sum+=a[i];
              if(sum>lim)
              {
                     sum=a[i];
                     cnt++;
                     mark[i]=1;
              }
       }
       cnt++;
       return cnt<=k;

}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           int m,k,i;
           long long int high=0,low=0,mid,ans;
           scanf("%d %d",&m,&k);
           for(i=0;i<m;i++)
           {
                  scanf("%lld",&a[i]);
                  if(low==-1 || low>a[i]) low=a[i];
                  high+=a[i];
           }
           ans=low;
           low=0;
           while(high>low)
           {
                  mid=(high+low)/2;
                  if(check(mid,k,m))
                  {
                         high=mid;
                         ans=high;

                  }
                  else low=mid+1;
           }
           memo(mark,0);
           high=0;
           int j=0;
           for(i=m-1;i>=0;i--)
           {
                  if(i>=(k-j-1))
                  {
                         high+=a[i];
                         if(high>low)
                         {
                                high=a[i];
                                j++;
                                mark[i]=1;
                         }
                  }
                  else
                  mark[i]=1;
           }
           printf("%lld",a[0]);
           if(mark[0]) printf(" /");
           for(i=1;i<m;i++)
           {
                  printf(" %lld",a[i]);
                  if(mark[i]) printf(" /");
           }
           printf("\n");
    }


}
