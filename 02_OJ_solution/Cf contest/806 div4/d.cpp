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
// set(i,v) - > a[i]=v 
// sum(l,r) - > a[l]+ar[l+1]....ar[r-1]

struct segtree
{
   int siz ; 
   vector < ll > sums ; 

   void init(int n)// ini the array whose size is 2^k>n , k is min
   {
      siz = 1 ;
      while(siz<n)
      {
         siz = siz*2 ; 
      }
      sums.assign(2*siz,0) ; 
   }
   void build(vector< int > &ar,int x,int lx,int rx)
   {
       if(rx-lx==1)
       {
          if(lx<(int)ar.size())// siz>=a.size()
          {
            sums[x] = ar[lx] ; 
          }
          return ; 
       }
       int mid = (lx+rx)/2 ; 
       int lc = 2*x+1 , rc = 2*x+2 ;
       build(ar,lc,lx,mid) ; 
       build(ar,rc,mid,rx) ; 
       sums[x] = sums[lc]+sums[rc] ;
   }
   void build(vector< int > &ar)
   {
       build(ar,0,0,siz) ;
   }
   void sett(int idx,int val,int x,int lx,int rx)
   {
      if(rx-lx==1)
      {
         sums[x] = val ; return ;//*** node (x) a val set hbe
      }
      int mid = (lx+rx)/2 ; //** mid is middle of lx,rx 
      int lc = 2*x+1 , rc = 2*x+2 ;
      if(idx<mid)
      {
          sett(idx,val,lc,lx,mid);
      }
      else
      {
          sett(idx,val,rc,mid,rx);
      }
      sums[x] = sums[lc]+sums[rc] ; 
   }
   void sett(int idx,int val)
   {
      sett(idx,val,0,0,siz) ; // root node is 0
   }
   ll sum(int l,int r,int x,int lx,int rx)
   {
       //cout << lx << " " << rx << endl ;
       if(r<=lx || rx<=l) { return 0 ; }
       if(l<=lx && rx<=r) { return sums[x] ; } 
       int mid = (lx+rx)/2 ;   //** mid is middle of lx,rx 
       int lc = 2*x+1 , rc = 2*x+2 ;  
       ll s1 = sum(l,r,lc,lx,mid) ;
       ll s2 = sum(l,r,rc,mid,rx) ;
       return s1+s2 ; 
   }
   ll sum(int l,int r)
   {
      return sum(l,r,0,0,siz) ;
   }
};
int main()
{
   debugMode();
   int n,m ;
   cin >> n >> m ;
   segtree st ; 
   st.init(n) ; 
   std::vector< int > ar(n+5) ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i] ; 
   }
   st.build(ar) ; // instead of call n times sett fun ,here we call once build fun o(siz)
   while(m--)
   {
      int op ; 
      cin >> op ;
      if(op==1)
      {
         int idx,val ; 
         cin >> idx >> val ; 
         st.sett(idx,val) ; 
      }
      else
      {
         int l,r ;
         cin >> l >> r ; 
         cout << st.sum(l,r) << endl ; // find sum of [l..r-1] range 
      }
   }
   return 0 ;
}