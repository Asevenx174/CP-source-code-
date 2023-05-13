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
int t = 1 ;
void count_sort(vector < int > &p,vector <int> &c)
{
   int n = p.size() ;
   std::vector < int > cnt(n);
   for(auto x : c)
   {
      cnt[x]++ ;
   }
   std::vector< int > p_new(n) ;
   std::vector< int > pos(n) ;
   pos[0] = 0 ;
   for (int i = 1 ; i < n ; ++i)
   {
      pos[i] = pos[i-1]+cnt[i-1] ;
   }
   for(auto x : p)
   {
      int i = c[x] ;
      p_new[ pos[i] ] = x ;
      pos[i]++ ;
   }
   p = p_new ;
}
void getsuffix(string s)
{
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
      for (int i = 0; i < n ; ++i)
      {
         p[i] = ( p[i]-(1<<k)+n )%n ;
      }
      count_sort(p,c) ;
      vector < int > c_new(n) ;
      c_new[ p[0] ] = 0 ;
      for (int i = 1 ; i < n ; ++i)
      {
         pii prev = {c[p[i-1]],c[ (p[i-1]+(1<<k))%n ]} ;
         pii now  = {c[p[i]],c[(p[i]+(1<<k))%n]} ;
         if(prev==now)
         {
            c_new[ p[i] ] = c_new[ p[i-1] ] ;
         }
         else
         {
            c_new[ p[i] ] = c_new[ p[i-1] ]+1 ;
         }
      }
      c = c_new ;
      k++ ;
   }
   vector < int > lcp(n) ; // o(n)
   k = 0 ;
   for (int i = 0; i < n-1 ; ++i)
   {
      // i-1,j-1 suffix had first k+1 character same
      // so i,j should have first k character same , no need to check
      int pi = c[i] ; // i indexed suffix er suffix array te pos pi
      int j = p[pi-1] ; // prev suffix of i in suffix array
      // j
      // i
      // lcp[i] = lcp( s[i...].s[j...] )
      while(s[i+k]==s[j+k]){k++;}
      lcp[pi] = k ;
      k = max(k-1,0) ;
   }
   int ans = 0 ;
   int idx = p[1] ; 
   for(int i=1;i<n;i++)
   {
       int len = s.size()-p[i-1]-1 ;
       //cout << p[i] << " " << lcp[i] << " " << s.substr(p[i],len) << endl ;
       if(lcp[i]<len){break;}
       idx = p[i] ; 
   }
   cout << idx << endl ;
}
int main()
{
   debugMode();
   string s ;
   cin >> s ;
   s+="$" ;
   getsuffix(s) ;
   return 0 ;
}
