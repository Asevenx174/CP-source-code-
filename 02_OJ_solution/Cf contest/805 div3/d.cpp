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
int main()
{
   debugMode();
   char cc = 'a' ; 
   int idx = 1 ; 
   map < char ,int > ci ; 
   map < int , char > ic ; 
   while(cc<='z')
   {
      ci[cc]=idx ; 
      ic[idx]=cc ; 
      cc++ ; 
      idx++ ; 
   } 
   int test ;
   cin >> test ;
   while(test--)
   {
      std:: vector < int > f(30,0) ;
      string s ;
      cin >> s ;
      int p ;
      cin >> p ;
      int sum = 0 ; 
      for(auto c : s )
      {
         int x = ci[c] ; 
         f[x]++ ;
         sum+=x ;  
      }
      int ans = 0 ; 
      idx = 26 ; 
      while( ( sum-(f[idx]*idx) ) >= p )
      {
         sum-=(f[idx]*idx) ; 
         f[idx] = 0 ; 
         idx-- ; 
      }
      
      ans = 0 ; 
      int sub = ( max(0,sum-p) )/idx ; 
      sum-=(sub*idx) ; 
      ans+=sub ; 
      while(sum>p)
      {
         sum-=idx ;
         ans++ ; 
      }
      f[idx]-=ans ; 
      string pq = "" ; 
      for(auto c : s )
      {
         int x = ci[c] ; 
         if(f[x]==0){continue;}
         f[x]-- ; 
         pq+=c ; 
      }
      cout << pq << endl ;
   }
   return 0 ;
}