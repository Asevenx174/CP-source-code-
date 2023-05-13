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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,neg=0 ;
      cin >> n ;
      lp(i,1,n)
      {
         cin >> ar[i] ;
         if(ar[i]<0){neg++;}
         ar[i] = max(ar[i],-ar[i]) ; 
      }
      int idx = neg+2,f=1 ; 
      while(idx<=n)
      {
         if(ar[idx]<ar[idx-1])
         {
            f=0 ; 
         }
         idx++ ; 
      }
      idx = neg-1 ; 
      while(idx>0)
      {
         if(ar[idx+1]>ar[idx])
         {
            f=0 ; 
         }
         idx-- ; 
      }
      if(f==1)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}