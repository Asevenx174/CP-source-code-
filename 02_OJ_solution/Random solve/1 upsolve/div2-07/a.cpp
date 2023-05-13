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
ll ar[maxx+10],n,k ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n >> k ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll res = mod ; 
      for(ll i=1;i<=k;i++)
      {
         ll l = ar[1]/i,ans=1 ; 
         ll r = l ; 
         for(ll j=2;j<=n;j++)
         {
            ll p = 1 ; 
            if(l==0)
            {
               p = k ;
            }
            else
            {
               p = ar[j]/l ; 
               p = min(p,k) ; 
            }
            ll f=0,pq=mod ; 
            for(ll q=max(1LL,p-25LL);q<=min(k,p+25LL);q++)
            {
               ll temp = ar[j]/q ; 
               if(temp>=l)
               {
            
                  f = 1 ; 
                  pq = min(pq,temp) ; 
               }
            }
            if(f==0)
            {
               ans = 0 ; 
               break ; 
            }
            else
            {
               r = max(r,pq) ; 
            }
         }
         if(ans)
         {
            res = min(res,r-l) ; 
         }
      }
      cout << res << endl ;
   }
   return 0 ;
}