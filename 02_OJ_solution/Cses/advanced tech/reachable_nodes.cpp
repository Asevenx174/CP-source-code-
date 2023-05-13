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
const ll maxx = 5e4+10,mod=1e9+7,imax=1e18+10;
bitset < maxx > dp[maxx];
vector < int > g[maxx];
int out[maxx];
int main()
{
   int n,m ;
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
       int u,v;
       cin >> u >> v ;
       g[v].push_back(u) ;
       out[u]++;
   }
   queue < int > q ;
   for(int i=1;i<=n;i++)
   {
       if(out[i]==0)
       {
           q.push(i);
           dp[i].set(i);
       }
   }
   while(!q.empty())
   {
       int u = q.front() ;
       q.pop() ;
       for(auto v : g[u])
       {
           dp[v] = dp[v]|dp[u] ;
           out[v]-- ;
           if(out[v]==0)
           {
               q.push(v);
               dp[v].set(v);
           }
       }
   }
   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ;}
       cout << dp[i].count() ;
   }
   return 0 ;
}
