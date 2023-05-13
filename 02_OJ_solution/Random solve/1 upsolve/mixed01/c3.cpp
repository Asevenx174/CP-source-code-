#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

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
ll prime[maxx+10],di[maxx+10];
vector < ll > v ;
void seive(ll n)
{
    prime[0]=prime[1]=1;
    for(ll i=4;i<=n;i+=2)
    {
        prime[i]=1;
    }
    for(ll i=3;i*i<=n;i++)
    {
        if(prime[i]==zz)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(prime[i]==zz)
        {
            v.push_back(i);
        }
    }
}
int main()
{
   debugMode();
   seive(maxx) ; 
   for(auto x : v )
   {
      ll temp = x ; 
      while(temp<maxx)
      {
         if(di[temp]==zz)
         {
            di[temp] = x ; 
         }
         temp = temp*x ; 
      }
   }
   ll n,q ;
   cin >> n >> q ;
   while(q--)
   {
      ll a,b,ans=-1 ;
      int h,k ; 
      scanf("%d %d",&h,&k) ; 
      a = h ; 
      b = k ; 
      
      if(a==b)
      {
         ans = 0 ; 
      }
      else if(max(a,b)>n)
      {
         ans = -1 ; 
      }
      else if (prime[a]==zz && prime[b]==zz)
      {
         ll temp = max(a,b)*2LL ; 
         if(a*b<=n)
         {
            ans = 2 ; 
         }
         else if( temp<=n )
         {
            ans = 4 ;
         }
      }
      else if(prime[a]!=zz && prime[b]!=zz)
      {
          ll f = zz ; 
          ll temp = di[a]*di[b] ; 
          ll g = __gcd(a,b) ; 
          if(prime[g]==0){f=g;}
          if(f>zz)
          {
             ans = 2 ; 
          }
          else if(temp<=n)
          {
             ans = 4 ; 
          }
          else
          {
             temp  = max(di[a],di[b])*2LL ; 
             if(temp<=n)
             {
                ans = 6 ;
             }
          }
      }
      else
      {
         if(prime[a]!=zz){swap(a,b);}
         ll d = di[b] ; 
         ll temp = max(a,d)*2LL ; 
         if(b%a==zz)
         {
            ans = 1 ; 
         }
         else if(a*d<=n)
         {
            ans = 3 ; 
         }
         else if (temp<=n)
         {
            ans = 5 ;
         }
      }
      int pq = ans ; 
      printf("%d\n",pq) ;
   }
   return 0 ;
}