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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n ; 
string s ;
bool used[maxx+10] ; 
string gets(int i,int j)
{
   j = min(j,(int)s.size()-1) ; 
   string temp = "" ; 
   int idx = i ; 
   while(idx<=j)
   {
      temp+=s[idx] ; 
      idx++ ; 
   }
   return temp ; 
}
int lr,rr ; 
int calco() 
{
   int best = 0 ; 
   for (int i = 0; i < s.size() ; ++i)
   {
      for(int j=i+1;j<s.size();j++)
      {
         int len = j-i+1 ; 
         int add = j-i ; 
         string a = gets(i,j) ; 
         string b = gets(j+1,j+1+add) ; 
         if(a==b && best<len)
         {
            best = len ;
            lr = i ; 
            rr = j ; 
         }
      }
   }
   return best ; 
}
void news()
{
   string temp = "" ; 
   for (int i = 0; i < s.size() ; ++i)
   {
      if(lr<=i && i<=rr){continue;}
      temp+=s[i] ; 
   }
   s = temp ; 
}
void solve()
{
   cin >> n >> s ; 
   int ans = 0 ; 
   while(1)
   {
      int val = calco() ;
      if(val==0){break;}
      news() ; 
      ans++ ; 
   }
   ans+=s.size() ; 
   cout << ans << endl ;
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