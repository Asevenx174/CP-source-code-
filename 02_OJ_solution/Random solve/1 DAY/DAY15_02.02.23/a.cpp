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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,sr[maxx+10],f=0,co=0,used[maxx+10],idx=1 ; 
std::vector < ll > g[maxx+10] ;
bool in[maxx+10] ; 

set < int > st ; 
ll cy[maxx+10] ; 
void dfs(int p,int u)
{
   co++ ; 
   cy[co] = u ; 
   used[u] = idx ; 
   for(auto v:g[u])
   {
      if(used[v]==0)
      {
         dfs(u,v) ; continue ;  
      }
      sr[v]++ ; 
      if(used[v]==idx)
      {
         f = 1 ; 
      }
      else
      {
         if(in[v])
         {
            f = 1 ; 
         }
      }
   }
}
void solve()
{
   idx = 1 ; 
   cin >> n ; 
   for (int i = 0; i < n+4 ; ++i)
   {
      sr[i] = 1 ; 
      used[i] = 0 ; 
      g[i].clear() ; 
      in[i] = false ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      ll a = i+1 ; 
      ll b = a+ar[a] ; 
      if(b<0 || b>n){continue;}
      g[a].push_back(b) ; 
   }
   ll c = 0 ; 
   for(int i=1;i<=n;i++)
   {
      if(used[i]!=0){continue;} ; 
      f = 0 ; 
      co = 0 ; 
      dfs(0,i) ; 
      if(f)
      {

         for (int i = 0; i < co ; ++i)
         {
            int x = cy[i+1] ; 
            in[x] = true ; 
            ///cout << x << " ->" << endl ;
         }
      }
      idx++ ; 
   }
   c = n-c ; 

  /* cout << c << endl ;
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll temp = 0 ; 
      //cout << i << " " << sr[i] << endl ; 
      if(in[i])
      {
         temp=(c+n+qq) ; 
      }
      else
      {
         temp=(c+n+qq-sr[i]) ; 
      }
      cout << i << " " << temp << endl ;
   }
   cout << ans << endl ; */
   
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll temp = 0 ; 
      if(used[i]!=1)
      {
         //cout << i << " ->> " << endl ;
         temp = tt*n+qq ; 
      }
      else
      {
         if(in[i])
         {
           temp=(c+n+qq) ; 
         }
         else
         {
           // cout << i << endl ;
           temp=(c+n+qq-sr[i]) ; 
         }
      }
      cout << i << " " << temp << endl ; 
      ans+=temp ;
   }
   cout << ans << endl ;
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