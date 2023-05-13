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
bool valid(ll l,ll r)
{
   bool ans = true ; 
   for(int i=l;i<=r;i++)
   {
      for(int j=i+1;j<=r;j++)
      {
         for(int k=j+1;k<=r;k++)
         {
            if(ar[i]<=ar[j] && ar[j]<=ar[k]){ans=false;}
            if(ar[i]>=ar[j] && ar[j]>=ar[k]){ans=false;}
         }
      }
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
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll ans = n+(n-1) ; 
      for(ll i=1;i<=n;i++)
      {
         ll temp = 2 ; 
         while(i+temp<=n && temp<6)
         {
            if(valid(i,i+temp))
            {
               ans++ ; 
            }
            temp++ ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}