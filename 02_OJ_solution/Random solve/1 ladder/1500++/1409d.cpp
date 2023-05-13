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
int calco(string s)
{
   int sum = 0  ;
   for(auto c : s )
   {
      int x = c-'0' ; 
      sum+=x ; 
   }
   return sum ; 
}
ll con(string s)
{
   string temp = "" ; 
   int f = 0 ; 
   for(auto c : s )
   {
      if(c=='0' && f==0){continue;}
      f=1 ; 
      temp+=c ; 
   }
   reverse(temp.begin(),temp.end()) ; 
   ll sum = 0,mul=1 ;
   for(auto c : temp )
   {
      ll x = c-'0' ; 
      x = x*mul ; 
      mul = mul*10 ; 
      sum+=x ; 
   }
   return sum ; 
}
string change(string s)
{
   string r = s ; 
   reverse(r.begin(),r.end()) ; 
   int f = 0 ; 
   string ans = "" ; 
   for( int i=0;i<r.size();i++)
   {
       char c = r[i] ; 
       if(c!='0' && f==0)
       {
         f = 1 ; 
         ans+='0' ; 
         while(i+1<r.size())
         {
            i++;
            c = r[i] ; 
            int x = c-'0' ;
            x++ ; 
            if(x<10)
            {
               c = x+'0' ; 
               ans+=c ; 
               break ; 
            }
            else
            {
               ans+='0' ; 
            }
         }
       }
       else
       {
         ans+=c ; 
       }
   }
   reverse(ans.begin(),ans.end()) ; 
   return ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      string s ;
      cin >> s ;
      ll first = con(s) ; 
      int k ; 
      cin >> k ;
      s = '0'+s ; 
      std::vector< string > v ;
      v.push_back(s) ; 
      while(1)
      {
         s = change(s) ; 
         v.push_back(s) ; 
         int x = calco(s) ; 
         if(x==1){break;}
      }
      ll n = 0  ; 
      string temp  ; 
      for(auto x : v )
      {
         temp = x  ; 
         ll sum = calco(x) ; 
         if(sum<=k)
         {
           break ; 
         } 
      }
      n = con(temp) ; 
      n = n-first ; 
      cout << n << endl ;
   }
   return 0 ;
}