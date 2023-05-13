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
const ll maxx = 2e5+10,mod= 998244353,imax=2e9+10,qq=1,zz=0;

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
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,s ;
      cin >> n >> s ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll sum = 0 ; 
      priority_queue < pii > pq ; 
      ll ans = 0,f=0 ; 
      for(int i=1;i<=n;i++)
      {
         pq.push({ar[i],i}) ;
         if(sum+ar[i]>s)
         {
            if(pq.empty())
            {
               ans = 1 ; break ; 
            }
            sum = sum+ar[i]-pq.top().ff ; 
            if(sum<=s)
            {
               ans = pq.top().ss ; 
            }
            else
            {
               ans = i ; 
            }
            break ; 
         }
         else
         {
            sum+=ar[i] ;  
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}