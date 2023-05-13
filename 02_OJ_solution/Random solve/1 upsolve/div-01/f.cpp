#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>
#define pi                 pair < pair < int ,int > ,int  >
///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll br[maxx+10],ar[maxx+10],n ; 
bool com(const pi &a,const pi &b)
{
   pii x = a.ff ; 
   pii y = b.ff ; 
   if(x.ss==y.ss)
   {
       return x.ff > y.ff ; 
   }
   else
   {
       return x.ss > y.ss ;  
   }
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector < pi > v ;
      set < int > s ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         br[i+1] = x ; 
         s.insert(i+1) ; 
         int l=(i+1)/(x+1),r ;
         if(x==0)
         {
            r = n ; 
         } 
         else
         {
            r = (i+1)/x ;  
         }
         v.push_back({ {l,r},i+1 }) ; 
      }
      sort(v.begin(),v.end(),com) ; 
      int temp = n ; 
      for(auto x : v )
      {
         pii p = x.ff ; 
         //cout << p.ff << " " << p.ss << " " << x.ss << endl ;
         ar[x.ss] = temp-- ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ;}
         cout << ar[i+1] ; 
      }
      cout << endl ; 
   }
   return 0 ;
}