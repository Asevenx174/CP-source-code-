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
string s="" ; 
void ini()
{
   for(int i=1;i<200;i++) 
   {
      if(i%15==0)
      {
         s+="FB" ; 
      }
      else if(i%5==0)
      {
         s+="B" ; 
      }
      else if(i%3==0)
      {
         s+="F" ;
      }
   }
}
bool check(string k)
{
   //s = "abcbdef" ; 
   int n = k.size() ; 
   for (int i = 0; i+n <= s.size() ; ++i)
   {
      string temp = s.substr(i,n) ;
      //cout << temp << endl ;
      if(temp==k){return true;} 
   }
   return false ; 
}
void solve()
{ 
   int n ;
   cin >> n ; 
   string k ;
   cin >> k ;
   if(check(k))
   {
      cout << "YES" << endl ;
   }
   else
   {
      cout << "NO" << endl ;
   }
}
int main()
{
   debugMode();
   ini() ; 
   //cout << s << endl ;
   //bool temp = check("abc") ; 
   //return 0 ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}