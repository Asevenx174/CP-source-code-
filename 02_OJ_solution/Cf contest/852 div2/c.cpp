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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,ar[maxx+10] ; 
void solve()
{
   std::vector < int > v ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      v.push_back(ar[i+1]) ; 
   }
   sort(v.begin(),v.end()) ; 
   deque < int > dq ; 
   for(auto x : v)
   {
      dq.push_back(x) ; 
   }
   int l = 1 ; 
   int r = n ; 
   while(l<=r)
   {
      int f = 1 ; 
      if(ar[l]==dq.front())
      {
        f = 0 ; 
        l++ ; 
        dq.pop_front() ; 
      }
      else if(ar[l]==dq.back())
      {
        f = 0 ; 
        l++ ; 
        dq.pop_back() ;
      }
      if(ar[r]==dq.back())
      {
        f = 0 ; 
        r-- ; 
        dq.pop_back() ;
      }
      else if(ar[r]==dq.front())
      {
        f = 0 ; 
        r-- ; 
        dq.pop_front() ;
      }
      if(f)
      {
         break ; 
      }
   }
   if(l<=r)
   {
      cout << l << " " << r << endl ;
   }
   else
   {
      cout << "-1" << endl ;
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