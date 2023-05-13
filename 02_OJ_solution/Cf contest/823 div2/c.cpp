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
int xr[maxx+10],dp[maxx+10] ; 
std::vector < int > g[maxx+10] ;
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i < maxx ; ++i)
      {
         g[i].clear() ; 
      }
      map < int ,int > pq,qp ; 
      set < int > s ; 
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> xr[i] ;
         s.insert(xr[i]) ;  
      }
      int idx = 0 ; 
      for(auto x : s )
      {
         pq[x] = idx ;
         qp[idx] = x ; 
         idx++ ;  
      }
      for (int i = 0; i < n ; ++i)
      {
         int temp = pq[ xr[i] ] ;
         g[temp].push_back(i) ; 
      }
      int a,l,r ; 
      int ans = 0,pos,val ; 
      for (int i = 0; i < idx ; ++i)
      {
         int len = g[i].size(),prev=maxx+5 ;
         dp[prev] = 0 ;   
         while(len--)
         {
            int j = g[i][len] ; 
            dp[j] = max(1,dp[prev]+1-(prev-j-1) ) ; 
            if(dp[j]>ans) 
            {
               ans = dp[j] ; 
               l = j ; 
               a = qp[i] ;  
            }
            prev = j ; 
         }
      }
      r = l ; 
      int sum = 0 ;
      while(r<n)
      {
         if(xr[r]==a){sum++;}else{sum--;}
         if(sum==ans){break;}
         r++ ; 
      } 
      l++;
      r++;
      cout << a << " " << l << " " << r << endl ; 
   }
   return 0 ;
}