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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 4e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],pr[maxx+10],val[maxx+10] ; 
ll com(ll n)
{
   ll ans = n*(n+qq) ; 
   ans = ans/tt ; 
   return ans ; 
}
ll comadd(ll s,ll k)
{
   ll h = k/tt ; 
   ll ans = com(s)-com(s-h) ;
   ans = ans*tt ; 
   s-=h ; 
   if(k%tt==qq){ans+=s;} ; 
   return ans ;  
}
ll calco(ll a,ll b,ll k)
{
  if(b>a){swap(a,b);}
  ll add = a-b ; 
  ll ans = 0 ; 
  if(add>=k)
  {
     ans = com(a)-com(a-k) ; 
  }
  else
  {
     ans = com(a)-com(b) ;
     k-=add ; 
     ans+=comadd(b,k) ; 
  }
  return ans ; 
}
ll get(ll l,ll r,ll k)
{
   ll ans = 0 ; 
   if(l+qq<r)
   {
      ans = val[r-1]-val[l] ; 
      k-=(pr[r-1]-pr[l]) ;  
   }
   ans+=calco(ar[l],ar[r],k);
   return ans ; 
}
void solve()
{
   ll x,n ; 
   cin >> n >> x ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   int idx = n+1,pos=1 ; 
   ll temp = n ; 
   while(temp--)
   {
      ar[idx++] = ar[pos++] ; 
   }
   ll sum = 0,l=1,r=2*n,res=0 ; 
   for(int i=1;i<=2*n;i++)
   {
      sum+=ar[i] ; 
      if(sum>x && r==(2*n))
      {
         r = i-1 ;  
      }
      res+=com(ar[i]) ;
      val[i] = res ;  
      pr[i] = sum ;  
   }
   ll fin = 0 ;
   l = 1 ; 
   r = 1 ;  
   while(l<=r && r<=2*n)
   {
      if(l<r)
      {
         temp = get(l,r,x) ;
      }
      else
      {
         temp = com(ar[l])-com(ar[l]-x) ; 
      } 
      //cout << l << " " << r << " " << temp << endl ; 
      fin = max(fin,temp) ; 
      ll f = 1 ; 
      r++ ; 
      while(r<=2*n)
      { 
         ll have = pr[r]-pr[l-1] ; 
         if(have>x){l++;break;}
         r++ ; 
      }  
   }
   cout << fin << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}