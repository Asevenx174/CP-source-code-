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
const ll maxx = 2e5+10 ,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector < int > g[maxx+10],v[maxx+10] ;
vector < char > l[maxx+10],r[maxx+10] ; 
int idx,used[maxx+10] ; 
void dfs(int x)
{
   used[x] = true ; 
   for(auto y : g[x])
   {
      if(used[y]==idx){continue;}
      v[idx].push_back(y) ; 
      dfs(y) ; 
   }
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
bool valid(int i)
{
   sort(l[i].begin(),l[i].end()) ;
   sort(r[i].begin(),r[i].end()) ;
   if(l[i].size()!=r[i].size()){return false;}
   for (int j = 0; j < l[i].size() ; ++j)
   {
       if(l[i][j]!=r[i][j]){return false ; }
   } 
   return true ; 
}
void solve()
{
   int n,k ;
   cin >> n >> k ; 
   for (int i = 0; i <=n+4 ; ++i)
   {
      used[i] = 0 ; 
      //v[i].clear() ; 
      g[i].clear() ; 
      l[i].clear() ; 
      r[i].clear() ; 
      make_set(i) ; 
   }
   string s,t ;
   cin >> s >> t ; 
   string aa = s ; 
   string bb = t ; 
   sort(aa.begin(),aa.end()) ;
   sort(bb.begin(),bb.end()) ;
   if(aa!=bb)
   {
      cout << "NO" << endl ; return ; 
   } 
   for(int i=1;i<=n;i++)
   {
      int j = i+k ; 
      if(j<=n)
      {
         //g[i].push_back(j) ; g[j].push_back(i) ; 
         union_sets(i,j) ; 
      }
      j = i+k+1 ; 
      if(j<=n)
      {
         //g[i].push_back(j) ; g[j].push_back(i) ;
         union_sets(i,j) ;
      }
   }
   for(int i=1;i<=n;i++)
   {
      //idx = i ; 
      //dfs(i) ; 
      int p = find_set(i) ;
      l[p].push_back(s[i-1]) ;
      r[p].push_back(t[i-1]) ; 
   }
   int f = 1 ; 
   for(int i=1;i<=n;i++)
   {
      if(!valid(i)){f=0;}
   }
   if(f)
   {
      cout << "YES" << endl ;
   }
   else
   {
      cout << "NO" << endl ;
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