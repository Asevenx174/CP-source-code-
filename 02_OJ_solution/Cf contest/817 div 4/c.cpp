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
      std::vector< int > ans(5,0) ;
      set < string > k ; 
      map < string , vector < int > > pq ; 
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ; 
         pq[s].push_back(1) ; 
         k.insert(s) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ; 
         pq[s].push_back(2) ; 
         k.insert(s) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ; 
         pq[s].push_back(3) ; 
         k.insert(s) ; 
      }
      for(auto x : k )
      {
         int len = pq[x].size() ;
         if(len==3){continue;}
         auto it = pq[x].begin() ; 
         if(len==2)
         {
            ans[*it]++ ; 
            it++ ; 
            ans[*it]++ ; 
         } 
         else
         {
            ans[*it]+=3 ; 
         }
      }
      cout << ans[1] << " " << ans[2] << " " << ans[3] << endl ;
   }
   return 0 ;
}