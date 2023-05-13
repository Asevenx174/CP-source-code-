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
struct CentroidDecomposition 
{
   set < int > tree[] // it's not vector<vector<int>>!
   vector<int> dad;
   vector<int> sub;

   CentroidDecomposition(vector<set<int>> &tree) : tree(tree) 
   {
      int n = tree.size();
      dad.resize(n);
      sub.resize(n);
      build(0, -1);
   }

   void build(int u, int p)
   {
      int n = dfs(u, p); // find the size of each subtree
      int centroid = dfs(u, p, n); // find the centroid
      if (p == -1) { p = centroid ; } // dad of root is the root itself
      dad[centroid] = p ; // p is the dad of the centroid of the centroid tree

      // for each tree resulting from the removal of the centroid
      for (auto v : tree[centroid])
      {
         tree[centroid].erase(v), // remove the edge to disconnect
         tree[v].erase(centroid), // the component from the tree
         build(v, centroid);
      }
   }

   int dfs(int u, int p)
   {
      sub[u] = 1;

      for (auto v : tree[u])
      {
         if (v != p) sub[u] += dfs(v, u);
      }

      return sub[u];
   }

   int dfs(int u, int p, int n)
   {
      for (auto v : tree[u])
      {
         if (v != p and sub[v] > n/2) return dfs(v, u, n);
      }
      return u;
   }

   int operator[](int i)
   {
      return dad[i];
   }
};


void solve()
{
   vector<set<int>> tree;
   int n,m ; 
   cin >> n >> m ; 
   tree.resize(n+5) ; 
   for (int i = 0; i+1 < n ; ++i)
   {
      int u,v ;
      cin >> u >> v ; 
      u-- ; 
      v-- ; 
      tree[u].insert(v) ;
      tree[v].insert(u) ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      int a,b ;
      cin >> a >> b ; 
   }
   cout << "yes" << endl ;
   CentroidDecomposition cd(tree) ; 
   cout << "yes" << endl ;
   //cout << cd[1] << endl ; 
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