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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool used[maxx+10] ; 
int parent[maxx+5],sized[maxx+5],n,m ;
vector < pair < string , string > > v ; 
set < string > s ; 
map < string ,int > si ; 
map < int ,string > is ; 
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
void solve()
{  
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      string a,b ;
      cin >> a >> b ; 
      v.push_back({a,b}) ; 
      s.insert(a) ; 
      s.insert(b) ; 
   }
   int idx = 1 ; 
   for(auto x : s)
   {
      make_set(idx) ; 
      si[x] = idx ; 
      is[idx] = x ; 
      idx++ ; 
   }
   for(auto p : v)
   {
      int a = si[p.ff] ; 
      int b = si[p.ss] ; 
      union_sets(a,b) ; 
      int gp = find_set(a) ; 
      cout << sized[gp] << endl ; 
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