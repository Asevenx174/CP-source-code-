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
ll n,k,ar[maxx+10],pre[maxx+10] ; 
ll calco(ll idx)
{
   ll ans = 0,mul=1 ; 
   while(idx<=n)
   {
      ll x = ar[idx] ;
      for (int i = 0; i < mul ; ++i)
      {
         x = x/2LL ; 
         if(x==0){break;} 
      }
      //cout << idx << " " << x << endl ;
      ans+=x ; 
      idx++ ;  
      if(x==0){break;}
      mul++ ; 
   }
   return ans ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector< int > v ;
      cin >> n >> k ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         v.push_back(x) ; 
      }
      //sort(v.begin(),v.end(),greater<int>()) ; 
      int idx = 1 ; 
      ll sum = 0 ; 
      for(auto x : v )
      {
         ar[idx] = x ;
         sum+=x ; 
         pre[idx] = sum ; 
         idx++ ;  
      }
      ll ans = 0 ; 
      for(ll g=0;g<=n;g++)
      {
         ll temp = -g*k+pre[g] ; 
         ll add =calco(g+1);
         temp+=add ; 
         //cout << g << " " << add << endl ;
         ans = max(ans,temp) ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}