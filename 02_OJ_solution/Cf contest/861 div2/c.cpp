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
typedef  long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 25+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll lr[maxx+10],rr[maxx+10],n,m,tr[maxx+10],f ; 
void sett()
{
   for (int i = 0; i < n ; ++i)
   {
      tr[i+1] = lr[i+1] ; 
   }
}
void con(string s,ll idx)
{
   ll i = 1 ; 
   for(auto c : s)
   {
      ll x = c-'0' ; 
      if(idx==1)
      {
         lr[i] = x ; 
        // cout << i << " " << x << endl ;
      }
      else
      {
         rr[i] = x ; 
      }
     // cout << x ; 
      i++ ; 
   }
   //cout << endl ;
}
ll getval(ll a,ll b,ll idx)
{
   ll mul = 1 ; 
   ll ans = 0 ; 
   while(a<=b)
   {
      ll x = 0 ; 
      if(idx==1)
      {
         x=lr[b];
         //cout << b << " ?? " <<  x << endl  ;
      }
      else if (idx==2)
      {
         x=rr[b];
      }
      else
      {
         x=tr[b];
      }
      x = x*mul ; 
      ans+=x ; 
      mul = mul*10LL ; 
      b-- ; 
   }
  // cout << endl ; 
   return ans ; 
}
ll calco(ll l,ll r)
{
   sett() ; 
   ll rem = 0 ; 
   for(int i=n;i>0;i--)
   {
      ll x = tr[i]+rem ;
      rem = 0 ;  
      if(x==10LL)
      {
         tr[i] = 0 ; 
         rem = 1 ; 
      }
      else if(x>r)
      {
         tr[i] = 0 ; 
         rem = 1 ;  
      }
      else
      {
         tr[i] = x ; 
      }
   }
   ll a = 1 ; 
   ll b = n ; 
   if(rem>zz)
   {
      tr[0] = rem ;
      a = 0 ;   
   }
   for (int i = a ; i <=b  ; ++i)
   {
      tr[i] = max(l,tr[i]) ; 
   }
   f = a ; 
   ll val = getval(a,b,3) ;
   return val ;  
}
void solve()
{
   string a,b ;
   cin >> a >> b ; 
   n = a.size() ; 
   m = b.size() ; 
   con(a,1) ;
   con(b,2) ; 
   ll p = getval(1,n,1) ; 
   ll q = getval(1,m,2) ; 
   //cout << p << " " << q << endl ;
   ll dis = mod ,ans = 0 ; 
   for(int i=0;i<=9;i++)
   {
      for(int j=max(1,i);j<=9;j++)
      {
         ll d = j-i ; 
         ll temp = calco(i,j) ;
         if(temp>=p && temp<=q && d<=dis)
         {
            dis = d ; 
            ans = temp ; 
            //cout << temp << " " << dis << " " << i << " " << j << endl ;
         } 
      }
   }
   //cout << ans << " " << dis <<  endl ;
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