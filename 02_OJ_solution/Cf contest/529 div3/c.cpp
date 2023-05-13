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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
   int n,k ;
   cin>> n >> k ;
   int idx = 1 ;
   priority_queue < int > pq ; 
   while(idx<=n)
   {
      if( (n&(idx)) )
      {
         pq.push(idx) ; 
      }
      idx = idx*2 ; 
   }
   if(pq.size()>k || k>n)
   {
      cout << "NO" << endl ; return 0 ; 
   }
   while(pq.size()!=k)
   {
      int x = pq.top() ; pq.pop() ; 
      x = x/2 ; 
      pq.push(x) ; 
      pq.push(x) ; 
   }
   cout << "YES" << endl ;
   idx = 0 ; 
   while(!pq.empty())
   {
      if(idx!=0){cout << " " ; }
      idx = 1 ; 
      cout << pq.top() ; 
      pq.pop() ; 
   }
   cout << endl ;
   return 0 ;
}