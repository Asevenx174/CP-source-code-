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
std::vector < int > g[maxx+10] ;
int n,m,val[maxx+10],sub[maxx+10],par[maxx+10],ch[maxx+10],ar[maxx+10] ;
ll im[maxx+10] ; 
struct com {
  bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
    if (p1.first == p2.first) {
      return p1.second < p2.second;  // If first elements are equal, sort by second element
    }
    return p1.first > p2.first;  // Sort by first element
  }
};

priority_queue < pii , vector < pii > , com > pq[maxx+5] ; 
bool used[maxx+10] ; 
void dfs(int p,int u)
{
   used[u] = true ; 
   int sum = 1 ;
   ll add = val[u] ;  
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      par[v] = u ;  
      dfs(u,v) ;
      sum+=sub[v] ; 
      add+=im[v] ; 
      pq[u].push({sub[v],v}) ; 
   }
   sub[u] = sum ; 
   im[u] = add ; 
}
void dlt(int f)
{
   while(!pq[f].empty() && par[pq[f].top().ss]!=f)
   {
      pq[f].pop() ; 
   }
   if(pq[f].empty()){return;}
   pii p = pq[f].top() ; pq[f].pop() ; 
   int c = p.ss ; 
   int q = par[f] ; 
   par[c] = q ; 
   par[f] = c ;  

   sub[f]-=sub[c] ; 
   sub[c]+=sub[f] ; 
   //sub[q]+=sub[c] ; 

   im[f]-=im[c] ; 
   im[c]+=im[f] ; 
   //im[q]+=im[c] ;
   pq[q].push({sub[c],c}) ;
   pq[c].push({sub[f],f}) ; 
}

void solve()
{
   cin >> n >> m ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> val[i+1] ; 
   }
   for (int i = 0; i+1 < n ; ++i)
   {
      int u,v ;
      cin >> u >> v ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ; 
   }
   dfs(0,1) ; 
   for (int i = 0; i < m ; ++i)
   {
      int t ;
      cin >> t ; 
      int x ; 
      if(t==1)
      {
         cin >> x ; 
        // cout << x << endl ;
         cout << im[x] << endl ;
      }
      else
      {
         cin >> x ; 
         dlt(x) ; 
      }
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