#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,p[maxx+10],pos ,r ; 
std::vector< int > g[maxx+10],ans[maxx+10],le ;
int q[maxx+10],id ; 
bool used[maxx+10],mark[maxx+10] ; 
void dfs(int f)
{
   used[f] = true ; 
   for(auto c : g[f] )
   {
      if(used[c]){continue;}
      p[c] = f ; 
      dfs(c);
   }
   if(r!=f && g[f].size()==1)
   {
       le.push_back(f) ; 
   }
}
int main()
{
   debugMode();
   //ios::sync_with_stdio(0); cin.tie(0); 
   ll test ;
   cin >> test ;
   while(test--)
   {
      le.clear() ; 
      id = 1 ; 
      lp(i,0,maxx)
      {
         g[i].clear() ; 
         used[i]=false ; 
         mark[i]=false ; 
      }
      pos = 0 ; 
      scanf("%d",&n) ;
      lp(i,1,n)
      {
         //cin >> p[i] ; 
         int x ; 
         scanf("%d",&x) ;
         p[i] = x ; 
      }
      if(n==1)
      {
         cout << "1" << endl ; 
         cout << "1" << endl ; 
         cout << "1" << endl ; 
         continue ; 
      }
      lp(c,1,n)
      {
         int f = p[c] ;
         //cout << f << " " << c << endl ;
         if(f!=c)
         {
            g[f].push_back(c) ; 
            g[c].push_back(f) ; 
         }
         else
         {
            r = f ; 
         }
      }
      dfs(r) ; 
      cout << le.size() << endl ; 
      for(auto l : le )
      {
         stack < int > s ; 
         s.push(l) ; 
         mark[l] = true ; 
         while( mark[p[l]]==false )
         {
            l = p[l] ; 
            s.push(l) ; 
            mark[l] = true ;
            if(l==r){break;}
         }
         cout << s.size() << endl ; 
         int gap = 0 ; 
         while(!s.empty())
         {
            if(gap==1){ printf(" ") ; }
            gap = 1 ; 
            int x = s.top() ; 
            printf("%d",x) ;
            s.pop() ; 
         }
         printf("\n") ;
      }
   }
   return 0 ;
}