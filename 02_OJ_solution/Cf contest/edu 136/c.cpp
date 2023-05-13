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
const ll maxx = 63 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,ar[maxx+10] ;
bool dp[maxx][maxx] ; 
void gen(ll idx,ll tk)
{
   //if(dp[idx][tk]){return;}
   if(idx>n)
   {
      if(tk==(n/2))
      {
         for (int i = 0; i < n ; ++i)
         {
            cout << " " << ar[i+1] ; 
         }
         cout << endl ;
      }
      return ; 
   }
   ar[idx] = 1 ; 
   gen(idx+1,tk+1) ;
   ar[idx] = 2 ; 
   gen(idx+1,tk) ;  
   //dp[idx][tk] = true ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   { 
     memset(dp,false,sizeof(dp)) ; 
     cin >> n ; 
     gen(1,0) ; 
   }
   return 0 ;
}