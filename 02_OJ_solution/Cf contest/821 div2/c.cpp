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
int ar[maxx+10],n ;
std::vector< int > v[5] ;
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      v[0].clear() ; 
      v[1].clear() ; 
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         v[x%2].push_back(i+1) ; 
         ar[i+1] = x ; 
      }
      int f = ar[1]%2 ; 
      cout << n-1 << endl ; 
      int len = v[f].size() ; 
      for (int i = 0; i+1 < len ; ++i)
      {
         cout << v[f][i] << " " << v[f][len-1] << endl ;
      }
      len = v[!f].size() ; 
      for (int i = 0; i < len ; ++i)
      {
         cout << "1 " << v[!f][i] << endl ; 
      }
   }
   return 0 ;
}