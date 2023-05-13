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
      std::vector < pii > pq ;
      int n,k ;
      cin >> n >> k ; 
      int f = 1 ; 
      if(k%2==1)
      {
         for(int i=1;i<=n;i+=2)
         {
            pq.push_back({i,i+1}) ; 
         }
      }
      else
      {
         for(int i=2;i<=n;i+=2)
         {
           if(i%4==0)
           {
              pq.push_back({i-1,i}) ; 
           }
           else if( (i+k)%4==0 )
           {
              pq.push_back({i,i-1}) ; 
           }
           else{f=0;}
         }
       }
       if(f==0)
       {
         cout << "NO" << endl ; continue ; 
       }
       cout << "YES" << endl ;
       for(auto x : pq )
       {
         cout << x.ff << " " << x.ss << endl ;
       }
   }
   return 0 ;
}