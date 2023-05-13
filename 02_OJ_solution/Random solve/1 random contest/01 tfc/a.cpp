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
const ll maxx = 15+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll tr[maxx],n,mul[maxx],a,b ; 
int getval()
{
   ll val = 0 ; 
   ll p = n ; 
   ll idx = 1 ; 
   while(tr[idx]==0 && idx<=n)
   {
      idx++ ; 
      p-- ;
   }
   while(idx<=n)
   {
      val+=(tr[idx]*mul[p]) ;
      p-- ; 
      idx++ ; 
   }
   return val ; 
}

std::vector < int > k ;
bool used[15] ; 
ll best = -1 ; 
void gen(ll idx)
{
   if(idx>n)
   {
      ll ans = 0 ;
      ll p = n ; 
      for(auto x : k )
      {
         ans+=((ll)x*mul[p]) ; 
         p-- ; 
      }
      //cout << ans << endl ;
      ll d = abs(a-ans) ; 
      ll val = min(d,mul[n+1]-d) ; 
      if(val>best)
      {
         best = val ; 
         b = ans ; 
      }
      else if(val==best && ans<b )
      {
         b = ans ; 
      }
      return ; 
   }
   for (int i = 0; i < 10 ; ++i)
   {
      if(used[i]){continue;}
      used[i] = true ; 
      k.push_back(i) ; 
      gen(idx+1) ; 
      used[i] = false ; 
      k.pop_back() ; 
   }
}
int main()
{
   debugMode();
   ll m = 1 ; 
   for(int i=1;i<=12;i++)
   {
      mul[i] = m ; 
      m = m*10LL ; 
   }
   string s ;
   cin >> s ;
   n = s.size() ; 
   int idx = 1 ; 
   for(auto c : s )
   {
      tr[idx++] = c-'0' ; 
   }
   a = getval() ; 
   gen(1) ; 
   ll dig = 1 ;
   ll temp = b ; 
   while(temp>9LL)
   {
      temp = temp/10LL ; 
      dig++ ; 
   }
   if(dig!=n)
   {
      cout << "0" ; 
   }
   cout << b << endl ;
   return 0 ;
}