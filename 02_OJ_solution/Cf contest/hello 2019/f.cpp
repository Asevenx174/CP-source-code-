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
const ll maxx = 38,mod=524288,imax=2e9+10,qq=1,zz=0;
 
inline void debugMode() 
{
#ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
}
int sett(int idx,int mask )
{
   mask = mask | (1<< (idx-1)) ; 
   return mask ; 
}
bool check(int idx,int mask )
{
   if( (mask&(1<<(idx-1))) ==0 )
   {
      return false ; 
   }
   return true ; 
}
ll n,m,ans=0 ; 
ll ar[5][50] ; 
std::vector < ll > v[5] ;
bool dp[20][mod+5][5] ; 
void calco(int idx,int mask,int mode)
{
   if(dp[idx][mask][mode]){ return ;}
   if(idx>n)
   {
      ll sum = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(check(i,mask))
         {
            //cout << i << endl ;
            sum+=ar[mode][i] ; 
         }
      }
      sum = sum%m ; 
      v[mode].push_back(sum) ; 
      ans = max(ans,sum) ; 
      return ; 
   }
   calco(idx+1,mask,mode);
   calco(idx+1,sett(idx,mask),mode);
   dp[idx][mask][mode]=true ;
   return ;   
}
int main()
{
   debugMode();
   cin >> n >> m ;
   ll r = n/2,idx=0 ; 
   for(int i=1;i<=n;i++)
   {
      ll x ;
      cin >> x ;
      if(i<=r)
      {
         ar[1][i] = x ; 
      }
      else
      {
         ar[0][++idx] = x ; 
      }
   }
   n = r ; 
   calco(1,0,1);
   n = idx ; 
   calco(1,0,0);
   sort(v[0].begin(),v[0].end()) ; 
   sort(v[1].begin(),v[1].end()) ;
   ll add = 0 ; 
   if(v[1].size()>0)
   {
      auto lt = v[1].rbegin() ; 
      add = *lt ; 
   }
   for(auto x : v[0])
   {
      int need = m-x ; 
      auto it = lower_bound(v[1].begin(),v[1].end(),need) ;
      if(v[1].size()>0)
      {
         if(it!=v[1].begin())
         {
            it-- ; 
            ll temp = x+*it ; 
            ans = max(ans,temp%m) ; 
         }
      }
      ans = max(ans,(x+add)%m ) ; 
   }
   cout << ans << endl ;
   return 0 ;
}