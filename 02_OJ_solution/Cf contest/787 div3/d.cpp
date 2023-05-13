#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x)              printf("%d\n",(x))
#define PP(x,y)           printf("%d %d\n",x,y)

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
int p[maxx+10],n,son[maxx+10] ;
bool used[maxx+10] ;  
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
       std::vector< vector < int > > path ;
       ms(son,0);  
       ms(used,false) ; 
       int r = 0  ; 
       S(n);
       lp(i,1,n)
       {
         S(p[i]);
         if(i==p[i]){r=i;}
         son[p[i]]++ ; 
       }
       if(n==1)
       {
         P(1) ;
         P(1) ;
         P(1) ;
         continue ; 
       }
       std::vector < int > l ; 
       lp(i,1,n)
       {
          if(son[i]==0)
          { 
             l.push_back(i) ; 
          }
       }
       P(l.size());
       for(auto u : l)
       {
          std::vector < int > temp ;
          temp.push_back(u) ; 
          used[u] = true ; 
          while(p[u]!=u)
          {
             u = p[u] ; 
             if(used[u]){ break ; }
             temp.push_back(u) ; 
             used[u]=true ; 
          }
          path.push_back(temp) ; 
       }
       for(auto v : path )
       {
          P(v.size()) ; 
          int f = 0 ; 
          for(auto it = v.rbegin();it!=v.rend();it++)
          {
             if(f==1){ printf(" ") ;}
             f = 1 ; 
             int x = *it ; 
             printf("%d",x) ;
          }
          printf("\n") ; 
       }
   }
   return 0 ;
}