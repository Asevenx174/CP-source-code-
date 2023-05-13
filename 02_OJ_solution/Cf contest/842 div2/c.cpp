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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10],cr[maxx+10],n ; 
void solve()
{
   std::vector < pii > v ;
   priority_queue < int > p,q ; 
   map < int ,int > f,k,r ; 
   int n,best=0 ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      f[x]++ ; 
      cr[i+1] = x ; 
      best = max(best,f[x]) ; 
      v.push_back({x,i+1}) ; 
      ar[i+1] = 0 ; 
      br[i+1] = 0 ; 
   }
   if(f[1]==2 || best>2){cout << "NO" << endl ; return ;}
   for (int i = 0; i < n ; ++i)
   {
      int j = i+1 ; 
      int x = cr[j] ;
      if(k[x]==0)
      {
         ar[j] = x ; 
         k[x] = 1 ; 
      }
      else
      {
         br[j] = x ; 
         r[x] = 1 ; 
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      if(k[i+1]==0)
      {
         p.push(i+1) ; 
      }
      if(r[i+1]==0)
      {
         q.push(i+1) ; 
      }
   }
   sort(v.begin(),v.end(),greater<pii>()) ; 
   for(auto pq : v)
   {
      int x = pq.ff ; 
      int idx = pq.ss ; 
      if(ar[idx]==0)
      {
        // while( k[ p.top() ] == 1 ){ p.pop(); }
         ar[idx] = p.top() ; p.pop() ; 
      }
      else
      {
         // while( r[ q.top() ] == 1 ){ q.pop(); }
         br[idx] = q.top() ; q.pop() ;
      }
      int l = min(ar[idx],br[idx]) ;
      int r = max(ar[idx],br[idx]) ;
      if(cr[idx]!=r || l==0) 
      {
         cout << "NO" << endl ; return ;
      }
   }
   cout << "YES" << endl ;
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ar[i+1] ; 
   }
   cout << endl ;
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << br[i+1] ; 
   }
   cout << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}