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
const ll maxx = 110 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n ; 
int main()
{
   debugMode();
   cin >> n ; 
   std::vector< ll > a,b ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      if(x>0)
      {
         a.push_back(x) ; 
      }
      else if(x<0)
      {
         b.push_back(-x) ; 
      }
   }
   sort(a.begin(),a.end()) ; 
   sort(b.begin(),b.end()) ; 
   int need = ((n-1)/2) + 1 ; 
   int ans = 0 ; 
   if(a.size()>=need)
   {
      auto it = a.begin() ; 
      ans = *it ; 
   }
   else if(b.size()>=need)
   {  
      auto it = b.begin() ; 
      ans = *it ;
      ans = -ans ;  
   }
   cout << ans << endl ;
   return 0 ;
}