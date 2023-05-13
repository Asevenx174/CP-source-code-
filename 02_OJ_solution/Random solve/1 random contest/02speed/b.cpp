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
      int n,m ;
      cin >> n >> m ;
      std::vector < bool > used(n+10,false);
      for (int i = 0; i < m ; ++i)
      {
         int a,b,c ;
         cin >> a >> b >> c ; 
         used[b] = true ; 
      }
      queue < int > p,q ; 
      for(int i=1;i<=n;i++)
      {
         if(used[i])
         {
            q.push(i) ; 
         }
         else
         {
            p.push(i) ; 
         }
      }
      int r = p.front() ; 
      int last = r ; 
      p.pop() ; 
      while(!p.empty())
      {
         int x = p.front() ; p.pop() ; 
         cout << last << " " << x << endl ; 
         last = x ;  
      }
      while(!q.empty())
      {
         cout << r << " " << q.front() << endl ; 
         q.pop() ; 
      }
   }
   return 0 ;
}