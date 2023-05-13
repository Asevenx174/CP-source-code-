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
const ll maxx = 200+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < 2*n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   int ans = 0 ; 
   for(int i=1;i<=2*n;i+=2)
   {
      if(ar[i]==ar[i+1]){continue;}
      int j = i+2 ; 
      while(j<=2*n)
      {
         if(ar[j]==ar[i]){break;}
         j++ ; 
      }
      //cout << i << " " << j << endl ;
      while(ar[j-1]!=ar[i])
      {
         swap(ar[j],ar[j-1]) ; 
         j-- ; 
         ans++ ; 
      }
   }
   cout << ans << endl ;
   return 0 ;
}