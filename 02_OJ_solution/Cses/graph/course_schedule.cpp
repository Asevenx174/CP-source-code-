
#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)
using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=1e18+10;
vector < int > g[maxx];
int col[maxx],in[maxx],out[maxx],tim=0,f=0;
vector < pii > ans ;
void dfs(int p,int c)
{
    if(f==1){return ;}
    in[c]=++tim;
    col[c]=1;
    for(auto x : g[c] )
    {
        if(col[x]==1){f=1;return ;}
        if(col[x]==0)
        {
            dfs(c,x);
        }
    }
    out[c]=++tim;
    ans.push_back({out[c],c});
    col[c]=2;
}
int main()
{
   int n,m ;
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
       int u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
   }
   dfs(0,1);
   if(out[n]==0 || out[1]<out[n] ){cout << "IMPOSSIBLE" << endl; return 0 ; }
   sort(ans.begin(),ans.end(),greater<pii>());
   int idx = 0,k=0;
   for(auto p : ans )
   {
       if(idx!=0){cout << " " ;}
       idx = 1 ;
       if(p.ss==1)
       {
           k=1;
       }
       if(k==1) { cout << p.ss ; }
       if(p.ss==n){break;}
   }
   cout << endl;
   return 0 ;
}
