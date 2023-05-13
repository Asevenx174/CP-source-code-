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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int prime[maxx+10],ar[maxx+10],val[maxx+10];
vector < int > v,pq[maxx+10] ;
bool used[maxx+10] ; 
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
void solve()
{
   for (int i = 0; i < maxx ; ++i)
   {
      pq[i].clear() ; 
      used[i] = false ; 
   }
   int best = 0 ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i] ; 
      best = max(best,ar[i]) ; 
   }

   int a,b ;
   cin >> a >> b ; 
   val[b] = mod ; 
   val[a] = a ; 
   for(auto x : v )
   {
      int q = 1 ; 
      while(1)
      {
         int temp = q*x ; 
         if(temp>best){break;}
         pq[temp].push_back(x) ; 
         pq[x].push_back(temp) ; 
         q++ ; 
      }
   }
   queue < int > q ;
   q.push(a) ; 
   while(!q.empty())
   {
      int u = q.front() ; 
      q.pop() ; 
      for(auto x : pq[u])
      {
         if(used[x]){continue;}
         q.push(x) ; 
         used[x] = true ; 
         val[x] = u ;   
      }
   }
   if(val[b]==mod)
   {
      cout << "-1" << endl ; 
   }
   else
   {
      vector < int > ans ; 
      while(val[b]!=b)
      {
         ans.push_back(b) ; 
         b = val[b] ; 
      }
      ans.push_back(a) ;
      cout << ans.size() << endl ;
      int idx = 0 ; 
      for(auto it = ans.rbegin() ; it!=ans.rend() ; it++)
      {
          if(idx)
          {
            cout << " " ; 
          }
          cout << *it ;
          idx = 1 ; 
      }
      cout << endl ; 
   }
}
int main()
{
   debugMode();
   seive(maxx) ; 
   ll test = 1 ; 
   //cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}