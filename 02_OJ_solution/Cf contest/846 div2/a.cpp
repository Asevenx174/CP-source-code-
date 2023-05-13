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
void solve()
{
   int n,a=0,b=0 ;
   deque < int > dq ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      if(x%2==1){a++;dq.push_front(i+1);}else{b++;dq.push_back(i+1);}
   }
   if(a==0 || (a==2 && n==3) )
   {
      cout << "NO" << endl ; return ; 
   }
   cout << "YES" << endl ;
   if(a==2)
   {
      cout << dq.front() ; 
      int temp = 2 ; 
      while(temp--)
      {
         cout << " " <<  dq.back() ; 
         dq.pop_back() ; 
      }
      cout << endl ;
   }
   else
   {
      int temp = 3 ; 
      while(temp--)
      {
         if(temp<2){cout << " ";}
         cout << dq.front() ; 
         dq.pop_front() ; 
      }
      cout << endl ;
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