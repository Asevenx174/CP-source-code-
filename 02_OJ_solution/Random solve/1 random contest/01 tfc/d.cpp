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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 15,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector < int > k ;
ll n,mul[maxx+5],a,b ; 
string s ; 
bool used[maxx+5] ;
ll getval()
{
   ll p = n ; 
   ll f = 0 ; 
   ll val = 0 ; 
   for(auto c : s )
   {
      ll x = c-'0' ; 
      if(f==0 && x==0){ p--; continue;}
      val += ( x*mul[p] ) ; 
      if(x!=zz){f=1;}
      p-- ; 
   }
   return val ; 
}
ll best = -1 ; 
void gen(ll idx)
{
   if(idx>n)
   {
      ll p = n ; 
      ll f = 0 ; 
      ll val = 0 ; 
      for(auto x : k )
      {
        if(f==0 && x==0){ p--; continue;}
        val += ( x*mul[p] ) ; 
        if(x!=zz){f=1;}
        p-- ; 
      }
      ll d = abs(a-val) ; 
      ll temp = min(d,mul[n+1]-d) ; 
      if(temp>best)
      {
         best = temp ; 
         b = val ; 
      }
      else if(temp==best && val<b)
      {
         b = val ; 
      }
      return ; 
   }
   for (ll i = 0; i < 10 ; ++i)
   {
      if(used[i]){continue;}
      used[i] = true ; 
      k.push_back(i) ; 
      gen(idx+1) ; 
      used[i] = false ; 
      k.pop_back() ; 
   }
}
ll dcal()
{
   ll ans = 1 ; 
   ll temp = b ; 
   while(temp>9LL)
   {
      temp = temp/10LL ; 
      ans++ ; 
   }
   return ans ; 
}
int main()
{
   debugMode();
   ll m = 1 ; 
   for(ll i=1;i<=12;i++)
   {
      mul[i] = m ; 
      m = m*10LL ; 
   }
   cin >> s ;
   n = s.size() ; 
   a = getval() ; 
   gen(1) ; 
   ll dig = dcal() ; 
   if(dig<n)
   {
      cout << "0" ; 
   }
   cout << b << endl ;
   return 0 ;
}