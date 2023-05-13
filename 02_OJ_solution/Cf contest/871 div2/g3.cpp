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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int pr[maxx+10],last,lvl ; 
ll fin[maxx+10],up[maxx+10] ; 
int getfirst(int x)
{
  int a=0,b=last,ans=0 ; 
  while(a<=b)
  {
    int m = (a+b)/2 ; 
    if(pr[m]>x)
    {
      b = m-1 ; 
    }
    else
    {
      a = m+1 ;
      ans = m ; 
    }
  }
  return ans ; 
}
void add(int x)
{
  int f = pr[lvl] ;   
  if((x-lvl)!=f)
  {
     up[x] = up[x-lvl]+((ll)x*x) ;  
     fin[x] = up[x] ;  
  }
  else
  {
     up[x] = ((ll)x*x) ; 
     fin[x] = up[x] ; 
  }
  if(x!=f)
  { 
     fin[x]+=fin[x-lvl-1] ; 
  }
}  
void ini()
{
  int x = 1 ; 
  pr[0] = 1 ; 
  int l=1 ; 
  while(x+l<=maxx)
  {
    x+=l ;
    pr[l] = x ; 
    last = l ; 
    l++ ;  
  }
  up[1] = 1 ; 
  fin[1] = 1 ; 
  int temp = 2 ; 
  int prev = 1 ; 
  lvl = 1 ; 
  while(1)
  {
    int co = temp ; 
    while(co-- && prev<maxx)
    {
       prev++ ;   
       add(prev) ; 
    }
    if(prev>=maxx){break;}
    temp++ ; 
    lvl++ ; 
  }
}
void solve()
{
  int n ;
  cin >> n ;
  cout << fin[n] << endl ; 
  //cout << up[2] << " " << up[3] << " " << up[4] << " " << up[5] << endl ;
}
int main()
{
   debugMode();
   ini() ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}