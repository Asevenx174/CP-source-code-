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
int n,m,sum[maxx+10] ; 
void solve()
{
   cin >> n >> m ; 
   vector<vector<int>>v( n+5 , vector<int> (m+5));
   int co = 0 ;  
   for(int i=1;i<=n;i++)
   {
      sum[i] = 0 ; 
      for(int j=1;j<=m;j++)
      {
         int x ;
         cin >> x ;
         v[i][j] = x ; 
         co+=x ; 
         sum[i]+=x ; 
      }
   }
   if(co%n!=0)
   {
     cout << "-1" << endl ; return ;
   }
   int p = co/n ; 
   vector < pair < int , pii > > ans ; 
   for(int j=1;j<=m;j++)
   {
      queue < int > a,b ; 
      for(int i=1;i<=n;i++)
      {
         if(sum[i]>p && v[i][j]==1){a.push(i);}
         if(sum[i]<p && v[i][j]==0){b.push(i);}
         if(!a.empty() && !b.empty())
         {
            int x = a.front() ; a.pop() ;
            int y = b.front() ; b.pop() ;
            sum[x]-- ; 
            sum[y]++ ; 
            ans.push_back( {x,{y,j}} ) ; 
         }
      }
   }
   cout << ans.size() << endl ;
   for(auto t : ans)
   {
      cout << t.ff << " " << t.sef << " " << t.ses << endl ;
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