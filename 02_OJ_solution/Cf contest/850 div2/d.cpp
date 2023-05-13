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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,br[maxx+10] ; 
void solve()
{
   set < int > s ; 
   cin >> n ;
   vector < int > used(n+5,0) ;  
   for (int i = 0; i < n+5 ; ++i)
   {
      s.insert(i) ; 
   }
   priority_queue < int , vector < int > , greater < int > > pq ;
   int as = 0 ;  
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      ar[i+1] = x ;
      used[x]++ ; 
   }
   int f = 1 ; 
   for(int i=1;i<=n;i++)
   {
      int x = ar[i] ; 
      int y = 0 ;
      if(!pq.empty() && used[pq.top()]==0 )
      {
         y = pq.top() ; pq.pop() ; 
      }
      else
      {
         while(used[as]!=0){pq.push(as);as++;}
         y = as ; 
         as++ ; 
      }
      br[i] = y ; 

      auto it = s.find(y) ;
      if(it!=s.end())
      {
         s.erase(it) ; 
      }
      it = s.begin() ;
      y  = *it ; 
      if(x!=y){f=0;} 
      used[x]-- ; 
   }
   if(f==0)
   {
      cout << "-1" << endl ; return ;
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ; }
      cout << br[i+1] ; 
   }
   cout << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}