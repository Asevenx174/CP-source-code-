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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
void solve()
{
   int n ; 
   cin >> n ;
   std::vector < int > v[n+5] ;
   for (int i = 0; i < n ; ++i)
   {
      v[i+1].push_back(i+1) ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      int j = 0 ; 
      while(j<n)
      {
         int x = s[j]=='0' ? 0 : 1 ; 
         if(x==1)
         {
            int a = i+1 ; 
            int b = j+1 ; 
            if(a==b){j++;continue;}
            v[b].push_back(a) ; 
         }
         j++ ; 
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      cout << v[i+1].size() ; 
      for(auto x : v[i+1])
      {
         cout << " " << x ; 
      }
      cout << endl ;
   }
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