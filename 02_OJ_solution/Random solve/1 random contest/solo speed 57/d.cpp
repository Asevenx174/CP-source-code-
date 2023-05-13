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
ll n,ar[maxx+10] ; 
ll calco(ll a,ll b)
{
   ll l = a-1 ; 
   ll r = n-b ; 
   ll len = b-a+1 ; 
   ll ans = (l+1)*(r+1)+(l+1)*(len-1)+(r+1)*(len-1) ; 
   return ans ;  
}
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll l = i ; 
      ll r = i ; 
      while(r+1<=n && ar[l]==ar[r+1])
      {
         r++ ;
      }
      ans+=calco(l,r) ;
      i = r ;  
   }
   cout << ans << endl ;
   return 0 ;
}