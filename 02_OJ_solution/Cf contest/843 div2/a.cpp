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
string s ; 
string gen(int l,int r)
{
   string ans = "" ; 
   while(l<=r)
   {
      ans+=s[l++] ; 
   }
   return ans ; 
}
bool valid(string a,string b,string c)
{
   if( (a<=b && c<=b) || (b<=a && b<=c) )
   {
      return true ; 
   }
   return false ; 
}
void solve()
{
   cin >> s ;
   int n = s.size() ; 
   int f = 1 ; 
   for (int i = 0; i+2 < n ; ++i)
   {
      for (int j = i+1; j+1 < n ; ++j )
      {
          string a = gen(0,i) ;
          string b = gen(i+1,j);
          string c = gen(j+1,n-1) ;
          if(valid(a,b,c))
          {
             cout << a << " " << b << " " << c << endl ;
             f = 0 ; 
             break ; 
          }  
      }
      if(f==0){break;}
   }
   if(f)
   {
      cout << ":(" << endl ;
   }
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