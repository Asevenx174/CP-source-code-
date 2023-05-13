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
const ll maxx = 5e5+10,mod=1e7+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int br[maxx+10] ; 
int prime[mod+5];
vector < int > v ;
void seive(int n)
{
    //memset(prime,0,sizeof(prime));
    int x = sqrt(n);
    prime[0]=prime[1]=1;
    for(int i=4;i<=n;i+=2)
    {
        prime[i]=1;
    }
    for(int i=3;i<=x;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }
}
set < int > used[5] ; 
void fact(int n,int idx)
{
   //cout << n << " " << idx << endl ;
   auto it = v.begin() ;
   do
   {
      int x = *it ; 
      //cout << x << " " << n << endl ; 
      if(x>n){break;}
      int f = 0 ;
      while(n%x==0)
      {
         n = n/x ; 
         f = 1 ; 
      }
      if(f)
      {
         //cout << idx << " " << x << endl ;
         used[idx].insert(x) ; 
      }
      it++ ; 
   }
   while(n>1 && it!=v.end()) ; 
   //cout << n << endl ;
} 
bool check()
{
   ///return true ; 
   auto lt = used[2].begin() ; 
   auto it = used[1].begin() ; 
   while(lt!=used[2].end())
   {
      int x = *lt ; 
      int y = 0 ; 
      while(it!=used[1].end())
      {
         y = *it ; 
         if(x==y){break;}
         it++ ; 
      }
      //cout << x << " " << y << endl ;
      if(x!=y){return false;}
      lt++ ; 
   }
   return true ; 
}
int pos = 1 ; 
void solve()
{
   //cout << "YES" << endl ;
   used[1].clear() ;
   used[2].clear() ; 
   int n,g1=0,g2=0 ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      fact(x,1) ; 
      ar[i+1] = x ; 
      if(g1==0)
      {
         g1 = x ; 
      }
      else 
      {
         g1 = __gcd(x,g1) ; 
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      fact(x,2) ; 
      br[i+1] = x ; 
      if(g2==0)
      {
         g2 = x ; 
      }
      else 
      {
         g2 = __gcd(x,g2) ; 
      }
   }
   //cout << "YES?" << endl ;
   int div = __gcd(g1,g2) ; 
   //cout << g1 << " " << g2 << endl ; 
   cout << "Case " << pos++ << ": " ; 
   int f=1,g=1 ; 
   if(!check())
   {
      //cout << "YES" << endl ;
      cout << "No No" << endl ;
      return ;
   }
  // cout << "YES" << endl ;
   for (int i = 0; i < n ; ++i)
   {
      int x = ar[i+1] ; 
      int y = br[i+1] ;
      while(div>1 && x%div==0 && x>0)
      {
         x = x/div ; 
      }
      while(div>1 && y%div==0 && y>0)
      {
         y = y/div ; 
      }
      if(x!=y){g=0;}
   }
   cout << "Yes " ; 
   if(g)
   {
      cout << "Yes" << endl ;
   } 
   else
   {
      cout << "No" << endl ;
   }
}
int main()
{
   debugMode();
   //cout << "yes" << endl ;
   seive(maxx) ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}