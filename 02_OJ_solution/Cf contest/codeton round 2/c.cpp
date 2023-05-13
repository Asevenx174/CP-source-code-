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
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector < ll > v ,k ;
      ll n,m ;
      cin >> n >> m ; 
      ll l = mod , r = 0 ; 
      for (int i = 0; i < m ; ++i)
      {
         ll x ;
         cin >> x ;
         v.push_back(x) ; 
         l = min(l,x) ;
         r = max(r,x) ; 
      }
      if(m==1)
      {
         cout << "2" << endl ; continue ; 
      } 
      sort(v.begin(),v.end()) ; 
      for (int i = 1 ; i < v.size() ; ++i)
      {
         ll d = v[i]-v[i-1]-1 ; 
         k.push_back(d) ; 
      }
      k.push_back(n+l-r-1) ; 
      sort(k.begin(),k.end(),greater<ll>()) ; 
      ll t = 0,ans=0 ; 
      for(auto x : k )
      {  
         ll y = x-(t*2) ; 
         if(y>2)
         {
            t+=2 ; 
            y-- ; 
            ans+=y ; 
         }
         else if(y==2)
         {
            t++ ; 
            ans++ ;
         }
         else if (y==1)
         {
            ans++ ;
            t++ ;   
         }
         else{break;}
      }
      ans = n-ans ; 
      cout << ans << endl ;
   }
   return 0 ;
}