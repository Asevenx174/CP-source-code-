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
const ll maxx = 4e4+10,mod=1e9,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,a[maxx+10],b[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ll sum = 0 ; 
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> b[i+1] ; 
         sum+=b[i+1] ; 
      }
      ll k = ( n*(n+1) ) /2ll ;  
      ll f = 1 ; 
      if( (sum%k)!=0 ){f=0;}
      sum = sum/k ; 
      ll sub = 0 ; 
      for(int i=n;i>1;i--)
      {
         ll temp = sum+b[i-1]-b[i] ; 
         a[i] = temp/n ;
         if(temp<=0 || a[i]<=0 || a[i]>mod || (temp%n)!=0 ){f=0;}
         sub+=a[i] ; 
      }
      a[1] = sum-sub ; 
      if(f==0 || a[1]<=0 || a[1]>mod){cout << "NO" << endl;continue;}
      cout << "YES" << endl ; 
      for(int i=1;i<=n;i++)
      {
         if(i>1){cout << " " ;}
         cout << a[i] ; 
      } 
      cout << endl ;
   }
   return 0 ;
}