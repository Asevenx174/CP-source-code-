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
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,x,y ;
      cin >> n >> x >> y ;
      ll g = n ; 
      if(x==y)
      {
         if(x==0){cout << "-1"<< endl; continue ;}
         ll p = g/x ; 
         if(p<0 || p>g || (g%x!=zz) ) { cout << "-1"<< endl; continue ;  }
         ll val = 1 ,idx = 0 ; 
         while(p--)
         {
            ll temp = x ; 
            while(temp--)
            {
               if(idx>0){cout << " " ;}
               cout << val ; 
               idx = 1 ; 
            }
            val = val+x+1 ; 
         }
         cout << endl ; continue ; 
      }
      ll a = g*(1-y) ;
      ll b = x-y ; 
      ll m = a*b ; 
      ll p = a/b ; 
      if(m<0 || (a%b)!=zz || p<0 || p>g ) { cout << "-1"<< endl; continue ; }
      ll val = 1 ,idx = 0 ; 
      ll q = g-p ; 
      //cout << p << "?" << x << endl ; 
      while(p--)
      {
            ll temp = x ; 
            while(temp--)
            {
               if(idx>0){cout << " " ;}
               cout << val ; 
               idx = 1 ; 
            }
            val = val+x+1 ; 
      }
      while(q--)
      {
            ll temp = y ; 
            while(temp--)
            {
               if(idx>0){cout << " " ;}
               cout << val ; 
               idx = 1 ; 
            }
            val = val+y+1 ; 
      }
      cout << endl ; 
   }
   return 0 ;
}