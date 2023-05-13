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
const ll maxx = 2e5+10,mod=1e6,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,br[maxx+10] ; 
void solve()
{
   set < int > s ;
   s.insert(n) ;
   s.insert(mod) ; 
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ;
      s.insert(i) ;  
   }
   std::vector < int > v ;
   v.push_back(0) ; 
   for(int i=2;i<=n;i++)
   {
      if(ar[i]>ar[i-1])
      {
         v.push_back(i) ; 
      }
      else if(i==n)
      {
         v.push_back(i) ; 
      }
   }
   
   int f = 1 ; 
   for(int i=1;i<=n;i++)
   {
      int x = br[i] ; 
      auto it = s.find(x) ; 
      if(it!=s.end())
      {
         s.erase(it) ; 
      }
      it = s.begin() ; 
      x = *it ; 
      if(x!=ar[i]){f=0;}
      cout << " " << br[i] ; 
   }
   cout << endl ;
   if(f)
   {
      for (int i = 0; i < n ; ++i)
      {
         //if(i>0){cout << " " ; }
        // cout << br[i] ; 
      }
     // cout << endl ;
   }
   else
   {
      cout << "-1" << endl ;
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
  // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}