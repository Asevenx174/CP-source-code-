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
   vector < pii > mf ; 

   void init(int n)// ini the array whose size is 2^k>n , k is min
   {
      siz = 1 ;
      while(siz<n)
      {
         siz = siz*2 ; 
      }
      mf.assign(2*siz,{0,0}) ;  
   }
   pii combine(pii &a,pii &b)
   {
      if(a.ff<b.ff) { return a ; }
      else if(a.ff>b.ff){ return b ; }
      else { return {a.ff,a.ss+b.ss} ; }
   }
   void build(vector< int > &ar,int x,int lx,int rx)
   {
       if(rx-lx==1)
       {
          if(lx<(int)ar.size())// siz>=a.size()
          {
            mf[x] = {ar[lx],1} ; 
          }
          return ; 
       }
       int mid = (lx+rx)/2 ; 
       int lc = 2*x+1 , rc = 2*x+2 ;
       build(ar,lc,lx,mid) ; 
       build(ar,rc,mid,rx) ; 
       mf[x] = combine(mf[lc],mf[rc]) ;  
   }
   void build(vector< int > &ar)
   {
       build(ar,0,0,siz) ;
   }
   void sett(int idx,int val,int x,int lx,int rx)
   {
      if(rx-lx==1)
      {
         mf[x] = {val,1} ; return ;//*** node (x) a val set hbe
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
      mf[x] = combine(mf[lc],mf[rc]) ;  
   }
   void sett(int idx,int val)
   {
      sett(idx,val,0,0,siz) ; // root node is 0
   }
   pii getmin(int l,int r,int x,int lx,int rx)
   {
       //cout << lx << " " << rx << endl ;
       if(r<=lx || rx<=l) { return {mod,0} ; }
       if(l<=lx && rx<=r) { return mf[x] ; } 
       int mid = (lx+rx)/2 ;   //** mid is middle of lx,rx 
       int lc = 2*x+1 , rc = 2*x+2 ;  
       pii p1 = getmin(l,r,lc,lx,mid) ;
       pii p2 = getmin(l,r,rc,mid,rx) ;
       return combine(p1,p2) ;  
   }
   pii getmin(int l,int r)
   {
      return getmin(l,r,0,0,siz) ;
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
         pii p = st.getmin(l,r) ; // find sum of [l..r-1] range
         cout << p.ff << " " << p.ss << endl ; 
      }
   }
   return 0 ;
}