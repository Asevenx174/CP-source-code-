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
int lvl[maxx+10],n,far,pq=0,best ; 
std::vector < int > a[maxx+10],b[maxx+10],g[maxx+10] ;
bool used[maxx+10] ; 

void bfs(int x,int idx)
{
   best = 0  ; 
   memset(used,false,sizeof(used)) ; 
   queue < int > q ; 
   q.push(x) ; 
   used[x] = true ; 
   lvl[x] = 0 ; 
   while(!q.empty())
   {
      int u = q.front() ; q.pop() ; 
      for(auto v : g[u])
      {
         if(used[v]){continue;}
         used[v] = true ; 
         q.push(v) ; 
         lvl[v] = lvl[u]+1 ; 
         if(idx==3)
         {
            if(lvl[v]>best)
            {
               best = lvl[v] ; 
               far = v ;  
               pq = max(pq,best) ; 
            }
         }
         else if(idx==1)
         {
            a[ lvl[v] ].push_back(v) ; 
         }
         else
         {
            b[ lvl[v] ].push_back(v) ;
         }
      }
   }
}
void solve()
{
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      make_set(i+1) ; 
   }
   for (int i = 0; i+1 < n ; ++i)
   {
      int u,v ;
      cin >> u >> v ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ; 
   }
   bfs(1,3) ; 
   int l = far ; 
   bfs(far,3) ;
   int r = far ; 
   bfs(l,1) ; 
   bfs(r,2) ; 
   vector < int > ans ;  
   int res = n ; 
   for(int i=n;i>0;i--)
   {
      if(i>pq)
      {
         ans.push_back(res) ; 
      }
      else
      {
         for(auto x : a[i])
         {
            if(find_set(x)!=find_set(l)){res--;}
            union_sets(x,l) ; 
         }
         for(auto x : b[i])
         {
            if(find_set(x)!=find_set(r)){res--;}
            union_sets(x,r) ; 
         }
         ans.push_back(res) ; 
      }
   }
   reverse(ans.begin(),ans.end()) ; 
   for (int i = 0; i < ans.size() ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ans[i] ; 
   }
   cout << endl ;
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