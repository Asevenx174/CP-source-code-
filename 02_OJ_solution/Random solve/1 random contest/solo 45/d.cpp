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
int main()
{
   debugMode();
   map < char ,int > pq ; 
   string s ;
   cin >> s ;
   int best = 0 ; 
   char ch ;
   for(auto c : s )
   {
      pq[c]++ ;
      if(pq[c]>best)
      {
         best = pq[c] ; 
         ch = c ; 
      } 
   }
   int n = s.size() ; 
   if(n==1){cout << "NO" << endl ; return 0 ; }
   int p = mod ; 
   for(int i=2;i<=n;i++)
   {
      int j=2 ; 
      int f = 1 ; 
      while(j<i)
      {
         if(i%j==0){f=0;}
         j++ ; 
      }
      if(f){p=i;}
   }
   int l=1,r=n/p ;
   int ran = r-l+1 ; 
   if(best<ran || r==0)
   {
      cout << "NO" << endl ; return 0 ; 
   }
   cout << "YES" << endl ; 
   char ans[1010] ; 
   for(int i=l;i<=r;i++)
   {
      ans[i] = ch ; 
      pq[ch]-- ;  
   }
   ch = 'a' ; 
   for(int i=1;i<=n;i++)
   {
      if(l<=i && i<=r){continue;}
      while(pq[ch]==0){ch++;}
      ans[i] = ch ; 
      pq[ch]-- ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cout << ans[i+1] ; 
   }
   cout << endl ; 
   return 0 ;
}