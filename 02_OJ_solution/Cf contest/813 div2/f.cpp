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
ll pr(ll n)
{
   ll d = 1 ;
   ll temp = n ; 
   while(temp>9)
   {
      temp = temp/10 ; 
      d++ ; 
   }
   ll idx=1,ans=0,sub=0 ;
   for(int i=1;i<d;i++)
   {
      ll temp = idx*9LL ; 
      //cout << i << " " << temp << endl ;
      sub+=temp ; 
      ans+=(i*temp) ; 
      idx = idx*10LL ;  
   }
   //cout << sub << endl ;
   ans+=(d*(n-sub)) ; 
   return ans ;
}
int main()
{
   debugMode();
   ll n ;
   cin >> n ;
   cout << pr(n) << endl ;
   return 0 ;
}