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
int in(char c)
{
   int x = c-96 ; return x ; 
}
char ch(int x)
{
   char c = x+96 ;
   return c ;  
}
map < char ,int > pq ; 
void calco(int num)
{
   int b = n/num ; 
   for(auto p : pq)
   {
      cout << p.ff << " " << p.ss << endl ; 
   }
}
void solve()
{
  cin >> n >> s ;
  for(auto c : s )
  {
     pq[c]++ ; 
  }
  for(int i=1;i<=min(26,n);i++)
  {
    if(n%i==0)
    {
       calco(i) ;
    }
  }
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