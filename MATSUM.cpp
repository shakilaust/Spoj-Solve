//BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#define MAX 1024+10
#define memo(a,b) memset((a),(b),sizeof(a))
using namespace std;
int Row,Col,MaxVal=MAX,tree[MAX][MAX],input[MAX][MAX];
void update(int r,int c,int val)
{
    int i,j;
    for(i=r; i<=Row; i+=(i & -i))
        for(j=c; j<=Col; j+=(j & -j))
            tree[i][j]+=val;
 
}
int read(int r,int c)
{
    int i,j,sum=0;
    for(i=r; i>0; i&=i-1)
        for(j=c; j>0; j &=j-1)
            sum+=tree[i][j];
    return sum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&Row);
        Col=Row;
        memo(tree,0);
        memo(input,0);
        char s[100];
        while(scanf("%s",s))
        {
            if (!strcmp(s,"SUM"))
            {
                int r1,c1,r2,c2;
 
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
 
                r1++,c1++,r2++,c2++;
 
                int res =0;
 
                res+=read(r2, c2) ;
                res-=read(r1 - 1, c2);
                res-=read(r2, c1 - 1);
                res+=read(r1 - 1, c1 - 1);
 
                printf("%d\n",res);
            }
            else if(!strcmp(s,"SET"))
                        {
				int r,c,val;
 
				scanf("%d %d %d",&r,&c,&val);
				r++,c++;
				update(r, c, -input[r][c] + val);
				input[r][c] = val;
			}
              else break;
        }
        puts("");
    }
}
 
