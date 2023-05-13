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
int nr[5] ;
std::vector < int > v[5]; 
void solve()
{
  v[1].clear() ; 
  v[2].clear() ; 
  v[3].clear() ; 
  vector < int > temp ;  
  int a,b,c ;
  cin >> a >> b >> c ; 
  int sum = 0 ; 
  int xx = 0 ; 
  int yy = 0 ; 
  int zz = 0 ; 
  for (int i = 0; i < a ; ++i)
  {
    int x ; 
    cin >> x ;
    sum+=x ; 
    v[1].push_back(x) ; 
    temp.push_back(x) ; 
    xx+=x ; 
  } 
  for (int i = 0; i < b ; ++i)
  {
    int x ; 
    cin >> x ;
    sum+=x ; 
    v[2].push_back(x) ; 
    temp.push_back(x) ;
    yy+=x ; 
  }
  for (int i = 0; i < c ; ++i)
  {
    int x ; 
    cin >> x ;
    sum+=x ; 
    v[3].push_back(x) ; 
    temp.push_back(x) ;
    zz+=x ; 
  }
  sort(temp.begin(),temp.end()) ; 
  sort(v[1].begin(),v[1].end()) ;
  sort(v[2].begin(),v[2].end()) ;
  sort(v[3].begin(),v[3].end()) ; 
  int p = temp[0] ; 
  int q = temp[1] ; 
  int ans = 0 ; 
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
    {
       if(i==j){continue;}
       if(v[i][0]==p && v[j][0]==q)
       {
          ans = max(ans,sum-(p+q)*2) ; break ;  
       }
    }
  }
  ans = max(ans,sum-2*min(xx,min(yy,zz))) ; 
  cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   //cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}