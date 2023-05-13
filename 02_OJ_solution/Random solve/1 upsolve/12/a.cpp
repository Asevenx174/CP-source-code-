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
      ll n ;
      cin >> n ; 
      string a,b ;
      cin >> a >> b ; 
      std::vector< int > p,q ;
      for(int i=1;i<n;i++)
      {
         if(a[i]!=a[i-1])
         { 
            p.push_back(i) ; 
         }
         if(b[i]!=b[i-1])
         { 
            q.push_back(i) ; 
         }
      }
      ll ans = 0 ; 
      if(p.size()!=q.size() || a[0]!=b[0] || a[n-1]!=b[n-1] )
      {
         cout << "-1" << endl ; continue ; 
      }
      for (int i = 0; i < p.size() ; ++i)
      {
         ans+=abs(p[i]-q[i]) ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}