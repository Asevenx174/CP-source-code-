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
const ll maxx = 305 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int n,m,ar[maxx+5][maxx+5],br[1000005] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      memset(ar,0,sizeof(ar));
      set < int > s ; 
      cin >> n >> m ;
      for(int i=1;i<=n*m;i++)
      {
         int x ;
         cin >> x ; 
         br[i] = x ; 
         s.insert(x) ; 
      }
      map < int ,int > pq ; 
      int idx = 1 ; 
      for(auto x : s )
      {
         pq[x] = idx++ ; 
      }
      int len = s.size() ; 
      deque < int > dq[len+5] ; 
      for(int i=1;i<=n*m;i++)
      {
         int x = pq[ br[i] ] ; 
         dq[x].push_back(i) ;
      }
      idx = 1 ; 
      for(int i=1;i<=n;i++)
      {
         int j = 1 ; 
         int cov = dq[idx].size() ; 
         if(cov>m)
         {
            int temp = m ;
            while(temp--)
            {
               dq[idx].pop_front() ; 
            }
            continue ; 
         }
         else if(cov==m)
         {
            idx++ ; 
            continue ; 
         }
         while( (m-j+1)>dq[idx].size() )
         {
            while(!dq[idx].empty())
            {
               int x = dq[idx].back() ; dq[idx].pop_back() ; 
               ar[i][j++] = x ; 
            }
            idx++ ; 
         }
         int pos = m ;
         int temp = m-j+1 ;
         while(temp>0)
         {
            ar[i][pos--] = dq[idx].front() ; 
            dq[idx].pop_front() ; 
            temp-- ; 
         } 
         if(dq[idx].empty()){idx++;}
      }
      int ans = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(ar[i][1]==0){continue;}
         ordered_set o_set;
         int temp = 0 ; 
         for(int j=m;j>0;j--)
         {
            //cout << " " << ar[i][j] ; 
            int sm = o_set.size()-o_set.order_of_key(ar[i][j])  ;
            ans+=sm ; 
            temp+=sm ; 
            o_set.insert(ar[i][j]) ; 
         }
         //cout << endl ;
      }
      cout << ans << endl ;
   }
   return 0 ;
}