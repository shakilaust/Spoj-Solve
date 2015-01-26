#include <stdio.h>
#include <string.h>
bool a[20005]={0};
void solve()
{  // memset(a,0,sizeof(a));
    int n,ct=0,in,i,mx=-1;
    scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         scanf("%d",&in);
         a[in]=1;
             if(a[in-1] && a[in+1])
             ct-=1;
             else if(a[in-1] || a[in+1])
             ct=ct;
             else
             ct+=1;
         printf("%d\n",ct);
 
 
     }
 
 
    printf("Justice\n");
}
int main()
{
    solve();
}
 
 
 
