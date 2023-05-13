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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,k,c,sub[maxx+10] ; 
std::vector < int > g[maxx+10] ;
bool used[maxx+10] ; 
void gensub(ll u)
{
   used[u] = true ; 
   ll sum=0,f=0 ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      f=1 ;
      gensub(v) ;
      sum=max(sum,sub[v]) ;  
   }
   sub[u] = sum+f ; 
   cout << u << " " << sub[u] << endl ;
}
void solve()
{
   memset(used,false,sizeof(used)) ; 
   cin >> n >> k >> c ; 
   for (int i = 0; i+1 < n ; ++i)
   {
      ll u,v ;
      cin >> u >> v ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ; 
   }
   gensub(1);
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}