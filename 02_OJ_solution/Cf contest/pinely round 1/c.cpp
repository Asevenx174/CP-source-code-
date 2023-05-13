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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10][maxx+10],n ; 
vector < int > g[maxx+10],ans[maxx+10],temp ; 
int used[maxx+10] ; 
set < int > str[maxx+10] ; 
int par = 0 ; 
void dfs(int u)
{
   used[u] = par ; 
   for(auto v : g[u] )
   {
      if(used[v]==par){continue;}
      if(used[v]==0)
      {
         dfs(v) ;
      } 
      for(auto x : str[v])
      {
         str[u].insert(x) ; 
      }
   }
   str[u].insert(u) ; 
}
void solve()
{
   for (int i = 0; i < maxx ; ++i)
   {
      g[i].clear() ; 
      used[i] = 0 ; 
      str[i].clear() ; 
   }
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ; 
      for (int j = 0; j < n ; ++j )
      {
         int x = s[j]=='1' ? 1 : 0 ; 
         ar[i+1][j+1] = x ; 
         if(x==1)
         {
            g[j+1].push_back(i+1) ; 
         }
      }
   }
   for(int i=1;i<=n;i++)
   {
      if(used[i]==0)
      {
         par = i ; 
         dfs(i) ; 
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      cout << str[i+1].size() ; 
      for(auto x : str[i+1])
      {
         cout << " " << x ; 
      }
      cout << endl ;
   }
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