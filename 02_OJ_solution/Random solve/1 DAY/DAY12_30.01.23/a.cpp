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
const ll maxx = 6e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,s,e,par[maxx+10] ; 
std::vector < int > g[maxx+5],dis(maxx) ;
bool used[maxx+10] ;
void con(int i,int j)
{
   g[i].push_back(j) ; 
   g[j].push_back(i) ; 
} 
void solve()
{
  cin >> n ;
  for (int i = 0; i <= maxx; ++i)
  {
     g[i].clear() ; 
     dis[i] = mod ; 
     used[i] = false ; 
  }
  int idx = 1 ; 
  for (int i = 0; i < n ; ++i)
  {
     int x ;
     cin >> x ; 
     ar[i+1] = x ;
     for(int j=2;j*j<=x;j++)
     {
        if(x%j!=0){continue;}
        while( (x%j)==0 )
        {
          x = x/j ; 
        }
        //cout << i+1 << " " << n+j << endl ;  
        con(i+1,n+j) ; 
     }
     if(x>1)
     {
        con(i+1,n+x) ; 
     }
  }
  cin >> s >> e ; 
  if(s==e)
  {
      cout << "1" << endl << s << endl ; return ;
  }
  else if(ar[s]==ar[e])
  {
     if(ar[s]==1)
     {
        cout << "-1" << endl ; return ; 
     } 
     else
     {
        cout << "2" << endl << s << " " << e << endl ; return ;
     }
  }
  queue < int > q ; 
  q.push(s) ; 
  dis[s] = 0 ; 
  par[e] = mod ; 
  while(!q.empty())
  {
     int u = q.front() ; q.pop() ; 
     if(used[u]){continue;}
     used[u] = true ; 
     for(auto v : g[u])
     {
        if(dis[v]>dis[u]+1)
        {
          dis[v] = dis[u]+1 ; 
          par[v] = u ; 
          q.push(v) ; 
        }
     }
  }
  if(par[e]==mod)
  {
    cout << "-1" << endl ; return ; 
  }
  //cout << "yes" << endl ; 
  vector < int > ans ; 
  while(e!=s)
  {
     if(e<=n){ans.push_back(e);} 
     e = par[e] ; 
  }
  ans.push_back(s) ; 
  reverse(ans.begin(),ans.end()) ; 
  cout << ans.size() << endl ; 
  for (int i = 0; i < ans.size() ; ++i)
  {
     if(i>0){cout << " " ;}
     cout << ans[i] ; 
  }
  cout << endl ; 
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