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
ll ar[maxx+10],n ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll f = 0 ; 
      ll r = mod ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         if(ar[i+1]==0 && f==1 && r==mod)
         {
            r = i+1 ; 
         }
         if(ar[i+1]!=0){f=1;}
      }
      ll l=1,ans=0 ;
      while(r<n)
      {
         while(ar[r]!=0 && r<n)
         {
            r++ ; 
         }
         while(ar[l]==0 && l<n)
         {
            l++ ; 
         }
         if(max(l,r)==n){break;}
         ar[l]--;
         ar[r]++;
         ans++;
      }
      for (int i = 0; i+1 < n ; ++i)
      {
         ans+=ar[i+1] ; 
      } 
      cout << ans << endl ;
   }
   return 0 ;
}