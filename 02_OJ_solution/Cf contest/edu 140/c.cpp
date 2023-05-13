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
const ll maxx = 1e3+10,mod=998244353,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,tr[maxx+10] ; 
void solve()
{
   //memset(ar,zz,sizeof(ar)) ; 
   ll f=1,r=0,l=0 ; 
   cin >> n ; 
   for(int i=1;i<=n;i++)
   {
      for(int j=i;j<=n;j++)
      {
         ll x ;
         cin >> x ; 
         if(x==zz){continue;}
         if(ar[j]!=zz && ar[j]!=x){f=zz;}
         ar[j] = x ; 
      }
   }
   ll a = 0 ; 
   ll b = 0 ;
   for(int i=1;i<=n;i++)
   {
      int x = ar[i] ; if(x==zz){continue;}
      if(x==qq){if(b){f=0;}a=1;l=i;}else{b=1;if(r==zz){r=i;}}
   }
   if(f==zz){cout << "0" << endl ; return ;}
   if(l==zz && r==zz)
   {
      cout << tr[n] << endl ;
      return ;
   }
   else if(l!=zz && r==zz)
   {
      ll ans = (tt*tr[n-l])%mod ; 
      cout << ans << endl ;
      return ;
   }
   else if(l==zz && r!=zz)
   {
      ll ans = (tr[r]-tt+mod)%mod ; 
      ans = ans*tr[n-r] ;   
      return ;
   }
   // 1...l....r...n
   ll ans = (tr[r-l]-qq+mod)%mod ; 
   ans = (ans*tt*tr[n-r])%mod ;  ; 
   cout << ans << endl ;
}
int main()
{
   debugMode();
   tr[0] = qq ; 
   for(ll i=1;i<=100LL;i++)
   {
      tr[i] = (tr[i-1]*tt)%mod ; 
   }
   ll test = 1 ; 
   //cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}