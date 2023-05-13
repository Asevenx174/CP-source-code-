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
int get(string s)
{
   int ar[10] ; 
   for (int i = 0; i < 5 ; ++i)
   {
      ar[i] = s[i]-'0' ; 
   }
   int h = ar[1]+ar[0]*10 ; 
   int m = ar[4]+ar[3]*10 ; 
   m+=(h*60) ; 
   return m ; 
}
string ch(int x)
{
   string ans = "" ; 
   char l,r ; 
   int temp = x%10 ; 
   r = temp+'0' ;  
   if(x<10)
   {
      ans+="0" ;
      ans+=r ; 
   }
   else
   {
      x = x/10 ; 
      l = x+'0' ; 
      ans+=l ; 
      ans+=r ; 
   }
   return ans ; 
}
string format(int m)
{
   int h = m/60 ; 
   h = h%24 ; 
   m = m%60 ; 
   string ans = "" ; 
   ans+=ch(h) ; 
   ans+=":" ; 
   ans+=ch(m) ;
   return ans ; 
}
bool pal(string a)
{
   string b = a ; 
   reverse(b.begin(),b.end());
   if(a==b){ return true ; }
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int co = 0 ; 
      map < string ,bool > used ; 
      string s ;
      int m ;
      cin >> s >> m ; 
      int taken = 0 ; 
      int add = get(s) ; 
      int pk = 1500 ; 
      while( pk-- )
      {   
          taken+=m ; 
          int sum = taken+add ; 
          string ans = format(sum) ; 
          //cout << ans << endl ;
          if(!used[ans])
          {
            used[ans] = true ; 
            if(pal(ans))
            {
               co++ ; 
            }
          }
      }
      if(!used[s])
          {
            used[s] = true ; 
            if(pal(s))
            {
               co++ ; 
            }
          }
      cout << co << endl ;
   }
   return 0 ;
}