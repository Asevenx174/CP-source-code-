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
int get(int x)
{
   int sum = 0 ; 
   while(x>9)
   {
      int d = x%10 ; 
      sum+=d ; 
      x = x/10 ; 
   }
   sum+=x ; 
   return sum ;  
}
void solve()
{
   int n ;
   cin >> n ;
   int sum = get(n) ; 
   int h = sum/2 ; 
   int m = 1 ; 
   int a,b;
   a = n/2 ; 
   b = n-a ; 
   if( abs(get(a)-get(b))<2)
   {
      cout << a << " " << b << endl ; return ;
   }

   a = 0 ; 
   while(h>0)
   {
      int d = min(h,9) ; 
      a+=(d*m) ; 
      m = m*10 ; 
      h-=d ; 
   }
   b = n-a ; 
   cout << a << " " << b << endl ;
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