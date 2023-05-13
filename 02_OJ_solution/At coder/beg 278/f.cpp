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
const ll maxx = 30 ,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ans  ; 
map < int ,char > ic ; 
map < char ,int > ci ; 
std::vector < int > p[maxx+5],q[maxx+5],g[maxx+5] ;
bool used[maxx+10] ; 
void dfs(int idx,int par, &set < int > pk)
{
   
}
void solve()
{
   for (int i = 0; i < maxx ; ++i)
   {
      p[i].clear() ; 
      q[i].clear() ; 
      g[i].clear() ; 
   }
   int n ;
   cin >> n ;
   for (int i = 0 ; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      int len = s.size() ; 
      int l = ci[ s[0] ] ; 
      int r = ci[ s[len-1] ] ;  
      p[l].push_back(i+1) ; 
      q[r].push_back(i+1) ; 
   }
   set < int > s ; 
   for(int i=26;i>0;i--)
   {
      for (int j = 0; j < q[i].size() ; ++j )
      {
         for(int k=0;  k< p[i].size() ;k++)
         {
             int a = q[i][j] ; 
             int b = p[i][k] ; 
             if(a==b){continue;}
             g[a].push_back(b) ; 
            // cout << a << " ????? " << b << endl ;
             s.insert(a) ; 
         }
      }
   }
   ans = 0 ; 
   for(auto i : s ) 
   {
      //memset(used,false,sizeof(used)) ; 
      //cout << i << "-->" << endl ; 
      used[i] = true ; 
      set < int > pk ;  
      dfs(i,1,pk) ; 
      used[i] = false ; 
   }
   if(ans)
   {
      cout << "First" << endl ;
   }
   else
   {
      cout << "Second"  << endl ;
   }
}
int main()
{
   debugMode();
   ll idx = 1 ; 
   char ch = 'a' ; 
   while(ch<='z')
   {
      ci[ch] = idx ; 
      ic[idx] = ch ; 
      ch++ ; 
      idx++ ; 
   }
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}