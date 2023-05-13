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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int pr[maxx+10],wr[maxx+10],ar[maxx+10],n,q ;
int ir[maxx+1],rr[maxx+10],br[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      vector < pii > v ; 
      map < pii ,int > pq ; 
      memset(wr,0,sizeof(wr)) ; 
      deque < int > dq ; 
      cin >> n >> q ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ;
         dq.push_back( i+1 ) ; 
      }
      for (int i = 0; i < q ; ++i)
      {
         int idx,r ;
         cin >> idx >> r ; 
         ir[i+1] = idx ; 
         rr[i+1] = r ; 
         v.push_back({r,idx}) ; 
      }
      sort(v.begin(),v.end()) ; 
      auto it = v.begin() ;  
      int sum = 0 ;
      while(ar[dq.front()]!=n)
      {
         sum++ ; 
         int x = dq.front() ; dq.pop_front() ; 
         int y = dq.front() ; dq.pop_front() ; 
         if( ar[x] > ar[y] )
         {
            wr[x]++ ;
            dq.push_back(y) ; 
            dq.push_front(x) ;
         }
         else
         {
            wr[y]++ ;
            dq.push_back(x) ; 
            dq.push_front(y) ; 
         }
         while(it!=v.end())
         {
            pii p = *it ; 
            if(p.ff==sum)
            {
               x = p.ss ; 
               pq[{p.ss,p.ff}] = wr[x] ;
               it++ ; 
            }
            else{break;}
         }
      }
      int idx = 1 ; 
      while(!dq.empty())
      {
         int x = dq.front() ; dq.pop_front() ; 
         br[x] = idx++ ;
      }
      while(it!=v.end())
      {
         pii p = *it ; 
         pq[{p.ss,p.ff}] = wr[] ;
         it++; 
      }
      for (int i = 0; i < q ; ++i)
      {
         int ans = pq[{ir[i+1],rr[i+1]}] ; 
         cout << ans << endl ;
      }
   }
   return 0 ;
}