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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,br[maxx+10]; 
int f[10] ; 
int main()
{
   debugMode();
   cin >> n ;
   int p = n/3 ; 
   string s ;
   cin >> s ;
   int idx = 1 ; 
   for(auto c : s )
   {
      int x = c-'0' ; 
      ar[idx]=x ;
      f[x]++ ; 
      idx++ ;  
   }
   lp(i,1,n)
   {
       int x = ar[i] ; 
       if(f[x]<=p){continue;}
       if(x==2)
       {
           if(f[0]<p)
           {
              f[0]++ ; 
              ar[i]=0 ; 
           }
           else
           {
              f[1]++ ; 
              ar[i]=1 ;
           }
           f[x]-- ; 
       }
       else if(x==1 && f[0]<p)
       {
          f[0]++ ; 
          ar[i]=0 ; 
          f[x]-- ; 
       }
   }
   int j = n  ;
   while(f[0]>p)
   {
      int x = ar[j] ; 
      if(x==0)
      {
          if(f[2]<p)
          {
             ar[j]=2 ; 
             f[2]++ ; 
          }
          else
          {
             ar[j]=1 ; 
             f[1]++ ; 
          }
          f[0]-- ;
      }
      j-- ; 
   }

   j = n  ;
   while(f[1]>p)
   {
      int x = ar[j] ; 
      if(x==1)
      {
          if(f[2]<p)
          {
             ar[j]=2 ; 
             f[2]++ ; 
          }
          else
          {
             ar[j]=0 ; 
             f[0]++ ; 
          }
          f[1]-- ;
      }
      j-- ; 
   }




   lp(i,1,n)
   {
      cout << ar[i] ; 
   }
   return 0 ;
}