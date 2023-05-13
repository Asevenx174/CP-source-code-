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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int p[maxx+10],q[maxx+10] ; 
int main()
{
   debugMode();
   set < int > s ; 
   int n,x ;
   cin >> n >> x ; 
   for (int i = 0; i < n ; ++i)
   {
      int temp ;
      cin >> temp ; 
      p[temp]++ ;  
      s.insert(temp) ; 
 
      int y = temp&x ; 
      if(y==temp){continue;}
      q[y]++ ;
      s.insert(y) ; 
   }
   int ans = mod ; 
   for(auto x : s )
   {
      if(p[x]>1){ans=0;break;}
      else if(p[x]>0 && q[x]>0)
      {
         ans = 1 ; 
      }
      else if(q[x]>1 && ans>2)
      {
         ans = 2 ; 
      }
   }
   if(ans==mod){ans=-1;}
   cout << ans << endl ;
   return 0 ;
}