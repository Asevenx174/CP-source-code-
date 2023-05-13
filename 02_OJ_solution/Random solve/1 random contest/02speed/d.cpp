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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,m,ar[maxx+5],br[maxx+5],last[maxx+10] ;
string a,b ;  
bool le(int r)
{
   int l = 1,idx=1 ; 
   while(l<=r)
   {
      int w = br[l] ; 
      //while(idx<=n && ar[idx]!=w){idx++;}
      if(ar[idx]!=w){return false;}
      l++ ; 
      idx++ ; 
   }
   return true ; 
}
bool re(int idx,int l)
{
   while(l<=m)
   {
      int w = br[l] ; 
      //while(idx>0 && ar[idx]!=w){idx--;}
      if(ar[idx]!=w){return false;}
      l++ ; 
      idx-- ; 
   }
   return true ; 
}
int main()
{
   debugMode();
   map < char ,int > ci ;
   map < int ,char > ic ; 
   char ch = 'a' ; 
   int idx = 1 ; 
   while(ch<='z')
   {
      ci[ch] = idx ; 
      ic[idx] = ch ; 
      ch++ ; 
      idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> a >> b ; 
      n = a.size() ; 
      m = b.size() ;
      idx = 1 ; 
      for(auto c : a )
      {
         ar[idx] = ci[c] ;
         last[ ar[idx] ] = idx ; 
         idx++ ;  
      }
      idx = 1 ; 
      for(auto c : b )
      {
         br[idx++] = ci[c] ; 
      }
      int ans = 0 ; 
      for(int i=1;i<m;i++)
      {
         if(le(i))
         {
            if(re(last[ br[i] ]-1,i+1 )){ans=1;}
         }
      }
      if(le(m)){ans=1;}
      if(re(n,1)){ans=1;}
      if(ans)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}