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
const ll maxx = 7100 ,mod=7900,imax=1e15+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,m,wr[maxx+10],fr[maxx+10],ad[maxx+10] ; 
ll idx = 0 ; 
ll dp[maxx][1005],pd[1000010+10],kr[maxx+10] ; 
ll calco(ll i,ll ed)
{
   if(dp[i][ed]!=-1){ return dp[i][ed] ; }
   if(i>idx)
   {
      //cout << ed << endl ; 
      if(ed==zz)
      {
         return zz ; 
      }
      return imax ; 
   }
   ll ans = imax ; 
   for(ll j=0;j<=fr[i];j++)
   {
      ll tk = j*ad[i] ; 
      if(tk>ed){continue;}
      //cout << j << " " << tk << endl ; 
      ll cost = j*wr[i] ;  
      ll temp = cost+calco(i+1,ed-tk) ;
      ans = min(ans,temp) ; 
   }
   return dp[i][ed] = ans ; 
}
void solve()
{
   idx = 0 ; 
   cin >> n >> m ;
   for(ll i=n;i>0;i--)
   {
      ll a = n/i ; 
      ll temp = a*(a-qq) ; 
      temp = temp/tt ; 
      ll j = 2 ; 
      while(1)
      {
         ll t = i*j ; 
         if(t>n){break;}
         temp-=pd[t] ; 
         j++ ; 
      }
      pd[i] = temp ; 
   }
   ll sum = 0 ; 
   for(ll k=2;k<=n;k++)
   {
      //if(pd[k]==zz){continue;}
      ll p = k-qq ; 
      ll e = pd[k] ; 
      ll temp = e/p ;
      if(temp==zz){continue;}
      idx++ ; 
      wr[idx] = k ; 
      ad[idx] = p ; 
      fr[idx] = e/p  ;  
      ll need = m/p ; 
      fr[idx] = min(need,fr[idx]) ;  
      sum+=fr[idx] ; 
      kr[idx] = k ; 
   }
   ll ans = 0 ; 
   for(int i=idx;i>0;i--)
   {
      ll k = kr[i] ; 
      ll f = fr[i] ;
      ll need = m/(k-qq) ;
      f = min(need,f) ; 
      ll sub = f*(k-qq) ; 
      m-=sub ; 
      ans+=(f*wr[i]) ;  
   } 
   if(m>zz){ans=-1;}
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