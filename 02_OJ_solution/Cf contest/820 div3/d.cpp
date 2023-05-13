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
int n,xr[maxx+10],yr[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> xr[i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> yr[i+1] ; 
      }
      std::vector < int > p,q,z ;
      for (int i = 0; i < n ; ++i)
      {
         int x = yr[i+1]-xr[i+1] ; 
         if(x>=0)
         {
            p.push_back(x) ; 
         }
         else
         {
            q.push_back(-x) ; 
         }
      }
      int left = p.size() ; 
      sort(q.begin(),q.end()) ; 
      sort(p.begin(),p.end(),greater<int>()) ; 
      auto it = p.begin() ; 
      auto lt = q.begin() ; 
      int ans = 0 ; 
      while(it!=p.end() && lt!=q.end())
      {
         int x = *it ;
         int y = *lt ;
         if(x-y>=0)
         {
            left-- ; 
            ans++ ; 
            it++;
            lt++;
         }
         else
         {
            z.push_back(*lt) ; 
            lt++ ; 
         }
      }
      sort(z.begin(),z.end()) ;
      auto kt = z.begin() ; 
      while(kt!=z.end() && it!=p.end())
      {
         int sub = 0 ; 
         int y = *kt ; 
         int sum = 0 ; 
         while(it!=p.end())
         {
            int x = *it ; 
            sum+=x ; 
            if(sum<y)
            {
               sub++ ; 
               it++ ; 
            }
            else
            {
               kt++ ; 
               break ;    
            }
         }
         if(sum>=y){ans++;left-=sub;}
      } 
      ans+=(left/2) ; 
      cout << ans << endl ;
   }
   return 0 ;
}