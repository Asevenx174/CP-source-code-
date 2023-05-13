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
int ar[maxx+10],dp[10][10],br[maxx+10] ;
void cpy(int n)
{
   lp(i,1,n){br[i]=ar[i];}
} 
int main()
{
   debugMode();
   

   map < char ,int > ci ; 
   map < int ,char > ic ; 
   ic[1] = 'R' ;
   ic[2] = 'G' ;
   ic[3] = 'B' ;
   ci['R'] = 1 ; 
   ci['G'] = 2 ; 
   ci['B'] = 3 ; 

   int n ;
   cin >> n ; 
   string s ;
   cin >> s ;
   int idx = 1 ; 
   for(auto c : s )
   {
      int x = ci[c] ; 
      ar[idx++] = x ; 
   }
   
   lp(i,1,n)
   {
      int r = i%3 ; 
      int x = ar[i] ; 
      dp[r][x]++ ; 
   }
   int ans = mod ; 


   lp(i,1,3)
   {
      lp(j,1,3)
      {
         lp(k,1,3)
         {
            if(i==j || i==k || j==k){continue;}
            // 0>i 
            // 1>j 
            // 2>k 
            int sum = dp[0][j]+dp[0][k]+dp[1][i]+dp[1][k]+dp[2][i]+dp[2][j] ;
            if(sum<ans)
            {
               ans = sum ; 
               cpy(n) ; 
               lp(p,1,n)
               {  
                  int x = ar[p] ; 
                  int r = p%3 ; 
                  if(r==0 && x!=i)
                  {
                     br[p]=i ; 
                  }
                  else if(r==1 && x!=j)
                  {
                     br[p]=j ;
                  }
                  else if(r==2 && x!=k)
                  {
                     br[p]=k ; 
                  }
               }
            }
         }
      }
   }
   cout << ans << endl ;
   lp(i,1,n)
   {
      cout << ic[br[i]] ;  
   }
   cout << endl ;
   return 0 ;
}