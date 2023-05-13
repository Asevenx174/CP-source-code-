#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n ; 
void solve()
{
   std::vector < ll > v ;
   cin >> n ; 
   if(n%tt==zz)
   {
      ll idx = n/2 ; 
      for (int i = 0; i < n+1 ; ++i)
      {
         if(idx!=n){v.push_back(idx);}
         idx++ ; 
      }
   }
   else
   {
      ll idx = n/2+1 ; 
      for (int i = 0; i < n ; ++i)
      {
         v.push_back(idx+2);
         idx++ ; 
      }
      v[0] = v[0]-1 ; 
      v[n-1] = v[n-1]+1 ; 
      v[n-2] = v[n-2]+1 ;  
   }
   for (int i = 0; i < v.size() ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << v[i] ; 
   }
   cout << endl ; 
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}