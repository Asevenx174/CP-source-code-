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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}


string getstr(ll x)
{
   string s = "" ; 
   while(x>9LL)
   {
      ll y = x%10 ; 
      char c = y+'0' ; 
      s+=c ;  
      x = x/10ll ; 
   }
   char c = x+'0' ; 
   s+=c ; 
   reverse(s.begin(),s.end()) ; 
   return s ; 
}
ll getint(string s)
{
   ll len = s.size(),sum=0,idx=1 ; 
   while(len--)
   {
      ll x = s[len]-'0' ; 
      sum+=(x*idx) ; 
      idx = idx*10ll ; 
   }
   return sum ;
}

map < pair < ll,ll > , bool > dp ; 
ll n,ans=mod ; 
void gen(ll num,ll op )
{
   if(dp[{num,op}]){ return ; }
   string s = getstr(num) ; 
   if(s.size()>n){ return ; }
   if(s.size()==n)
   {
      ans = min(ans,op) ; 
      return ; 
   }
   set < ll > d ; 
   for(auto c : s)
   {
      int x = c-'0' ; 
      d.insert(x) ; 
   }
   for(auto x : d )
   {
      if(x>1)
      {
         ll temp = num*x ; 
         gen(temp,op+1) ; 
      }
   }
   dp[{num,op}] = true ; 
}
int main()
{
   debugMode();
   cin >> n ; 
   string s ; 
   cin >> s ;
   if(s.size()==n)
   {
      ans = 0 ; 
   }
   else if(s.size()>n)
   {
      ans = -1 ; 
   }
   else
   {
      gen(getint(s),0);
   }
   if(ans==mod){ans=-1;}
   cout << ans << endl ;
   return 0 ;
}