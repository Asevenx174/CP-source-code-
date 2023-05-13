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
ll fin[maxx+10] ; 
int pr[maxx+10],last=0,lvl ; 
ll val[maxx+10],dr[maxx+10] ; 

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
void summ(int x,int y)
{  
   dr[y] = y+dr[x] ; 
   fin[x]+=fin[y] ; 
}
void add(int x)
{
  int f = pr[lvl] ; 
  if((x-lvl)!=f)
  {
     summ(x,x-lvl) ; 
  }
  if(x!=f)
  {
     //summ(x,x-lvl-1) ; 
     fin[x]+=dr[x] ; 
  }
}
void ini()
{
  dr[1] = 1 ;  
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
  for( ll i=1;i<maxx;i++)
  {
    val[i] = i*i ; 
  }
  fin[1] = 1 ; 
  int temp = 2 ; 
  int prev = 1 ; 
  while(1)
  {
    int co = temp ; 
    while(co-- && prev<maxx)
    {
       prev++ ; 
       add(prev) ; 
       fin[prev]+=(prev*prev) ; 
    }
    if(prev>=maxx){break;}
    temp++ ; 
  }
}
void solve()
{ 
  int n ;
  cin >> n ; 
  cout << fin[n] << endl ;
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