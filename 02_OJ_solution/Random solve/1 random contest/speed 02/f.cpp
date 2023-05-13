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
int ar[maxx+10] ; 
int f[maxx+10],ans[maxx+10] ; 
bool used[maxx+10] ; 
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      f[ ar[i+1] ]++ ; 
   }
   priority_queue < int , vector < int > , greater < int > > pq ;
   for(int i=1;i<=n;i++)
   {
      if(f[i]==0)
      {
         pq.push(i) ; 
      }
   }
   int temp = n ; 
   for(int i=1;i<=n;i++)
   {
      int x = ar[i] ; 
      int y = pq.top() ; 
      if(used[x])
      {
         ans[i] = y ; pq.pop() ; used[y] = true ;  continue ; 
      }
      if(f[x]==1)
      {
         temp-- ; 
         used[x]  = true ; 
         f[x]-- ; 
         ans[i] = x ; continue ; 
      }
      if(x>pq.top())
      {
         ans[i] = y ; 
         f[y]-- ; 
         used[y] = true ; 
         pq.pop() ; 
      }
      else
      {
         ans[i] = x ; 
         f[x]-- ; 
         used[x] = true ; 
      }
   }
   cout << temp << endl ;
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ans[i+1] ; 
   }
   cout << endl ; 
   return 0 ;
}