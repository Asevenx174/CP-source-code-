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
ll n ;
std::vector < ll > v ;
ll l,r ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      v.clear() ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         v.push_back(x) ; 
      }
      sort(v.begin(),v.end()) ; 
      l = v[0] ; 
      r = (v[0]*2LL)-1LL ; 
      ll ans = 0LL ; 
      for (int i = 1 ; i < n ; ++i)
      {
         ll y = v[i] ; 
         if(y<=r){continue;}
         ll a=1,b=mod ; 
         ll add = 0 ; 
         while(a<=b)
         {
            ll m = (a+b)/2ll ; 
            if( (y-r*m) > r )
            {
               a = m+1 ; 
            }
            else
            {
               add = m ; 
               b = m-1 ; 
            }
         }
         ans+=add ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}