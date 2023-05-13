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
const ll maxx = 205 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll pr[maxx+10],f=0 ; 
std::vector< int > g[maxx+10] ;
bool used[maxx+10] ; 
void dfs(int u)
{
   used[u] = true ; 
   f++ ; 
   for(auto v : g[u] )
   {
      if(!used[v])
      {
         dfs(v) ; 
      }
   }
}
ll lcm(ll a,ll b)
{
   ll gcd = __gcd(a,b) ; 
   ll ans = (a*b)/gcd ; 
   return ans ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n ;
      cin >> n ;
      for (int i = 0; i < maxx ; ++i)
      {
         g[i].clear() ; 
      }
      string s ;
      cin >> s ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> pr[i+1] ; 
         g[i+1].push_back( pr[i+1] ) ; 
         g[ pr[i+1] ].push_back( i+1 ) ; 
      }
      ms(used,false) ; 
      ll ans = 1 ; 
      for(int i=1;i<=n;i++)
      {
         if(!used[i])
         {
            f = 0 ; 
            dfs(i) ; 
            ans = lcm(ans,f) ;
         }
      }
      cout << ans  << endl ;
   }
   return 0 ;
}