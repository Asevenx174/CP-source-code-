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
int n,k,c,sr[maxx+10],up[maxx+10] ; 
std::vector < int > g[maxx+10] ;
vector < pii > sub[maxx+10] ; 
bool used[maxx+10] ; 
void getsub(int u)
{
   used[u] = true ; 
   int l = 0 ; 
   sr[u] = 0 ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      l = 1 ; 
      getsub(v) ; 
      sub[u].push_back({sr[v],v}) ;
      sr[u] = max(sr[u],sr[v]) ; 
   }
   sr[u]+=l ; 
   //cout << u << " " << sr[u] << endl ;
   sort(sub[u].begin(),sub[u].end(),greater<pii>()) ; 
}
void getup(int p,int u)
{
   used[u] = true ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      int val = up[p]+1 ;
      int temp = min(2,(int)sub[u].size()) ;
      auto it = sub[u].begin() ;
      pii pp = *it ; 
      cout << u << " " << pp.ff << " " << pp.ss << endl ;
      while(temp--)
      {
         pp = *it ; 
         if(pp.ss!=v)
         {
            //cout << u << " " <<  v << " " << temp.ff << endl ;
            val = max(pp.ff+1,val) ; break ;
         }
         it++ ; 
      }  
      up[v] = val ; 
      cout << v << " ? " << val << endl ;
      getup(u,v) ; 
   }
}
void solve()
{
   cin >> n >> k >> c ; 
   for (int i = 1 ; i < n ; ++i)
   {
      int u,v ;
      cin >> u >> v ; 
      g[u].push_back(v) ; 
      g[v].push_back(u) ; 
   }
   memset(used,false,sizeof(used)) ;
   getsub(1) ;  
   memset(used,false,sizeof(used)) ;
   getup(0,1) ;
   /*for(int i=1;i<=n;i++)
   {
      cout << i << " " << sr[i] << endl ;
   }*/
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