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
typedef unsigned long long ll ;
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=1e18+10;
vector < ll > g[maxx];
ll in[maxx],out[maxx],up[maxx],down[maxx],sub[maxx],ex[maxx],n;
void dfs(int p,int c)
{
    ll ans = 1 , k = in[c];
    for(auto x : g[c] )
    {
        if(x!=p)
        {
            in[x]=in[c]+1;
            dfs(c,x);
            ans+=sub[x];
            k+=out[x];
        }
    }
    sub[c]=ans;
    out[c]=k;
    down[c]=out[c]-(sub[c]*in[c]);
}
void dfs22(int p,int c)
{
    ll ans = 0 ;
    for(auto x : g[c])
    {
        if(x!=p)
        {
            ans+=(down[x]+sub[x]);
        }
    }
    for(auto x : g[c])
    {
        if(x!=p)
        {
            up[x]=up[c]+(n-sub[x])+(ans-(down[x]+sub[x]));
            dfs22(c,x);
        }
    }
}
int main()
{
   cin >> n ;
   for(int i=1;i<n;i++)
   {
       ll u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   in[1]=0;
   dfs(0,1);

   up[1]=0;
   dfs22(0,1);

   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ;}
       ll kk = up[i]+down[i] ;
       cout << kk ;
   }
   cout << endl;
   return 0 ;
}
