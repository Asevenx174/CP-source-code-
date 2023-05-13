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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

set<int> g[maxx+10]; // adjacency list (note that this is stored in set, not vector)
int sub[maxx+10], dad[maxx+10];

int dfs(int u, int p)
{
  sub[u] = 1;
  for(auto v : g[u])
  { 
    if(v != p) 
    {
      sub[u] += dfs(v, u);
    }
  }
  return sub[u];
}
int centroid(int u, int p, int n)
{
  for(auto v : g[u]) 
  {
    if(v != p)
    {
      if(sub[v] > n / 2) { return centroid(v, u, n); } 
    }
  }
  return u;
}
void build(int u, int p)
{
  int n = dfs(u, p);
  int c = centroid(u, p, n);
  if(p == -1) p = c;
  dad[c] = p;

  vector<int> temp(g[c].begin(),g[c].end());
  for(auto v : temp) 
  {
    g[c].erase(v); g[v].erase(c);
    build(v, c);
  }
}
void solve()
{

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