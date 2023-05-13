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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

ll ar[maxx+10],lr[maxx+10],rr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ordered_set sett ;  
      ll n ; 
      cin >> n ;
      ll best = mod ; 
      for(int i=1;i<=n;i++)
      {
         ll x ;
         cin >> x ; 
         ar[i] = x ; 
         best = min(best,x) ; 
         lr[i] = best ; 
      }
      if(n==1)
      {
         cout << "1" << endl ; continue ; 
      }
      best = mod ; 
      for(int i=n;i>0;i--)
      {
         best = min(best,ar[i]) ; 
         rr[i] = best ; 
      }
      for(int i=1;i<n;i++)
      {
         if(i!=lr[1] && i!=rr[n])
         {
            sett.insert(i) ; 
         }
      }
      std::vector< int > v ;
      for(int i=2;i<n;i++)
      {
         ll x = max(lr[i],rr[i]) ; 
         if(x>0){v.push_back(x);}
      }
      sort(v.begin(),v.end(),greater<int>()) ;
      ll ans = 1 ; 
      for(auto x : v )
      {
         auto it = sett.find(x) ;
         if(it!=sett.end())
         {
            sett.erase(it) ; 
         } 
         else
         {
            ll f = sett.size()-sett.order_of_key(x+1) ;
            if(f==0){ans=1;break;}
            ans = (ans*f)%mod ;  
            sett.erase(sett.rbegin());
         }
      }
      cout << ans << endl ; 
   }
   return 0 ;
}