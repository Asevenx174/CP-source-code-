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
const ll maxx = 2e5+10,mod=1005,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],last=0,br[maxx+10] ; 
std::vector < int > pm ;
bool valid(int n,int idx)
{
   auto it = lower_bound(pm.begin(),pm.end(),n) ;
   if(*it==n){ last = idx ; ar[idx] = 0 ; return true;}
   while(1)
   {
      int y = *it ; 
      int sub = y-n ; 
      if(sub>n){return false;}
      if(valid(sub-1,idx+1))
      {
         ar[idx] = sub ; 
         return true ; 
      }
      it++ ; 
   }
   return false ; 
}
int main()
{
   debugMode();
   for(int i=0;i<=mod;i++)
   {
      pm.push_back(i*i) ; 
   }
   int test ;
   cin >> test ; 
   while(test--)
   {
      last = 0 ; 
      int n ;
      cin >> n ;
      if(valid(n-1,1))
      {
         int idx = 1 , r = n-1 ; 
         while(idx<=last)
         {
            int a = ar[idx] ; 
            int temp = r-a+1 ; 
            while(temp--)
            {
               br[r] = a ; 
               r--;
               a++;
            }
            r = ar[idx]-1 ; 
            idx++ ; 
         }
         for (int i = 0; i < n ; ++i)
         {
            if(i>0){cout << " " ;}
            cout << br[i] ; 
         }
         cout << endl ;
      }
      else
      {
         cout << "-1" << endl ;
      }
   }
   return 0 ;
}