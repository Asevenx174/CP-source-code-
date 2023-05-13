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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

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
   int test ;
   cin >> test ;
   while(test--)
   {
      priority_queue < pii > pq ; 
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         pq.push({x,i+1}) ; 
      }
      while(pq.size()>1)
      {
         pii p = pq.top() ; pq.pop() ; 
         pii q = pq.top() ; pq.pop() ; 
         if(p.ff>1)
         {
            pq.push({p.ff-1,p.ss}) ; 
         }
         if(q.ff>1)
         {
            pq.push({q.ff-1,q.ss}) ;
         }
      }
      pii p = pq.top() ; 
      cout << p.ss << endl ;
   }
   return 0 ;
}