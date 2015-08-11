#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

map < long long int  , long long int > val ;
long long int x ;

long long int DP( long long int x )
{
    if( x <= 0 ) return 0 ;
    if( x == 1 ) return x ;
    if( val.find( x ) != val.end() ) return val[x];
    val[x] = max( x , DP( x / 2 ) + DP( x / 3 ) + DP( x / 4 ) );
    return val[x];

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being


   while( scanf("%lld",&x) == 1 )
   {
    printf("%lld\n",DP(x));
   }




    return 0;
}
