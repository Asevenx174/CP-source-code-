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
ll res[maxx+10],ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ll n ;
      cin >> n ;
      string s ;
      cin >> s ;
      ll idx = 1,sum=0 ;
      for(auto c : s )
      {
         ll x = c=='L' ? 0 : 1 ; 
         if(c=='R')
         {
            sum+=(n-idx) ; 
         }
         else
         {
            sum+=(idx-1) ; 
         }
         ar[idx++] = x ; 
      }
      std::vector < ll > up ;
      ll m = n/2 ; 
      for(int i=1;i<=n;i++)
      {
           if(i<=m && ar[i]==0)
           {
              ll p = i-1 ; 
              ll q = n-i ;  
              if(p==q){continue;}
              up.push_back(q-p) ;  
           }
           else if(i>m && ar[i]==1)
           {
              ll p = n-i ; 
              ll q = i-1 ;
              if(p==q){continue;}
              up.push_back(q-p) ;
           }
      }
      sort(up.begin(),up.end(),greater<int>()) ; 
      auto it = up.begin() ; 
      for(int i=1;i<=n;i++)
      {
         if(i>1){cout << " " ; }
         if(it!=up.end())
         {
            sum+=*it ; 
            it++ ; 
         }
         cout << sum ; 
      }
      cout << endl ;
   }
   return 0 ;
}