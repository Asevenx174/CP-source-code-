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
const ll maxx = 2e5+10,mod= 998244353,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,k ; 
int main()
{
   debugMode();
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   std::vector< int > v ;
   ll sum = 0 , mul=1 ; 
   for(int i=1;i<=n;i++)
   {
      ll x = ar[i] ; 
      if(x>(n-k))
      {
         v.push_back(i) ; 
         sum+=x ; 
      }
   }
   for(int i=1;i<v.size();i++)
   {
      ll temp =(v[i]-v[i-1])%mod ; 
      mul = (mul*temp)%mod ; 
   }
   cout << sum << " " << mul << endl ;
   return 0 ;
}