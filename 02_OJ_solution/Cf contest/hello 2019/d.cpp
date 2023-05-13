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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< ll > v ;
void calco(ll n)
{
   ll last ; 
   for(ll i=1;i*i<=n;i++)
   {
      if(n%i==zz)
      {
         ll j = n/i ;
         v.push_back(i) ;
         if(i!=j)
         {
            v.push_back(j) ;
         }
      }
   }
}
int main()
{
   debugMode();
   ll n,k ;
   cin >> n >> k ;
   calco(n) ; 
   ll ans = -1 ; 
   sort(v.begin(),v.end()) ; 
   if(v.size()>=k)
   {
      for(auto x : v )
      {
         k-- ; 
         if(k==0){ans=x;break;}
      }
   }
   cout << ans << endl ;
   return 0 ;
}