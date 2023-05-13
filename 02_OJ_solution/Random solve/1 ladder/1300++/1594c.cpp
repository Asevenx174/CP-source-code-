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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)


using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const int maxx = 3e5+10  ,mod=32768,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< int > prime ;
bool used[maxx+10] ;
int col[maxx+10] ;  
void gen()
{
   used[1] = true ; 
   for(int i=4;i<maxx;i+=2)
   {
      used[i] = true ; 
   }
   for(int i=3;i*i<=maxx;i+=2)
   {
       if(!used[i])
       {
         int j = i+i ; 
         while(j<maxx)
         {
            used[j] = true ; 
            j+=i ; 
         }
       }
   }
   for (int i = 2 ; i < maxx ; ++i)
   {
      if(!used[i]){prime.push_back(i);}
   }
}
void calco(int idx)
{
   for(auto x : prime )
   {
      if(idx==1){break;}
      int sum = 0 ; 
      while(idx%x==0)
      {
         idx = idx/x ; 
         col[x] = true ; 
         sum++ ; 
      }
      col[x] = max(col[x],sum) ; 
   }
   if(idx>1){ max(col[idx],1) ;}
}
int main()
{
   debugMode();
   gen() ; 
   int test ; 
   cin >> test ;
   while(test--)
   {
     ms(col,0) ; 
     int n ; 
     cin >> n ; 
     char c ;
     cin >> c ; 
     string s ;
     cin >> s ;
     int idx = 1 ,f=1 ; 
     for(auto k : s )
     {
        if(c!=k)
        {
           calco(idx) ; 
           f=0 ; 
        }
        idx++ ; 
     }
     int temp = mod ; 
     for(auto x : prime )
     {
        if(!col[x])
        {
            temp = min(temp,x) ; 
        }
        else
        {
            int sum = 0 ; 
            while(col[x]--){sum+=x;}
            temp = min(temp,sum+x) ; 
        }
     }
     if(f==1)
     {
        cout << "0" << endl ; continue ;
     }
     if(temp<=n)
     {
        cout << "1" << endl ;
        cout << temp << endl ;
     }
     else
     {
        cout << "2" << endl ;  
        cout << n-1 << endl ; 
        cout << n << endl ;
     }
   }
   return 0 ;
}