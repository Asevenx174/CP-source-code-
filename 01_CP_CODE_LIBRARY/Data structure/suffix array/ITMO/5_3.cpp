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

int ar[maxx+10] ; // 0 based 
int st[maxx+10][26],n,lg[maxx+10],q,pr[maxx+10],cr[maxx+10] ; // 26>= log2(maxx<=1e7)

int getmin(int l,int r)
{
   int len = r-l+1 ;
   int j = lg[len] ; 
   int ans = min(st[l][j],st[r-( (1<<j) - 1 )][j]) ; 
   // [1,6] = [1,1+2^2-1] + [6-(2^2-1),6] = [1,4]+[3,6] 
   return ans ; 
}
void precom() // nlogn
{
   lg[1] = 0 ; // 1 can be divided 0 times by 2 
   for(int i=2;i<=maxx;i++)
   {
      lg[i] = lg[i/2]+1 ; 
   }  
   for (int i = 0; i < n ; ++i)
   {
      st[i][0] = ar[i] ; 
   }
   for(int j=1;j<=25;j++)
   {
      for (int i = 0; i + (1<<j) <= n ; ++i)
      {
         st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]) ; 
      } 
   }
}
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
   for (int i = 0; i < n ; ++i)
   {
      ar[i] = lcp[i] ; 
   }
   precom() ; 
   for (int i = 0; i < n ; ++i)
   {
      //cout << lcp[i] << " " << p[i] << " " << c[ p[i] ] << " " << s.substr(p[i],n-p[i]) << endl ;
      pr[i] = p[i] ; 
      cr[ p[i] ] = i ; 
   }
}
vector < pii > pq ; 
bool com(const pii &xx,const pii &yy)
{
   pii a = xx ; 
   pii b = yy ; 
   int la = a.ss-a.ff+1 ; 
   int lb = b.ss-b.ff+1 ; 
   int ca = cr[a.ff] ;
   int cb = cr[b.ff] ; 
   if(ca>cb)
   {
      swap(ca,cb) ; 
      swap(la,lb) ;
      swap(a,b) ;   
   }
   if(ca==cb)
   {
      return la < lb ; 
   }
   if(la<lb)
   {
      return la < lb ; 
   }
   else if(la==lb)
   {
      int com = getmin(ca+1,cb) ;
      if(com==la)
      {
         return a.ff < b.ff ; 
      }
      return ca < cb ;  
   }
   else
   {
      int com = getmin(ca+1,cb) ;
      cout << ca << " " << cb << " " << com << endl ; 
      if(com==lb)
      {
         return ca > cb ; 
      } 
      return ca < cb ; 
   }
}
int main()
{
   debugMode(); 
   string s ;
   cin >> s ;
   s+="$" ; 
   getsuffix(s) ; 
   int q ;
   cin >> q ;
   for (int i = 0; i < q ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      pq.push_back({x-1,y-1}) ;  
   }
   sort(pq.begin(),pq.end(),com) ; 
   for(auto x : pq )
   {
      cout << x.ff+1 << " " << x.ss+1 << endl ; 
   }
   return 0 ;
}