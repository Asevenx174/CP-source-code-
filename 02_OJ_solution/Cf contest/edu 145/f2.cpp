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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[10] = {0,-1,-1,1,1} ;
int fy[10] = {0,-1,1,1,-1} ; 
int n,m,a,b,aa,bb,ans=0,f=0 ; 
string s ; 
map < pii , bool > lr ; 
void dfs(int i,int j,int d)
{
  if(i==aa && j==bb)
  {
     f = 1 ; 
     return ;
  }
  if(min(i,j)==1 || i==n || j==m)
  {
     if(lr[{i,j}]){return ;}
     lr[{i,j}] = true ; 
  }
  int x = i+fx[d] ; 
  int y = j+fy[d] ; 
  if( !( x<0 || x>n || y<0 || y>m ) )
  {
     dfs(x,y,d) ; return ;
  }
  ans++ ; 
  if(d==1){d=3;}
  else if(d==2){d=4;}
  else if(d==3){d=1;}
  else{d=2;}
  dfs(x,y,d) ; 
}
void solve()
{
   lr.clear() ; 
   f = 0 ; 
   ans = 0 ; 
   cin >> n >> m >> a >> b >> aa >> bb >> s ; 
   int val ; 
   if(s=="UL"){val=1;}
   else if(s=="UR"){val=2;}
   else if(s=="DL"){val=4;}
   else
   {
      val = 3 ; 
   }
   dfs(a,b,val);
   if(f==0){ans=-1;}
   cout << ans << endl ;
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

