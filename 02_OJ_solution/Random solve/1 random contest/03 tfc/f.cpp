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
const ll maxx = 4e6+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int lr[maxx+10] ; 
int rr[maxx+10] ; 
std::vector < pii > v[maxx+5] ;
void solve()
{
   map < int ,int > pq,qp ; 
   set < int > s,last ; 
   int n,m ;
   cin >> n >> m ; 
   vector < int > dp(n+5,mod) ; 
   int best = 0 ; 
   for(int i=1;i<=m;i++)
   {
      int l,r ;
      cin >> l >> r ; 
      r = r+l-1 ; 
      lr[i] = l ; 
      rr[i] = r ;
      s.insert(l) ; 
      s.insert(r) ; 
      last.insert(r) ; 
      v[r].push_back({l,i}) ; 
      best = max(best,r) ; 
   }
   int idx = 0 ; 
   for( auto x : s )
   {
      idx++ ; 
      pq[x] = idx;  
      qp[idx] = x ; 
   }
   for(auto r : last )
   {
      for(auto p : v[r])
      {
         int l = p.ff ; 
         cout << l << " " << r << endl ; 
         idx = p.ss ; 
         int pos = pq[l] ; 
         pos = qp[pos-1] ;  
         cout << pos << endl ;
         dp[r] = min(dp[r],dp[pos]+1) ;  
      }
   }
   cout << dp[best] << endl ;
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