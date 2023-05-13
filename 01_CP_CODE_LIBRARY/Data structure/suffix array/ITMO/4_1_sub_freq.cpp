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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

int sufs[maxx+10] ; 
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
   for (int i = 0; i < n ; ++i)
   {
      sufs[i+1] = p[i] ; 
      //string temp = s.substr(p[i],((int)s.size()-p[i]-1)) ; 
      //cout << i << " " << temp << endl ; 
   }
}
int pt = 0 ; 
void check(string s,string k,int lim)
{
   int l = 1 ;
   int r = lim+1,idx ; 
   while(l<=r)
   {
      int m = (l+r)/2 ;
      string sub =  s.substr(sufs[m],(int)k.size()) ;
      if(sub==k){pt=m;}
      if(sub<k)
      {
         l = m+1 ; 
      }
      else
      {
         r = m-1 ; 
      }
   } 
}
void check2(string s,string k,int lim)
{
   int l = 1 ;
   int r = lim,idx ; 
   //cout << l << "??"<< r << endl ; 
   while(l<=r)
   {
      int m = (l+r)/2 ;
      //cout << m << endl ; 
      string sub =  s.substr(sufs[m],(int)k.size()) ;
      if(sub==k){pt=m;}
      if(sub<=k)
      {
         l = m+1 ; 
      }
      else
      {
         r = m-1 ;  
      }
   } 
}
int main()
{
   debugMode(); 
   string s ;
   cin >> s ;
   s+="$" ; 
   getsuffix(s) ; 
   int n = s.size() ; 
   int q ;
   cin >> q ;
   while(q--)
   {
      string k ;
      cin >> k ;
      pt = 0 ; 
      check(s,k,n) ; 
      int l = pt ; 
      pt = 0 ;
      check2(s,k,n) ; 
      int r = pt ; 
      int ans = 0 ; 
      //cout << l << " " << r << endl ; 
      if(pt!=0){ans=r-l+1;}
      cout << ans << endl ; 
   }
   return 0 ;
}