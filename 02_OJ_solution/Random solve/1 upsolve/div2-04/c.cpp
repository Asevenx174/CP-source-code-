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
const ll maxx = 510 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10][maxx+10] ; 
ll n,m ; 
string sr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,m ;
      cin >> n >> m ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> sr[i] ; 
      }
      int sum = 0 ; 
      for(int i=0;i<n;i++)
      {
         int j = 0 ; 
         for(auto c : sr[i])
         {
            int x = c=='1' ? 1 : 0 ; 
            sum+=x ; 
            ar[i][j] = x ; 
            j++ ; 
         }
      }
      int ans = 0 ; 
      for (int i = 0; i < n ; ++i)
      {
         for (int j = 0 ; j < m ; ++j)
         {
            if(j+1<m && ar[i][j]==0 && ar[i][j+1]==0)
            {
               ans = 2 ; 
            }
            if(i+1<n && ar[i][j]==0 && ar[i+1][j]==0)
            {
               ans = 2 ; 
            }
            if(ar[i][j]==0)
            {
               ans = max(ans,1) ; 
            }
            if(i+1<n && j+1<m)
            {
               if(ar[i][j]==0 && ar[i+1][j+1]==0){ans=2;}
               if(ar[i+1][j]==0 && ar[i][j+1]==0)
               {
                  ans = 2 ; 
               }
            }
         }
      }
      sum-=(2-ans) ; 
      cout << sum << endl ;
   }
   return 0 ;
}