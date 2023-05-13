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
void radix_sort(vector < pair < pii , int > > &a)
{
   int n = a.size() ; 
   {
      std::vector < int > cnt(n) ; // cnt[1] indicates the number pairs ends with 1
      for(auto p : a)
      {
         cnt[p.ff.ss]++ ; 
      }
      vector < pair < pii , int > > a_new(n) ; 
      vector < int > pos(n) ;
      pos[0] = 0 ; 
      for(int i=1;i<n;i++)
      {
         pos[i] = pos[i-1]+cnt[i-1] ; // pos[1] indicates the index of first pair ends with 1
      } 
      for(auto p : a)
      {
         int i = p.ff.ss ; 
         a_new[pos[i]] = p ; 
         pos[i]++ ;  // indicates the next index of i'th bucket
      }
      a = a_new ; 
   }
   {
      std::vector < int > cnt(n) ; 
      for(auto p : a)
      {
         cnt[p.ff.ff]++ ; 
      }
      vector < pair < pii , int > > a_new(n) ; 
      vector < int > pos(n) ;
      pos[0] = 0 ; 
      for(int i=1;i<n;i++)
      {
         pos[i] = pos[i-1]+cnt[i-1] ; 
      } 
      for(auto p : a)
      {
         int i = p.ff.ff ; 
         a_new[pos[i]] = p ; 
         pos[i]++ ;  
      }
      a = a_new ; 
   }
}
int main()
{
   debugMode(); 
   string s ;
   cin >> s ;
   s+="$" ; 
   int n = s.size() ; 

   std::vector < int > p(n),c(n) ;
   {
      vector < pair < char ,int > > a(n) ; 
      for( int i=0;i<n;i++) { a[i] = {s[i],i} ;}
      sort(a.begin(),a.end()) ; 
      
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
   }

   int k = 0 ; 
   while ( (1 << k) < n ) // logn
   {
      vector < pair < pii ,int > > a(n) ; 
      for (int i = 0; i < n ; ++i)
      {
          a[i] = { { c[i] , c[ (i+(1<<k))%n ] } , i } ; 
      }
      radix_sort(a) ; // o(n)

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