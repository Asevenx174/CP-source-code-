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
ll n,val ; 
ll hr[maxx+10] ; 
int main()
{
   debugMode();
   cin >> n >> val ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> hr[i+1] ; 
   }
   ll l=1,r=2,ans=0 ; 
   while(r<=n)
   {
      while(r+1<=n && val>= ( 2*(hr[r+1]-hr[r])*(hr[r]-hr[l]) ) ) 
      {
         r++ ; 
      }
      ll add = (hr[r]-hr[l])*(hr[r]-hr[l])+val ; 
      ans+=add ; 
      cout << l << " " << r << endl ;
      l = r ; 
      r++ ; 
   }
   cout << ans << endl ;
   return 0 ;
}