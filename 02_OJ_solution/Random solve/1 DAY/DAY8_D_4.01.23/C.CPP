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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=320,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],pr[maxx+10],n,q ; 
ll st[maxx+10][mod+5],dep[maxx+10],fr[maxx+10],num[maxx+10] ; 
std::vector < int > g[maxx+10] ;
void dfs(ll u,ll d)
{
   fr[d]++ ;
   num[u] = fr[d] ; 
   dep[u] = d ; 
   for(auto v : g[u])
   {
      dfs(v,d+1) ; 
   } 
}
ll calco(ll x,ll y)
{
   if(x==zz)
   {
      return zz ; 
   }
   ll d = dep[x] ; 
   ll f = fr[d] ; 
   if(f<=mod && st[x][num[y]]>zz)
   {
      return st[x][num[y]] ; 
   }
   ll ans = calco(pr[x],pr[y])+ar[x]*ar[y] ;
   if(f<=mod)
   {
      st[x][num[y]] = ans ; 
   }  
   return ans ; 
}
void solve()
{
   cin >> n >> q ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i=2 ; i<=n ; ++i)
   {
      cin >> pr[i] ; 
      g[ pr[i] ].push_back(i) ; 
   }
   dfs(1,0) ; 
   for (int i = 0; i < q ; ++i)
   {
      ll x,y ;
      cin >> x >> y ; 
      ll ans = calco(x,y) ; 
      cout << ans << endl ;
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}