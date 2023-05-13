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
int ar[maxx+10],n,m ; 
std::vector < pii > v[maxx+10];
ll calco(ll s,ll t)
{
   ll d = t-s ; 
   ll ans = d*s ; 
   ll add = s*(s-qq) ; 
   add = add/tt ; 
   ans+=add ; 
   return ans ;  
}
void solve()
{
   map < int ,int > pq ; 
   cin >> n >> m ; 
   for (int i = 0; i < n+4; ++i)
   {
      v[i].clear() ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      v[i+1].push_back({0,ar[i+1]}) ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      int idx,val ; 
      cin >> idx >> val ; 
      if(ar[idx]==val){continue;}
      v[idx].push_back({i+1,val}) ;
      ar[idx] = val ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      v[i+1].push_back({m+1,mod}) ; 
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<v[i].size();j++)
      {
         int f = v[i][j].ff-v[i][j-1].ff ; 
         int val = v[i][j-1].ss ; 
         //cout << i << " " << val << " " << f << endl ;
         pq[val]+=f ; 
      }
   }
   ll ans = 0 ; 
   for(auto p : pq)
   {
      ll add = calco(p.ss,m+qq) ; 
      ans+=add ; 
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