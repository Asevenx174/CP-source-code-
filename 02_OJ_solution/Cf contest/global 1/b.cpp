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
ll br[maxx+10] ; 
int main()
{
   debugMode();
   ll n,m,k ; 
   cin >> n >> m >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> br[i+1] ; 
   }
   std::vector < ll > d ;
   for(int i=2;i<=n;i++)
   {
      d.push_back(br[i]-br[i-1]-1) ; 
   }
   sort(d.begin(),d.end()) ; 
   ll temp = max(0LL,n-k) ; 
   ll ans = n ;  
   auto it = d.begin() ; 
   while(temp--){ans+=(*it);it++;}
   cout << ans << endl ;
   return 0 ;
}