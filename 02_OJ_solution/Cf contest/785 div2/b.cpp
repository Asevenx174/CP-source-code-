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
int dp[maxx+10][50] ;
int main()
{
   debugMode();
   char cc = 'a' ; 
   map < char ,int > pq ; 
   int idx = 1 ; 
   while(cc<='z')
   {
      pq[cc++]=idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      vector < bool > used(55,false) ; 
      int ans = 1 ; 
      std::vector< int > g[50] ;
      string s ;
      cin >> s ;
      int n = s.size() ; 
      idx = 1 ; 
      set < int > pk ; 
      int fin = 1 ; 
      for(auto c : s )
      {
          int y = pq[c] ; 
          used[y] = true ; 
          pk.insert(y) ; 
          g[y].push_back(idx) ; 
          for(int i=1;i<=26;i++)
          {
             int add = y==i ? 1 : 0 ; 
             dp[idx][i] = add ; 
             dp[idx][i]+=dp[idx-1][i] ; 
          }
          if(idx>1)
          {
             if(s[idx-1]==s[idx-2]){fin=0;}
          }
          idx++ ; 
      }
      int flag = 0 ; 
      if(pk.size()!=1){flag=1;}
      else
      {
         cout << "YES" << endl ; 
         continue ; 
      }
      if(fin==0 && flag==1)
      {
         cout << "NO" << endl ; 
         continue ; 
      }
      for(int i=1;i<=26;i++)
      {
         for(int j=1;j<g[i].size();j++)
         {
             
             int a = 0 ; 
             int b = mod ; 
             int x = g[i][j-1] ;
             int z = g[i][j] ;
             for(int k=1;k<=26;k++)
             {
                int temp = dp[z][k]-dp[x-1][k] ; 
                if(!used[k]){continue ;}
                a = max(a,temp) ; 
                b = min(b,temp) ;  
             }
             if(abs(a-b)>1){ans=0;}


             if(j==1){continue;}
             a = 0 ; 
             b = mod ; 
             x = g[i][j-2] ;
             int y = g[i][j-1] ; 
             z = g[i][j] ; 
             for(int k=1;k<=26;k++)
             {
                int temp = dp[z][k]-dp[x-1][k] ; 
                if(!used[k]){continue ;}
                a = max(a,temp) ; 
                b = min(b,temp) ;  
             }
             if(abs(a-b)>1){ans=0;}
         }
      }
      if(ans==1)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }

   }
   return 0 ;
}