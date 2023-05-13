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
const ll maxx = 2e5+10,mod=1e9,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll fastpow(ll n,ll k)
{   ll ans = 1 ;
    while(k>0)
    {   if(k&1)
        { ans = (ans*n)%mod; }
        k = k >> 1 ;
        n = (n*n)%mod ;
    }
    return ans ;
}
ll k ; 
ll calco(ll l)
{
   if(l==0){return 1;}
   if(l==1){return k;}
   ll ans = fastpow(k-1,l-1) ;
   ans = (ans*k)%mod ; 
   return ans ;  
}
int main()
{
   debugMode();
   ll test,pos=1 ;
   cin >> test ;
   while(test--)
   {
      std::vector < pii > v ;
      ll m,n,b ;
      cin >> m >> n >> k >> b ; 
      set < int > s ; 
      map < int ,int > pq ; 
      for (int i = 0; i < b ; ++i)
      {
         int x,y ;
         cin >> x >> y ; 
         v.push_back({x,y}) ; 
         s.insert(x) ; 
      }
      int idx = 0 ; 
      for(auto x : s )
      {
         pq[x] = ++idx ; 
      }
      std::vector < int > g[b+10] ;
      for(auto p : v)
      {
         int x = pq[p.ff] ; 
         g[x].push_back(p.ss) ;  
      }
      ll ans = calco(n) ; 
      ans = fastpow(ans,m-idx) ; 
      for(int i=1;i<=idx;i++)
      {
         g[i].push_back(0) ; 
         g[i].push_back(n+1) ;  
         sort(g[i].begin(),g[i].end()) ; 
         for(int j=1;j<g[i].size();j++)
         {
            int x = g[i][j-1] ; 
            int y = g[i][j] ; 
            cout << x << " " << y << endl ;
            ll l = y-x-1 ; 
            ans = (ans*calco(l))%mod ; 
         }
      }
      printf("Case %I64d: %I64d\n",pos++,ans) ; 
   }
   return 0 ;
}