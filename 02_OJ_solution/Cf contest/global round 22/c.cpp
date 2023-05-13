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
vector < int > g[maxx+10] ;  
bool used[maxx+10],add[maxx+10] ; 
int flag=0,f=0 ;  
void dfs(int p,int u)
{
   if(!add[u]){f++;}
   used[u] = true ; 
   for(auto v : g[u])
   {
      if(v==p){continue;}
      if(used[v]){flag=1;continue;}
      dfs(u,v) ; 
   }
}
void solve()
{
   map < pii ,int > pq ; 
   map < int , pii > ab ; 
   std::vector < pii > v ;
   set < pii > s ; 
   int n,m ;
   cin >> n >> m ; 
   for (int i = 0; i < m ; ++i)
   {
      int x,y ; 
      cin >> x >> y ; 
      s.insert({x,y}) ; 
      if(x==y){continue;}
      v.push_back({x,y}) ; 
   }
   for(int i=1;i<=n;i++)
   {
      s.insert({i,i}) ; 
   }
   int idx = 1 ; 
   for(auto x : s)
   {
      if(x.ff==x.ss){add[idx]=true;}else{add[idx]=false;}
      used[idx] = false ; 
      pq[x] = idx ;
      ab[idx] = x ; 
      idx++ ;  
   }
   for (int i = 0; i < idx+4; ++i)
   {
      g[i].clear() ;  
   }
   for(auto p : v)
   {
      int x = p.ff ; 
      int y = p.ss ; 
      pii a = {x,x} ; 
      pii b = {y,y} ; 
      int u = pq[p] ; 
      int temp = pq[a] ; 
      //cout << a.ff << " " << a.ss << " ---- " << p.ff << " " << p.ss << endl ; 
      g[u].push_back(temp) ; 
      g[temp].push_back(u) ;
      temp = pq[b] ;  
      //cout << b.ff << " " << b.ss << " ---- " << p.ff << " " << p.ss << endl ;
      g[u].push_back(temp) ; 
      g[temp].push_back(u) ; 
   }
   int ans = 0 ; 
   for(auto x : v)
   {
      int u = pq[x] ; 
      if(used[u]){continue;}
      flag = 0 ; 
      f = 0 ; 
      dfs(0,u) ;
      if(flag)
      {
         ans+=2 ; 
         ans+=(f-1) ; 
      }  
      else
      {
         ans+=f ; 
      }
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