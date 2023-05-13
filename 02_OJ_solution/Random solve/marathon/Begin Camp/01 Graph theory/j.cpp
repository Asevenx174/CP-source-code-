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
const ll maxx = 1000+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool used[maxx+10] ; 
vector < pii > ed ;   
std::vector < int > g[maxx+10],k ;
int parent[maxx+5],sized[maxx+5],n ;
void make_set(int v)
{
    parent[v] = v;
    sized[v]=1;
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sized[a] < sized[b])
            swap(a, b);
        parent[b] = a;
        sized[a] += sized[b];
    }
}
bool vis[maxx+10][maxx+10] ; 
void dfs(int p,int u)
{
   used[u] = true ; 
   for(auto v : g[u])
   {
      if(p==v){continue;}
      if(used[v])
      {
         if(vis[v][u]){ed.push_back({u,v});} 
         vis[u][v] = true ; 
         continue ; 
      }
      dfs(u,v) ; 
   }
}
void solve()
{
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      make_set(i+1) ; 
   }
   for (int i = 1 ; i < n ; ++i)
   {
      int u,v ; 
      cin >> u >> v ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ; 
      union_sets(u,v) ; 
   }
   set < int > h ; 
   for (int i = 0; i < n ; ++i)
   {
      h.insert(find_set(i+1)) ; 
      if(!used[i+1])
      {
         dfs(0,i+1);
      } 
   }
   for(auto x : h)
   { 
      k.push_back(x) ; 
   }
   int idx = 1 ; 
   cout << ed.size() << endl ;
   for(auto p : ed)
   {
      cout << p.ff << " " << p.ss << " " << k[idx-1] << " " << k[idx] << endl ; 
      idx++ ; 
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