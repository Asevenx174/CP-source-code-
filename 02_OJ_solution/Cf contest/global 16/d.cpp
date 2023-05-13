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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool com(const pii p,const pii q)
{
   if(p.ff!=q.ff)
   {
      return p.ff < q.ff ; 
   }
   else
   {
      return p.ss < q.ss ;  
   }
}
int ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ordered_set o_set;
      std::vector < pii > pq ;
      int n,m ;
      cin >> n >> m ;
      int p = 1 ; 
      for (int i = 0; i < n ; ++i)
      {
         for (int i = 0; i < m ; ++i)
         {
            int a ;
            cin >> a ;
            pq.push_back({a,p}) ; 
            p++ ; 
         }
      }
      sort(pq.begin(),pq.end()) ; 
      int pos = 1 ; 
      for(auto x : pq )
      {
         //cout << pos << " " << x.ff << " " << x.ss << endl ;
         pos++ ; 
      }

      deque < int > dq[6010] ; 
      int prev = -1,k=0 ; 
      for(auto pp : pq )
      {
         if(prev==pp.ff)
         {
            dq[k].push_front(pp.ss) ; 
         }
         else
         {
            k++ ; 
            dq[k].push_front(pp.ss) ; 
         }
         prev = pp.ff ; 
      }
      int idx = 1 ; 
      int last = mod  ; 
      k = 1 ; 
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            if(dq[k].size()==0)
            {
              k++ ; 
            }
            if(last>dq[k].front())
            {
               ar[idx] = dq[k].front() ; 
               dq[k].pop_front() ; 
            }
            else if(last>dq[k].back())
            {
               ar[idx] = dq[k].back() ; 
               dq[k].pop_back() ; 
            }
            else
            {
               ar[idx] = dq[k].front() ; 
               dq[k].pop_front() ;
            }
            last = ar[idx] ; 
            idx++ ; 
         }
         last = mod ; 
      }
      idx = 1 ; 
      int ans = 0 ; 
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            int val = ar[idx++] ;
           // cout << " " << val ;  
            ans+=o_set.order_of_key(val) ; 
            o_set.insert(val) ; 
         }
         //cout << endl ;
         o_set.clear() ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}