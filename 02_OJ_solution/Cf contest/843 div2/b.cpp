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
std::vector < int > v[maxx+10] ;
void solve()
{
   map < int , int > pq ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n+5  ; ++i)
   {
      v[i].clear() ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      int k ;
      cin >> k ; 
      for (int j = 0; j < k ; ++j)
      {
         int x ;
         cin >> x ; 
         pq[x]++ ; 
         v[i].push_back(x) ; 
      }
   }
   int ans = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      int f = 1 ; 
      for(auto x : v[i] )
      {
         if(pq[x]==1){f=0;}
      }
      if(f){ans=1;}
   }
   if(ans)
   {
      cout << "Yes" << endl ; 
   }
   else
   {
      cout << "No" << endl ;
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