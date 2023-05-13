#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 310 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< pii > pq ;
int n,m,ar[maxx+10] ;
vector < int > seg ; 
int calco(int i,int j,int f)
{
   int d = 0 ,idx = 1  ; 
   for(auto p : pq)
   {
      int l = p.ff ;
      int r = p.ss ;
      if( (l<= i && i<=r) && !(l<=j && j<=r) )
      {
         d++ ; 
         if(f)
         {
            seg.push_back(idx) ; 
         }
      }
      idx++ ; 
   }
   int ans = abs( (ar[i]-d)-ar[j] ) ; 
   return ans ;  
}
int main()
{
   debugMode();
   cin >> n >> m ;
   lp(i,1,n){cin >>ar[i];}
   lp(i,1,m)
   {
      int x,y ;
      cin >> x >> y ; 
      pq.push_back({x,y}) ; 
   }
   int ans = 0 ;
   pii fin =  {0,0} ; 
   int p=0,q=0 ; 
   lp(i,1,n)
   {
      lp(j,i+1,n)
      {
         int x = ar[i] ; 
         int y = ar[j] ; 
         int temp = calco(i,j,0) ; 
         if(temp>ans)
         {
            p = i ; 
            q = j ; 
            ans = temp ; 
         }
         temp = calco(j,i,0) ; 
         if(temp>ans)
         {
            p = j ; 
            q = i ; 
            ans = temp ; 
         }
      }
   }
   cout << ans << endl ; 
   int temp = calco(p,q,1) ; 
   int idx = 1 ; 
   cout << seg.size() << endl ;
   for(auto x : seg )
   {
      if(idx!=1){cout << " " ; }
      idx = 2  ;
      cout << x ; 
   }
   cout << endl ;
   return 0 ;
}