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
string calco(string s)
{
   string ans = "" ; 
   for(int i=0;i+1<s.size();i++)
   {
      ans+=s[i] ; 
   }
   int n = s.size() ; 
   ans=s[n-1]+ans ; 
   return ans ; 
}
int main()
{
   debugMode() ;
   std::vector< string > v ;
   string s ; 
   cin >> s ; 
   string temp = s ; 
   do
   {
      v.push_back(s) ; 
      s = calco(s);  
   }
   while(s!=temp) ; 
   sort(v.begin(),v.end()) ; 
   auto it = v.begin() ; 
   auto lt = v.rbegin() ; 
   cout << *it << endl ; 
   cout << *lt << endl ;
   return 0 ; 
}