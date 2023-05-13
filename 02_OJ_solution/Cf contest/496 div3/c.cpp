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
const ll maxx = 120000+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n ; 
int main()
{
   debugMode();
   map < int ,int > pq ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      pq [ ar[i+1] ] ++ ; 
   }
   std::vector < ll > v ;
   ll p = 2 ; 
   while(p<=imax)
   {
      v.push_back(p) ; 
      p = p*2LL ; 
   }
   ll ans = 0 ;  
   for(int i=1;i<=n;i++)
   {
      ll x = ar[i] ; 
      ll add = 1 ; 
      for(auto y : v )
      {
         ll sub = y-x ; 
         if(sub==x && pq[x]>1)
         {
            add = 0 ; 
         }
         else if(sub!=x && pq[sub]>0)
         {
            add = 0 ; 
         }
      }
      ans+=add ; 
   }
   cout << ans << endl ;
   return 0 ;
}