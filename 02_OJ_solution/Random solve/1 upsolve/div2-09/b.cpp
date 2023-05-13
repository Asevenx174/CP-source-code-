#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair < long long , long long >

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
ll kr[maxx+10],hr[maxx+10],n,idx[maxx+10],val[maxx+10] ;
ll calco(ll r)
{
   ll ans = r*(r+1) ;
   ans = ans/2LL ; 
   return ans ; 
}
ll get(ll l,ll r)
{
   ll ans = calco(r)-calco(l-1) ; 
   return ans ;  
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> kr[i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> hr[i+1] ; 
      }
      for(int i=1;i<=n;i++)
      {
         idx[i] = kr[i] ; 
         val[i] = hr[i] ; 
         for(int j=i+1;j<=n;j++)
         {
            ll r=kr[j] ;
            ll l = r-hr[j]+1 ; 
            ll sub = kr[i]-l+1 ;
            val[i] = max(val[i],sub)  ;  
         }
         //cout << i << " " << idx[i] << " " <<  val[i] << endl ;
      }
      ll ans = get(1,val[1]) ; 
      for(int i=2;i<=n;i++)
      {
         ll p = val[i-1] ; 
         ll q = val[i] ; 
         if(idx[i]-idx[i-1]<val[i])
         {
            ll r = p+idx[i]-idx[i-1] ; 
            ans+=get(p+1,r) ;
            val[i] = r ; 
         } 
         else
         {
            ans+=get(1,q) ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}