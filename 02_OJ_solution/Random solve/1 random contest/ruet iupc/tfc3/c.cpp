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
int ar[maxx+10],br[maxx+10],n,q ; 
int main()
{
   debugMode();
   cin >> n >> q ;
   lp(i,1,n){ar[i]=i;br[i]=i;}
   while(q--)
   {
      int v ;
      cin >> v ; 
      int idx = ar[v] ; 
      int k = idx==n ? n-1 : idx+1 ; 
      int kv = br[k] ; 
      swap(ar[v],ar[kv]) ; 
      swap(br[idx],br[k]) ; 
   }
   lp(i,1,n)
   {
      if(i!=1){cout << " " ;  }
      cout << br[i] ; 
   }
   cout << endl ;
   return 0 ;
}