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
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      map < int , bool > used ; 
      ll n ;
      cin >> n ;
      std::vector < ll > d ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         d.push_back(x) ; 
         used[x] = true ; 
      } 
      sort(d.begin(),d.end()) ; 
      auto it = d.begin() ; 
      auto lt = d.rbegin() ; 
      ll a = *it ;
      ll b = *lt ; 
      ll x = a*b ; 
      for(ll i=2;i*i<=x;i++)
      {
         if((x%i)==zz)
         {
            ll j = x/i ; 
            if(!used[i] || !used[j]){x=-1;break;}
         }
      }
      for(auto y : d )
      {
         if( (x%y)!=0 ){x=-1;}
      }
      cout << x << endl ;
   }
   return 0 ;
}