#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
int ar[maxx+10],n ; 
int main()
{
   debugMode();
   cin >> n ; 
   lp(i,1,n)
   {
      cin >> ar[i] ; 
   }
   int k = 0 ; 
   lp(i,3,n-2)
   {
      if(ar[i-2]==1 && ar[i-1]==0 && ar[i]==1 && ar[i+1]==0 && ar[i+2]==1)
      {
         k++ ; 
         ar[i]=0 ; 
      }
   }
   lp(i,2,n-1)
   {
      if(ar[i-1]==1 && ar[i]==0 && ar[i+1]==1)
      {
         k++ ;
         ar[i+1]=0 ; 
      }
   }
   cout << k << endl ;
   return 0 ;
}