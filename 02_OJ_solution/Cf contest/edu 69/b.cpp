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
int ar[maxx+10],n ; 
int main()
{
   debugMode();
   int idx = 0 ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      if(ar[i+1]==n)
      {
         idx = i+1 ; 
      }
   }
   int l = idx ;
   int r = idx ; 
   int t = n ; 
   int temp = n-1 ; 
   while(1)
   {
      if(l-1>0 && ar[l-1]==t-1)
      {
         l-- ; 
         t-- ; 
      }
      else if(r<n && ar[r+1]==t-1)
      {
         r++ ;
         t-- ; 
      }
      else{break;}
   }
   if(t==1)
   {
      cout << "YES" << endl ; 
   }
   else
   {
      cout << "NO" << endl  ; 
   }
   return 0 ;
}