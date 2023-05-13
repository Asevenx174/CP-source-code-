#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=998244353,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
vector < ll > fac ; 
ll n,m,ar[maxx+10] ; 
map < pii , bool > used ; 
map < pii , ll > str ; 
void calcofac()
{
   ll val = ar[1] ; 
   ll p = 2 ; 
   while( (p*p)<=val )
   {
      bool s = false ; 
      while(val%p==zz)
      {
         val = val/p ;
         s = true ; 
      }
      if(s)
      {
         fac.push_back(p) ; 
      }
      p++ ; 
   }
   if(val>qq)
   {
      fac.push_back(val) ; 
   }
}
ll idx,pr[20],d,k,res=0,co=0 ; 
bool dp[12][1<<12] ; 
void gen(int pos,int mask)
{
   if(dp[pos][mask])
   {
      return  ; 
   }
   if(pos==idx)
   {   
      //cout << "yes" << " " << idx <<  endl ;
      ll sum = 0,mul=1,id=0 ; 
      for (int i = 0; i < idx ; ++i)
      {
         ll add = qq << i ; 
         if( (ll)mask&add )
         {
            ll x = pr[i] ; 
            //cout << i << " " << x << endl ;
            mul = mul*x ; 
            id++ ; 
         }
      }
      ll temp = k/mul ; 
      if(mul==1){temp=0;}
      if(id%tt==qq)
      {
         co= (co+temp)%mod ; 
      }
      else
      {
         co= (co-temp+mod)%mod ;
      } 
      return ; 
   }
   ll add = qq << pos ; 
   gen(pos+1,(mask|add)) ; 
   gen(pos+1,mask) ; 
   dp[pos][mask] = true ; 
   return ; 
}
void calco()
{
   idx = 0 ; 
   for(auto x : fac)
   {
      if(d%x==zz)
      {
         //cout << idx << " " <<  d << " " << x << endl ; 
         pr[idx] = x ;
         idx++ ;    
      }
   }
   co = 0 ; 
   memset(dp,false,sizeof(dp)) ; 
   gen(0,0) ; 
   res= (res+(k-co))%mod  ; 
}
void solve()
{ 
   used.clear() ; 
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   fac.clear() ; 
   calcofac()  ;
   ll ans = 1,flag=1 ;
   for(int i=2;i<=n;i++)
   {
      if( (ar[i-1]%ar[i]) != zz ) { flag=0 ; break; }
      d = ar[i-1]/ar[i] ; 
      k = m/ar[i] ; 
     // cout << i << " " << d << " " << k << endl ;
      res = 0 ;
      if(used[{d,k}])
      {
         res = str[{d,k}] ; 
      }
      else
      {
         calco() ;
         used[{d,k}] = true ; 
         str[{d,k}] = res ; 
      } 
      //cout << i << " " << res << endl ;
      ans = (ans*res)%mod ; 
   }
   if(!flag){ans=0;}
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}