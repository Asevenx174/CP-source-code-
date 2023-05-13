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
   debugMode(); // O(n(logn)^2)
   string s ;
   cin >> s ;
   s+="$" ; 
   int n = s.size() ; 
   // p is current suffix array  , c is the class array 
   std::vector < int > p(n),c(n) ;
   {
      // for each k , p and c get changed 
      // p[i]-> indicates the index of i'th ordered string of s
      // c[i]-> ordered class
      // here k=0
      vector < pair < char ,int > > a(n) ; 
      for( int i=0;i<n;i++) { a[i] = {s[i],i} ;}
      sort(a.begin(),a.end()) ; // nlogn
      
      // k=0 , 2^k = 1 lenght string er jnno 
      for(int i=0;i<n;i++){ p[i] = a[i].ss ; }
      c[ p[0] ] = 0 ; // sorted first (index) er class 0 
      for(int i=1;i<n;i++)
      {
         if(a[i].ff==a[i-1].ff)
         {
            c[ p[i] ] = c[ p[i-1] ] ; // same class
         }
         else
         {
            c[ p[i] ] = c[ p[i-1] ] + 1 ; 
         }
      }
   }

   int k = 0 ; 
   while ( (1 << k) < n ) // iterater logn times 
   {
      // k = k+1 
      vector < pair < pii ,int > > a(n) ; 
      for (int i = 0; i < n ; ++i)
      {
          a[i] = { { c[i] , c[ (i+(1<<k))%n ] } , i } ; 
      }
      sort(a.begin(),a.end()) ; // nlogn

      for(int i=0;i<n;i++){ p[i] = a[i].ss ; }
      c[ p[0] ] = 0 ;
      for(int i=1;i<n;i++)
      {
         if(a[i].ff==a[i-1].ff)
         {
            c[ p[i] ] = c[ p[i-1] ] ;
         }
         else
         {
            c[ p[i] ] = c[ p[i-1] ] + 1 ; 
         }
      }
      k++;
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << p[i]  ;
   }
   cout << endl ;
   return 0 ;
}