//BISMILLAHIR RAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 50000+10
#define INF 1<<29
#define LL long long
using namespace std;
struct abc
{
     LL mx,premx,postmx,sum;
};
abc tree[MAX<<2];
int input [MAX];
abc build(int lf,int rt,int node)
{      abc ret;
       if(lf==rt)
       {
              ret.mx=ret.premx=ret.postmx=ret.sum=input[lf];
              return tree[node]=ret;
       }
       int mid=(lf+rt)>>1;
       abc p=build(lf,mid,node<<1);
       abc q=build(mid+1,rt,(node<<1)+1);
       ret.sum=p.sum+q.sum;
       ret.premx=max(p.premx,p.sum+q.premx);
       ret.postmx=max(q.postmx,q.sum+p.postmx);
       ret.mx=max(max(p.mx,q.mx),p.postmx+q.premx);
       return tree[node]=ret;
}
abc query(int lf,int rt,int node,int x,int y)
{
       abc ret;
       if(rt<x || y<lf)  // range er bahire pore jacche, local varibale use korchi so main array te kono problem hobe na
       {
              ret.premx=ret.postmx=ret.mx=-INF;
              ret.sum=0;
              return ret;
       }
       if(x<= lf && rt<=y) return tree[node];
        int mid=(lf+rt)>>1;
       abc p=query(lf,mid,node<<1,x,y);
       abc q=query(mid+1,rt,(node<<1)+1,x,y);
       ret.sum=p.sum+q.sum;
       ret.premx=max(p.premx,p.sum+q.premx);
       ret.postmx=max(q.postmx,q.sum+p.postmx);
       ret.mx=max(max(p.mx,q.mx),p.postmx+q.premx);
       return ret;
}
int main()
{
       int i,N,Q;
       scanf("%d",&N);
       for(i=1;i<=N;i++) scanf("%d",&input[i]);
       build(1,N,1);
       scanf("%d",&Q);
       while(Q--)
       {
              int x,y;
              scanf("%d %d",&x,&y);
              abc ans=query(1,N,1,x,y);
              printf("%lld\n",ans.mx);
       }
}
 
