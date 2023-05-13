#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair < long long , long long >

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
ll ar[maxx+10],n,m,fr[maxx+10] ; 
int main()
{
   debugMode();
   fr[1] = 1 ; 
   for(int i=2;i<maxx;i++)
   {
      ll add = i*(i+1) ; 
      add = add/2 ; 
      fr[i] = fr[i-1]+add ;
   }
   cin >> n >> m ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   std::vector < pii > v ; 
   for (int i = 0; i < m ; ++i)
   {
      ll idx,x ;
      cin >> idx >> x ; 
      v.push_back({idx,x}) ; 
   }
   ll f = 0 ; 
   for(int i=1;i<=n;i++)
   {
      while(ar[i+1]==ar[i] && i+1<=n)
      {
         i++ ; 
      }
      f++ ; 
   }
   for(auto p : v )
   {
      ll idx = p.ff ;
      ll x   = p.ss ;
      if(ar[idx]==x){ cout << fr[f] << endl ;  continue;}
      if(idx==1)
      {
         if(ar[idx]==ar[idx+1])
         {
            f++ ; 
         }
         else
         {
            if(x!=ar[idx+1]){f++;}else{f--;}
         }
      } 
      else if(idx==n)
      {
         if(ar[idx]==ar[idx-1])
         {
            f++ ; 
         }
         else
         {
            if(x!=ar[idx-1]){f++;}else{f--;}
         }
      }
      else
      {
         if(ar[idx]!=ar[idx-1] && ar[idx]!=ar[idx+1])
         {
            if(x==ar[idx+1] || x==ar[idx-1]){f--;}
         }
         else if(ar[idx]!=ar[idx+1])
         {
            if(x!=ar[idx+1]){f++;}
         }
         else if(ar[idx]!=ar[idx-1])
         {
            if(x!=ar[idx-1]){f++;}
         }
         else
         {
            f+=2 ; 
         }
      }
      cout << fr[f] << endl ; 
      ar[idx] = x ; 
   }
   return 0 ;
}