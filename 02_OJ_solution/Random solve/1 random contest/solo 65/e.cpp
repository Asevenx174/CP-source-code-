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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string sr[10010] ; 
int main()
{
   debugMode();
   int n,a=0,b=0,ba=0 ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      sr[i] = s ; 
      int l=0,r=(int)s.size()-1 ; 
      if(s[l]=='B' && s[r]=='A')
      {
         ba++ ; 
      }
      else if(s[l]=='B')
      {
         b++ ; 
      }
      else if(s[r]=='A')
      {
         a++ ; 
      }
   }
   string s = "" ; 
   if(a>0)
   {
      a-- ; 
      s+="xA" ; 
   }
   while(ba--)
   {
      s+="BxA" ; 
   }
   if(b>0)
   {
      b-- ; 
      s+="Bx" ; 
   }
   while(min(a,b)>0)
   {
      s+="xABx" ; 
      a-- ; 
      b-- ; 
   }
   sr[n] = s ; 
   ll ans = 0 ; 
   //cout << s << endl ;
   for (int i = 0; i <= n ; ++i)
   {
      for(int j=1;j<sr[i].size();j++)
      {
         if(sr[i][j-1]=='A' && sr[i][j]=='B'){ans++;}
      }
   }
   cout << ans << endl ;
   return 0 ;
}