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
const ll maxx = 2010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10][maxx+10],n ;
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int to = 0 ; 
      cin >> n ;
      lp(i,0,n-1)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='1' ? 1 : 0 ; 
            ar[i][j++] = x ; 
            to+=x ; 
         }
      }
      int maxd = 0 ; 
      lp(r,0,n-1)
      {
         lp(d,0,n-1)
         {
            int sum = 0 ; 
            lp(k,0,n-1)
            {
               int i = k-d ; 
               if(i<0){i+=n;}
               int j = k-r ;
               if(j<0){j+=n;}
               sum+=ar[i][j] ; 
            }
            maxd = max(maxd,sum) ; 
         }
      }
      int ans = (n-maxd)+(to-maxd) ; 
      cout << ans << endl ;
   }
   return 0 ;
}