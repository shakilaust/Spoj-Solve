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
 
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
 
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
/* **************************************  My code start here ****************************************** */
const int MX = 1e6+7 ;
int check[MX] , prime[MX]  , idx ;
int Ans[MX][12];
 
void seive()
{
    int i , j ;
    prime[idx++] =  2 ;
    for ( i = 3 ; i*i < MX ; i+= 2)
    {
        if( check[i] == 0 )
        {
            prime[idx++] = i ;
            for ( j = i*i ; j < MX ; j+= (2*i))
            {
                check[j] = 1 ;
            }
        }
    }
    while( i < MX )
    {
        if( check[i] == 0 ) prime[idx++] = i ;
        i+=2;
    }
}
void Fact(int num)
{
    int cnt = 0 , i , mem = num ;
    for ( i = 0 ; i < idx && prime[i]*prime[i] <= num ; i++ )
    {
        int r = 0 ;
        while( num % prime[i] == 0 )
        {
            r++;
            num/=prime[i];
        }
        if( r ) cnt++;
    }
    if( num > 1 ) cnt++;
    Ans[mem][cnt] = 1 ;
    for ( i = 0 ; i <= 10 ; i++ ) Ans[mem][i] += Ans[mem-1][i];
 
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
 
    seive();
    int i ;
    Ans[1][0] = 1 ;
    for ( i = 2 ; i < MX ; i++ ) Fact(i);
    int cs , t , a , b , n ;
    read(t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        read(a) , read(b) , read(n) ;
        printf("%d\n",Ans[b][n]-Ans[a-1][n]);
    }
 
    return 0;
}
 
