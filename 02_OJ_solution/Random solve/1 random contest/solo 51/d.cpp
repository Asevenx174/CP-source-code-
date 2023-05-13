#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int parent[maxx+5],sized[maxx+5];
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
int main()
{
   debugMode();
   int n,m ;
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      make_set(i+1) ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      int u,v ;
      cin >> u >> v ; 
      union_sets(u,v) ; 
   }
   set < int > s ; 
   for (int i = 0; i < n ; ++i)
   {
      int x = find_set(i+1) ; 
      //cout << i+1 << " " << x << endl ; 
      s.insert(x) ; 
   }
   cout << ((int)s.size()-1) << endl ; 
   return 0 ;
}