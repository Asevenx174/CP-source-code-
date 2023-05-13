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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int prime[maxx+10],sm[maxx+10];
std::vector < int > v ;
void seive(int n)
{
    memset(prime,0,sizeof(prime));
    int x = sqrt(n);
    prime[0]=prime[1]=1;
    for(int i=4; i<=n; i+=2)
    {
        prime[i]=1;
    }
    for(int i=3; i<=x; i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }
}
bool primefactor(int n,int y) 
{ 
   
    while (n%2 == 0) 
    { 
        if(y%2==0){return true;}
        n = n/2; 
    } 
     
    
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        
        while (n%i == 0) 
        { 
            if(y%i==0){return true;}
            n = n/i; 
        } 
    } 
     
    if (n > 2) 
        {if(y%n==0){return true;}}

    return false ; 
} 
int main()
{
   debugMode();
   seive(maxx) ; 
   int n ;
   cin >> n ;

   for(auto x : v )
   {
      ll temp = x ; 
      while(temp<=n)
      {
         if(sm[temp]==0)
         {
            sm[temp]=x ; 
         }
         temp = temp*x ; 
      } 
   }
   int q ;
   cin >> q ;
   while(q--)
   {
      int a,b,ans=0 ;
      scanf("%d",&a);
      scanf("%d",&b);
      if(prime[a]==0 && prime[b]==0)
      {
         ll temp = (ll)a*b ;
         int pk = max(a,b)*2 ;
         if(pk<=n)
         {  
            ans = 2 ; 
         }
         else
         {
            ans = -1 ; 
         }
      }
      else if(prime[a]==0)
      {
         if(b%a==0)
         {
            ans = 1 ; 
         }
         else
         {
            ll best = sm[b] ; 
            int pk = max(a,sm[b])*2 ; 
            best = best*a ;
            if( pk <= n   )
            {
               ans = 5 ; 
            }
            else{ans=-1;}
         }
      }
      else if (prime[b]==0)
      {
         if(a%b==0)
         {
            ans = 1 ; 
         }
         else
         {
            ll best = sm[a] ; 
            int pk = max(b,sm[a])*2 ; 
            best = best*b ; 
            if(pk<=n)
            {
               ans = 5 ; 
            }
            else
            {
               ans = -1 ; 
            }
         }
      }
      else
      {
         if( primefactor(a,b) || primefactor(b,a) )
         {
            ans = 2 ; 
         }
         else
         {      
            ll temp = sm[a]*sm[b] ; 
            int pk = max(sm[a],sm[b])*2LL ; 
            if(pk<=n)
            {
               ans = 6 ; 
            }
            else
            {
               ans = -1 ; 
            }
         }
      }
      if(a==b)
      {
         ans = 0 ; 
      }
      printf("%d\n",ans);
   }
   return 0 ;
}