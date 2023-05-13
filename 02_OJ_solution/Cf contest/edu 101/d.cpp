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
const ll maxx = 3010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,k ; 
bool valid(int l,int r)
{
   cout << l << " " << r << endl ;
   for(int i=1;i<=n;i++)
   {
      int x = ar[i] ; 
      int d = x/l ; 
      while(d>0)
      {
         int div = x/d ; 
         if(l>div)
         {
            d-- ; 
         }
         else{break;}
      }
      if(d>0)
      {
         int div = x/d ; 
         if(l<=div && div<=r && d<=k)
         {
            continue ; 
         }
      }
      return false ; 
   }
   return true ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int best = mod,pq=0 ; 
      cin >> n >> k ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ;  
         pq = max(pq,ar[i+1]) ; 
      }
      int fin = mod ; 
      for(int i=1;i<=pq;i++)
      {
         int l=i,r=pq,ans=mod ;
         while(l<=r)
         {
            int mid = (l+r)/2 ;
            if(valid(i,mid))
            {
               ans = mid ;
               r = mid-1 ; 
            }
            else
            {
               l = mid+1 ; 
            }
         }
         fin = min(fin,ans-i) ; 
      }
      cout << fin << endl ;
   }
   return 0 ;
}