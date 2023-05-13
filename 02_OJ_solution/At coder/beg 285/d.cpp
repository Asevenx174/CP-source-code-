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
int prime[maxx+10];
vector < ll > v ;
bool isitprime(ll n)// root n comx
{
    if(n==2){return true;}
    if(n<2 || n%2==0){return false;}
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n%i==0){return false;}
    }
    return true;
}
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
    for(int i=1; i<=n; i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }
}
int main()
{
   debugMode();
   seive(maxx) ; 
   ll test ;
   cin >> test ;
   while(test--)
   {
     ll k ;
     cin >> k ; 
     ll a=0,b=0 ; 
     vector < pii > l,r ;  
     set < int > s ; 
     for(auto x : v )
     {
        ll p = x ; 
        ll val = p*p ; 
        ll q = k/val ;
        ll temp = p*p*q ; 
        if(temp==k)
        {
           r.push_back({p,q}) ; 
           s.insert(q) ; 
        }
        q = x ; 
        p = k/x ;
        p = sqrt(p) ; 
        temp = p*p*q ; 
        if(temp==k)
        {
           l.push_back({p,q}) ;
           s.insert(p) ; 
        }   
     }
     map < int , int > pq ; 
     for(auto x : s )
     {
        if(x<maxx)
        {
            if(prime[x]==0){pq[x]=1;}
        }
        else
        {
            if(isitprime(x))
            {
                pq[x] = 1 ; 
            }
        }
     }

     for(auto x : l)
     {
        if(pq[x.ff]==1)
        {
            a = x.ff ; 
            b = x.ss ; 
        }
     }
     for(auto x : r)
     {
        if(pq[x.ss]==1)
        {
            a = x.ff ; 
            b = x.ss ; 
        }
     }
     cout << a << " " << b << endl ;
   }
   return 0 ;
}