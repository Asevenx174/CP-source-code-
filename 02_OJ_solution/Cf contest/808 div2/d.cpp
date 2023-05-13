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
ll ar[maxx+10],br[maxx+10],pr[maxx+10],qr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector < int > v[5] ;
      ll n,m,rem=0 ;
      cin >> n >> m ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         v[ br[i+1] ].push_back( ar[i+1] ) ; 
      }
      sort(v[1].begin(),v[1].end(),greater<int>()) ; 
      sort(v[2].begin(),v[2].end(),greater<int>()) ;
      auto it = v[1].begin() ; 
      auto lt = v[2].begin() ; 
      ll p = v[1].size() ; 
      ll q = v[2].size() ; 

      if(p>0)
      {
         if( (*it>=m) ){ cout << "1" << endl; continue ;}
      }

      ll idx = 1 ; 
      while(it!=v[1].end())
      {
         pr[idx++] = *it ; 
         it++ ; 
      }
      idx = 1 ; 
      while(lt!=v[2].end())
      {
         qr[idx++] = *lt ; 
         lt++ ; 
      }

      ll i=0,j=0,temp=0 ;
      while(j+1<=q && temp<m)
      {
         j++ ; 
         temp+=qr[j] ; 
      }
      ll ans = mod ; 
      if(temp>=m)
      {
         ans = i+(2*j) ; 
      }
      while(i+1<=p)
      {
         i++ ; 
         temp+=pr[i] ; 
         while(temp-qr[j]>=m && j>0)
         {
            temp-=qr[j] ; 
            j-- ; 
         }
         if(temp>=m)
         {
            ans = min(ans,i+(2*j)) ; 
         }
      }
      if(ans==mod){ans=-1;}
      cout << ans << endl ;
   }
   return 0 ;
}