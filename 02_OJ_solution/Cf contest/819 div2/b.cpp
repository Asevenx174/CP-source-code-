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
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,m ;
      cin >> n >> m ;
      if(m<n)
      {
         cout << "NO" << endl ; continue ; 
      }
      if(m==n)
      {
         cout << "YES" << endl ;
         for (int i = 0; i < n ; ++i)
         {
            if(i>0){cout << " " ;}
            cout << "1" ; 
         }
         cout << endl ; continue ; 
      }
      if(n==1)
      {
         cout << "YES" << endl ;
         cout << m << endl ; continue ; 
      }
      if(n==2)
      {
         if(m%2==0)
         {
            ll temp = m/2 ; 
            cout << "YES" << endl ;
            cout << temp << " " << temp << endl ; continue ; 
         }
         else
         {
             cout << "NO" << endl ;
             continue ; 
         }
      }
      if(n%2==1)
      {
         cout << "YES" << endl ;
         for(int i=1;i<=n;i++)
         {
            if(i>1){cout << " " ; }
            int temp = i==n ? m : 1 ; 
            cout << temp ;  
            m-- ;
         }
         cout << endl ;
         continue ; 
      }
      else
      {
         if(m%2==0)
         {
            cout << "YES" << endl ;
            for(int i=1;i<=n;i++)
            {
               if(i>1){cout << " " ; }
               if(i<n-1)
               {
                  cout << "1" ; 
                  m-- ; 
               }
               else
               {
                  cout << m/2  ;
               }
            }
            cout << endl ; continue ; 
         }
         else
         {
            cout << "NO" << endl ;
         }
      }
   }
   return 0 ;
}