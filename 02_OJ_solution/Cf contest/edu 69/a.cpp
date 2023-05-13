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
std::vector < int > v ;
int b1,b2,n ;
bool valid(int k)
{
   if(min(b1,b2)<k+1){return false;}
   int have = n-2 ; 
   int need = k ; 
   if(need>have){return false;}
   return true ; 
} 
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
         int x ;
         cin >> x ;
         v.push_back(x) ; 
      }
      sort(v.begin(),v.end(),greater<int>()) ; 
      auto it = v.begin() ; 
      b1 = *it ;
      it++ ; 
      b2 = *it ; 
      int l=0,r=n,ans=0 ; 
      while(l<=r)
      {
         int m = (l+r)/2 ;
         if(valid(m))
         {
            ans = m ; 
            l = m+1 ; 
         }
         else
         {
            r = m-1 ; 
         }
      }
      cout << ans << endl ; 
   }
   return 0 ;
}