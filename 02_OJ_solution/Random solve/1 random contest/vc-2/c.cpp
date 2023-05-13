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
int ar[maxx+10],br[maxx+10] ; 
int main()
{
   debugMode();
   char cc = 'a' ; 
   int idx = 1 ; 
   map < char , int > ci ; 
   map < int , char > ic ; 
   while(cc<='z')
   {
      ci[cc]=idx ; 
      ic[idx]=cc ; 
      cc++ ; 
      idx++ ; 
   }
   int n ;
   cin >> n ;
   string s ;
   cin >> s ; 
   idx = 1 ;
   for(auto c : s )
   {
      ar[idx] = ci[c] ;
      idx++ ;  
   }
   for(int i=1;i<=n;i+=2)
   {
      if(ar[i]==ar[i+1])
      {
         br[i]=1 ; 
         br[i+1]=1 ; 
      }
   }
   for(int i=3;i<=n;i+=2)
   {
       if(br[i]==1 && br[i-1]==1)
       {
          if(ar[i]!=ar[i-1])
          {
             br[i] = 0 ; 
             br[i-1] = 0 ; 
          }
       }
   }
   int ans = 0 ; 
   s = "" ; 
   for(int i=1;i<=n;i++)
   {
      if(br[i]==0)
      {
         s+=ic[ ar[i] ] ; 
      }
      else{ans++;}
   }
   string k = "" ; 
   for(int i=1;i<=s.size();i+=2)
   {
      if(i+1>s.size())
      {
         ans++ ; 
      }
      else if (s[i]!=s[i-1])
      {
         ans++ ; 
      }
      else
      {
         k+=s[i-1] ;
         k+=s[i] ;  
      }
   }
   cout << ans << endl ;
   cout << k << endl ;
   return 0 ;
}