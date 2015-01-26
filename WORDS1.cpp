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
int in[30],out[30],cnt;
vector <int> adj[30];
bool visit[30];
void dfs(int u)
{     int i;
       visit[u]=1;
       cnt++;
       for(i=0;i<adj[u].size();i++)
       {
              int v=adj[u][i];
              if(visit[v]==0) dfs(v);
       }
}
bool Euler()
{
       int start,sp=-1,i,n=0,s=0,e=0;
       for(i=0;i<26;i++)
       {
              if(in[i] || out[i])
              {
                     start=i;
                     n++;
              }
              if(in[i]==out[i]) continue;
              else if(in[i]==out[i]+1)
              {
                     s++;
                     sp=i;
                     if(s>1) return 0;
              }
              else if(in[i]+1==out[i])
              {
                     e++;
                     if(e>1) return 0;
              }
              else return 0;
       }
       if(s!=e) return 0;
       cnt=0;
       dfs(start);
       return n==cnt;
}
string inp;
int main()
{  int cs,t;
   scanf("%d",&t);
   for(cs=1;cs<=t;cs++)
   {      int i,n,len,Ks,noOddDeg=0;
          memo(in,0);
          memo(out,0);
          memo(visit,0);
 
          for(i=0;i<26;i++) adj[i].clear();
          scanf("%d",&n);
          for(Ks=1;Ks<=n;Ks++)
          {
                 cin>>inp;
                 int u=inp[0]-'a';
                 int v=inp[inp.size()-1]-'a';
                 adj[u].pb(v);
                 adj[v].pb(u);
                 in[u]++,out[v]++;
          }
         printf("%s\n",Euler()==1?"Ordering is possible.":"The door cannot be opened.");
 
 
   }
   return 0;
}
