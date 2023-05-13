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
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n ; 
ll used[maxx+10] ; 
int main()
{
   debugMode();
   cin >> n ;
   ll sum = 0 ; 
   lp(i,1,n)
   {
      cin >> ar[i] ; sum+=ar[i] ; 
      used[ ar[i] ]++ ; 
   }
   std::vector< ll > k ; 
   lp(i,1,n)
   {
      ll x = ar[i] ; 
      used[x]-- ; 
      ll temp = sum-x ; 
      if(temp%2LL==0LL)
      {
         temp = temp/2LL ; 
         if(used[temp]>0LL)
         {
            k.push_back(i) ; 
         }
      } 
      used[x]++;
   }
   cout << k.size() << endl ; 
   if(k.size()==0){ return 0 ; }
   int idx = 0 ; 
   for(auto x : k )
   {
      if(idx!=0){cout << " " ; } idx = 1 ; 
      cout << x ; 
   }
   cout << endl ;
   return 0 ;
}