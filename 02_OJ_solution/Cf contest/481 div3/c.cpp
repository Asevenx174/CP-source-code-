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
ll ar[maxx+10],pre[maxx+10],qr[maxx+10] ; 
int main()
{
   debugMode();
   std::vector < ll > v ;
   ll n,m ; 
   cin >> n >> m ;
   ll sum = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      sum+=ar[i+1] ; 
      v.push_back(sum) ; 
      pre[i+1] = sum ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      cin >> qr[i+1] ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      ll x = qr[i+1] ; 
      auto it = lower_bound(v.begin(),v.end(),x) ; 
      ll idx = it-v.begin()+1 ; 
      x = x-pre[idx-1] ; 
      cout << idx << " " << x << endl ;
   }
   return 0 ;
}