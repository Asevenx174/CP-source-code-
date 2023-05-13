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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

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
   char cc = 'a' ; 
   int idx = 1 ; 
   map < char ,int > con ; 
   map < int ,char > pq ; 
   while(cc<='z')
   {
      pq[idx]=cc ; 
      con[cc++]=idx++ ; 
   }

   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,k ;
      cin >> n >> k ;
      string s ;
      cin >> s ;
      idx = 1 ; 
      for(auto c : s )
      {
         ar[idx++]=con[c] ; 
      }
      ll d = min(ar[1]-1,k) ;
      k-=d ; 
      idx = 2 ; 

      ll r = ar[1] ; 
      ll l = ar[1]-d ;
      ll a=0,b=0 ;  
      while(idx<=n)
      {
         if(ar[idx]>r && k>0)
         {
            int need = min(ar[idx]-r,k) ; 
            ar[idx]-=need ; 
            if(ar[idx]==r){r+=need;}
            else
            {
               a=ar[idx] ; 
               b=ar[idx]+need ; 
            }
            k-=need ; 
         }
         if(a<=ar[idx] && ar[idx]<=b)
         {
            ar[idx]=a ; 
         }
         if(l<=ar[idx] && ar[idx]<=r)
         {
            ar[idx]=ar[1]-d ; 
         }
         idx++ ; 
      }

      ar[1]-=d ; 
      lp(i,1,n)
      {
         cout << pq[ ar[i] ] ; 
      }
      cout << endl ;
   }
   return 0 ;
}