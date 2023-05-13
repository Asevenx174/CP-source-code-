#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>
#define pi                 pair < int , pair < int ,int > >
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
int n,hr[maxx+10],wr[maxx+10],ar[maxx+10][5],vr[maxx+10][10],ir[maxx][10] ; 
int pre[maxx+10],loc[maxx+10],ans[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      vector < pi > sow ;
      std::vector< int > pq,qp ;
      vector < pii > soh ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> hr[i+1] >> wr[i+1] ; 
         sow.push_back( { wr[i+1] , { hr[i+1] , i+1 } } ) ;
         soh.push_back({hr[i+1],wr[i+1]}) ;
         pq.push_back(wr[i+1]) ; 
         qp.push_back(hr[i+1]) ; 
      }
      sort(pq.begin(),pq.end()) ; 
      sort(soh.begin(),soh.end()) ; 
      sort(sow.begin(),sow.end()) ; 
      int pos = 1 ; 
      for(auto x : sow )
      {
         int w = x.ff ; 
         pii p = x.ss ;
         int h = p.ff ; 
         int idx = p.ss ; 
         ar[pos][1] = w ; 
         ar[pos][2] = h ; 
         ar[pos][3] = idx ; 
         pos++ ;  
      }
      int i1=0,i2=0,v1=mod,v2=mod ; 
      vr[0][1] = mod ; 
      vr[0][2] = mod ; 
      for(int i=1;i<=n;i++)
      {
         int w = ar[i][1] ; 
         int h = ar[i][2] ; 
         int idx = ar[i][3] ; 
         vector < pii > temp ; 
         temp.push_back({v1,i1}) ;
         temp.push_back({v2,i2}) ;
         temp.push_back({h,i}) ;
         sort(temp.begin(),temp.end()) ; 
         auto it = temp.begin() ; 
         pii p = *it ; 
         v1 = p.ff ; 
         i1 = p.ss ;  
         it++ ; 
         p = *it ; 
         v2 = p.ff ; 
         i2 = p.ss ;
         vr[i][1] = v1 ; 
         vr[i][2] = v2 ; 
         ir[i][1] = i1 ; 
         ir[i][2] = i2 ; 
      }
      int k = 1,best=mod,prev=0  ; 
      pre[0] = mod ; 
      for(auto x : soh)
      {
          if(best>x.ss)
          {
             best = x.ss ; 
             prev = k ;  
          }
          pre[k] = best ; 
          loc[k] = prev ; 
          k++ ;  
      }
      for(int i=1;i<=n;i++)
      {
         int hi = hr[i] ; 
         int wi = wr[i] ; 
         auto it = lower_bound(qp.begin(),qp.end(),hi) ; 
         int lim = it-qp.begin() ; 
         int temp = -1 ; 
         if(lim>0 && pre[lim]<wi )
         {
            temp = loc[lim] ;  
         } 
         auto lt = lower_bound(pq.begin(),pq.end(),hi) ;
         lim = lt-pq.begin() ; 
         if(lim>0)
         {
            if(wi>vr[lim][1] && ir[lim][1]!=i )
            {
               temp = ir[lim][1] ; 
            }
            else if (wi>vr[lim][2] && ir[lim][2]!=i)
            {
               temp = ir[lim][2] ; 
            }
         }
         ans[i] = temp ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ; }
         cout << ans[i+1] ; 
      }
      cout << endl ;
   }
   return 0 ;
}