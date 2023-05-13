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
bool used[maxx+10] ; 
ll n,q,lim ; 
ll wr[maxx+10],pre[maxx+10],idx,taken,pq[maxx+10],f[maxx+10],qr[maxx+10],box=0 ; 
void calco(ll l,ll r,ll g)
{
   ll a = l , b = r , ans=0 ; 
   while(a<=b)
   {
      ll m = (a+b)/2LL ;
      if( pre[m]-pre[l-1]>=g )
      {
         b = m-1 ; 
         ans = m ;  
      }
      else
      {
         a = m+1 ; 
      }
   }
   taken = ans-l+1 ; 
   if(ans==n)
   {
      idx = 1 ; 
   }
   else
   {
      idx = ans+1 ; 
   }
   return ;  
}
ll fun(ll k)
{
   if(k==0){return 0 ; }
   ll lp = k/box ; 
   ll ex = k%box ; 
   idx = 1 ; 
   ll ans = lp*taken ; 
   while(ex--)
   {
      ans+=f[idx] ; 
      idx = pq[idx] ; 
   } 
   return ans ; 
}
int main()
{
   debugMode();
   cin >> n >> q >> lim ; 
   ll to = 0 ,sum=0 ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> wr[i] ; 
      sum+=wr[i] ; 
      to+=wr[i] ; 
      pre[i+1] = sum ; 
   }
   for (int i = 0; i < q ; ++i)
   {
      cin >> qr[i+1] ; 
   }
   ll lp = lim/sum ; 
   ll ex = lim%sum ; 
   for(int i=1;i<=n;i++)
   {
      ll co = lp*n ; 
      ll temp = ex ; 
      ll have = pre[n]-pre[i-1] ; 
      if(have>=temp)
      {
         calco(i,n,temp) ; 
      }
      else
      {
         co+=(n-i+1) ;  
         temp-=have ; 
         calco(1,i-1,temp) ; 
      }
      co+=taken ; 
      pq[i]=idx ; 
      f[i]=co ;
      //cout << i << " " << f[i] << " " << pq[i] << endl ;
   }
   taken = 0 ; 
   idx = 1 ; 
   do
   {
      used[idx]=true ; 
      taken+=f[idx] ; 
      idx = pq[idx] ; 
      box++ ; 
   }
   while(!used[idx]) ; 
   for(int i=1;i<=q;i++)
   {
      ll k = qr[i] ; 
      ll ans = fun(k)-fun(k-1) ; 
      cout << ans << endl ; 
   } 
   return 0 ;
}