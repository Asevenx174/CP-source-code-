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
int fx[5] = {0,0,-1} ; 
int fy[5] = {0,1,0} ; 
void solve()
{
   int p=0,q=0 ; 
   int n,m ;
   scanf("%d %d",&n,&m) ; 
   int temp = 3 ; 
   int x = 2 ; 
   int y = m-1 ; 
   int f = 0 ; 
   int lr=0,ud=0 ;
   for (int i = 0; i < 3 ; ++i)
   {
      int a = x+fx[i] ; 
      int b = y+fy[i] ; 
      if(min(n,m)==1){a=1,b=1;}

      printf("? %d %d\n",a,b) ; 
      fflush(stdout); 

      int ans ;
      scanf("%d",&ans) ; 
      if(ans==0)
      {
          if(p==0)
          {
            p = a ; 
            q = b ; 
          }
          //printf("! %d %d\n",a,b);
         // fflush(stdout) ; 

          //return ;
      }
      else if(i==0)
      {
         f = ans ; 
         if(n==1)
         {
            x = 1 ; 
            if(b+ans<=m)
            {
               y = b+ans ; 
            }
            else
            {
               y = b-ans ; 
            }
            //printf("! %d %d\n",x,y);
           // fflush(stdout) ; 
           if(p==0)
          {
            p = x ; 
            q = y ; 
          }
          //return ;
         }
         else if(m==1)
         {
            y = 1 ; 
            if(a+ans<=n)
            {
               x = a+ans ; 
            }
            else
            {
               x = a-ans ; 
            }
           // printf("! %d %d\n",x,y);
            //fflush(stdout) ; 
              if(p==0)
          {
            p = x ; 
            q = y ; 
          }
          //return ;
         }
      }
      else if(i==1)
      {
         if(f<ans)
         {
            lr = 0 ; 
         }
         else
         {
            lr = 1 ; 
         }
      }
      else
      {
         if(f<ans)
         {
            ud=1 ; 
         }
         else
         {
            ud=0 ; 
         }
      }
   }
   if(lr==0 && ud==0)
   {
      int op = min(y-1,f) ; 
      y-=op ; 
      f-=op ; 
      x-=op ;  
   }
   else if(lr==0 && ud==1)
   {
      int op = min(y-1,f) ; 
      y-=op ; 
      f-=op ;  
      x+=f ; 
   }
   else if(lr==1 && ud==0)
   {
      int op = min(m-y,f) ; 
      y+=op ; 
      f-=op ; 
      x-=f ; 
   }
   else
   {
      int op = min(m-y,f) ; 
      y+=op ; 
      f-=op ;  
      x+=f ; 
   }
   if(p==0)
   {
            p = x ; 
            q = y ; 
   }
   printf("! %d %d\n",p,q);
   fflush(stdout) ; 
}
int main()
{
   debugMode();
   int test = 1 ; 
   scanf("%d",&test) ;  
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}