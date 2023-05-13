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
ll ar[maxx+10],br[maxx+10],n,m ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      priority_queue < int > p,q ; 
      cin >> n >> m ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll ans = 0  ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         if(br[i+1]==1)
         {
            p.push(ar[i+1]) ;
         }
         else
         {
            q.push(ar[i+1]) ;
         }
      }
      ll rem = 0 ; 
      while(rem<m)
      {
         ll need = m-rem ; 
         
         if(!p.empty())
         {
            if(p.top()>=need)
            {
                rem+=p.top() ; 
                ans++ ; 
                p.pop() ; break ; 
            }
         }
         if(!p.empty() && !q.empty())
         {
            if(p.top()>=q.top())
            {
               ans++ ; 
               rem+=p.top() ; 
               p.pop() ; 
            }
            else
            {
               if(p.size()>1)
               {
                   ll x = p.top() ; 
                   p.pop() ; 
                   ll y = p.top() ; 
                   if(x+y>=q.top())
                   {
                      rem+=(x+y) ; 
                      p.pop() ; 
                   }
                   else
                   {
                      rem+=q.top() ; 
                      q.pop() ; 
                      p.push(x) ; 
                   }
               }
               else
               {
                   rem+=q.top() ; 
                   q.pop() ; 
               }
               ans+=2 ; 
            }
         }
         else if (!p.empty())
         {
            ans++ ; 
            rem+=p.top() ; 
            p.pop() ; 
         }
         else if (!q.empty())
         {
            ans+=2 ; 
            rem+=q.top() ; 
            q.pop() ; 
         }
         else{ break ; }
      }
      if(rem<m){ans=-1;}
      cout << ans << endl ;
   }
   return 0 ;
}