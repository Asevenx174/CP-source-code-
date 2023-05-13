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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int tr[maxx+10],xr[maxx+10],yr[maxx+10],co=0 ;
std::vector< int > g[maxx+10] ; 
bool used[maxx+10] ; 
void dfs(int u)
{
   co++ ; 
   used[u] = true ;
   for(auto v : g[u] )
   {
      if(!used[v])
      {
         dfs(v) ; 
      }
   }
}
int main()
{
   debugMode();
   int r,n ;
   cin >> r >> n ; 
   for(int i=1;i<=n;i++)
   {
      cin >> tr[i] >> xr[i] >> yr[i] ; 
   }
   for(int i=2;i<=n;i++)
   {
      int lim = tr[i]-tr[i-1] ; 
      int cost = abs(xr[i]-xr[i-1])+abs(yr[i]-yr[i-1]) ; 
      if(cost<=lim)
      {
         g[i].push_back(i-1) ; 
         g[i-1].push_back(i) ; 
      }
   }
   int ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
       if(!used[i])
       {
         int cost = abs(xr[i]-1)+abs(yr[i]-1) ; 
         if(cost<=tr[i])
         {
            co = 0 ; 
            dfs(i) ; 
            ans = max(ans,co) ; 
         }
       }
   }
   cout << ans << endl ;
   return 0 ;
}