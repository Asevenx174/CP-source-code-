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
   int test ;
   cin >> test ;
   while(test--)
   {
      string a,b ;
      cin >> a >> b ; 
      map < char ,int > pq ; 
      pq[ a[0] ]++ ; 
      pq[ a[1] ]++ ; 
      pq[ b[0] ]++ ; 
      pq[ b[1] ]++ ;
      char cc = 'a' ; 
      std::vector < int > v ;
      while(cc<='z')
      {
         if(pq[cc]==0){cc++;continue;}
         //cout << cc << " " << pq[cc] << endl ;
         v.push_back(pq[cc]) ; 
         cc++ ;
      } 
      sort(v.begin(),v.end(),greater<int>()) ; 
      int len = v.size() ; 
      auto it = v.begin() ; 
      int ans = 0 ; 
      if(len==1)
      {
         ans = 0 ;
      }
      else if(len==4)
      {
         ans = 3 ; 
      }
      else if(*it==3)
      {
         ans = 1 ; 
      }
      else
      {
         it++ ; 
         if(*it==2)
         {
            ans = 1 ; 
         }
         else
         {
            ans = 2 ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}