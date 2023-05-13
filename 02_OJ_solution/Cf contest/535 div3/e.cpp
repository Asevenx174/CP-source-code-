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
int n,m,ar[maxx+10] ;
int main()
{
   debugMode();
   std::vector< pii > pq ;
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
   lp(i,1,n)
   {
      lp(j,i+1,n)
      {
         int x = ar[i] ; 
         int y = ar[j] ; 
         int a=0,b=0 ;
         for(auto p : pq )
         {
            int l = p.ff ; 
            int r = p.ss ;
            if(l<=min(x,y) && max(x,y)<=r){continue;}
            if(max(x,y)<l || min(x,y)>r){continue;}
            if(l<=x && x<=y)
            {
               a++ ; 
            }
            else
            {
               b++ ; 
            }
         }
         if(x<y){swap(x,y);swap(a,b);}
         y-=b ;
         int temp = abs(x-y) ; 
         if(temp>ans)
         {
            ans = temp ; 
            fin = {i,j} ; 
         }
      }
   }
   int i = fin.ff ; 
   int j = fin.ss ; 
   int x = ar[i] ; 
   int y = ar[j] ;
   vector < int > res ; 
   if(x>y)
   {
         int idx = 1 ; 
         for(auto p : pq )
         {
            int l = p.ff ; 
            int r = p.ss ;
            if(l<=min(x,y) && max(x,y)<=r){continue;}
            if(max(x,y)<l || min(x,y)>r){continue;}
            if( !(l<=x && x<=y) )
            {
               res.push_back(idx) ; 
            }
            idx++ ; 
         }
   }
   else
   {
         int idx = 1 ; 
         for(auto p : pq )
         {
            int l = p.ff ; 
            int r = p.ss ;
            if(l<=min(x,y) && max(x,y)<=r){continue;}
            if(max(x,y)<l || min(x,y)>r){continue;}
            if( (l<=x && x<=y) )
            {
               res.push_back(idx) ; 
            }
            idx++ ; 
         }
   }
   cout << ans << endl ;
   cout << res.size() << endl ;
   int idx = 0 ; 
   for(auto x : res )
   {
      if(idx!=0){cout << " " ;}
      idx = 1 ; 
      cout << x ; 
   }
   cout << endl ;
   return 0 ;
}