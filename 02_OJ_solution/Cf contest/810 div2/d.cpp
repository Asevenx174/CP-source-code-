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
int ar[maxx+10] ; 
int main()
{
   debugMode();
   std::vector< int > v;
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      v.push_back(x) ; 
   }
   sort(v.begin(),v.end(),greater<int>()) ; 
   auto it = v.begin() ; 
   for(int i=2;i<=n;i+=2)
   {
      ar[i] = *it ; it++ ;
   }
   for(int i=1;i<=n;i+=2)
   {
      ar[i] = *it ; it++ ;
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ; }
      cout << ar[i+1] ; 
   }
   cout << endl ;
   return 0 ;
}