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
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      set < int > s ; 
      for (int i = 0; i < n ; ++i)
      {
         s.insert(i+1) ; 
      }
      std::vector< int > v ;
      while(!s.empty())
      {
         auto it = s.begin() ; 
         int x = *it ; 
         v.push_back(x) ; 
         s.erase(it) ; 
         while(1)
         {
            x = x*2 ; 
            it = s.find(x) ;
            if(it==s.end()){break;}
            v.push_back(x) ; 
            s.erase(it) ; 
         }
      }
      cout << "2" << endl ; 
      for (int i = 0; i < v.size(); ++i)
      {
         if(i>0){cout << " " ;}
         cout << v[i] ;
      } 
      cout << endl ;
   }
   return 0 ;
}