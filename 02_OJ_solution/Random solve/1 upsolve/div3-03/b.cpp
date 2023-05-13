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
int hr[maxx+1],wr[maxx+10],n ; 
int sh[maxx+10],sw[maxx+10],id[maxx+10] ; 
int calco(int i)
{
   int temp=0 ; 
   int l=1,r=n ; 
   while(l<=r)
   {
      int m = (l+r)/2 ; 
      //cout << m << "->" << sh[m] << endl ;
      if(sh[m]>=hr[i])
      {
         l = m+1 ; 
      }
      else
      {
         temp = m ; 
         r = m-1 ; 
      }
   }
   //cout << temp << endl ;
   if(temp==0){return -1;}
   int j = id[temp] ; 
   if(hr[j]<hr[i] && wr[j]<wr[i]){ return j ; }
   return -1 ; 
}
int calco2(int i)
{
   int temp=-1 ; 
   int l=1,r=n ; 
   while(l<=r)
   {
      int m = (l+r)/2 ; 
      int idx = id[m] ; 
      int best = wr[idx] ;
      if(best>=hr[i])
      {
         r = m-1 ; 
      }
      else
      {
         if(hr[idx]>=wr[i])
         {
            l = m+1 ; 
         }
         else
         {
            temp = idx ; 
            r = m-1 ; 
         }
      }
   }
   return temp ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector < pair < int , pii > > v ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> hr[i+1] >> wr[i+1] ; 
         v.push_back({hr[i+1],{i+1,wr[i+1]}} );
      }
      sort(v.begin(),v.end()) ; 
      int best = mod,idx=n,last ; 
      for(auto t : v )
      {
         int h = t.ff ; 
         int w = t.ss.ss ; 
         int i = t.ss.ff ; 
         if(w<best)
         {
            best = w ; 
            last = i ;  
         }
         sh[idx] = h ; 
         id[idx] = last ;  
         idx-- ; 
      }
      /*for(int i=1;i<=n;i++)
      {
        // cout << i << " " << sh[i] << endl ;
      }
      int q ;
      cin >> q ;
      while(q--)
      {
         int idx ;
         cin >> idx ; 
         cout << calco(idx) << endl ;
      }*/
      for(int i=1;i<=n;i++)
      {
         //cout << sh[i] << " " << id[i] << endl ;
         if(i>1){cout << " " ;}
         int ans = calco(i) ;
         if(ans==-1)
         {
            ans = calco2(i) ; 
         } 
         cout << ans ; 
      }
      cout << endl ;
   }
   return 0 ;
}