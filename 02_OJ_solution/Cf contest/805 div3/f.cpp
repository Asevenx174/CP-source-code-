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
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      map < int ,int > a,b ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         while(x%2==0)
         {
            x = x/2 ; 
         }
         a[x]++ ; 
      }
      std::vector< int > v ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         while(x%2==0)
         {
            x = x/2 ; 
         }
         v.push_back(x) ; 
      }
      int ans = 1 ; 
      for(auto x : v )
      {
         if(a[x]>0)
         {
            a[x]-- ; 
         }
         else
         {
             int f = 0 ; 
             while(x>1)
             {
                x = x/2 ; 
                if(a[x]>0)
                {
                  f = 1 ;
                  a[x]-- ; break ; 
                }
             }
             if(f==0){ans=0;}
         }
      }
      if(ans)
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