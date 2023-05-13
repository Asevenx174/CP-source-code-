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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
map < pii , bool > used ;  
std::vector< ll > v ;
ll ar[maxx+10] ; 
ll npr(ll n,ll r)
{
   if(r>n){return 0;}
   ll ans = 1 ; 
   for (int i = 0; i < r ; ++i)
   {
      ans = ans*(n-i) ; 
   }
   return ans ; 
}
ll calco(ll m)
{
   //cout << m << "->" << endl ;
   ll sum = 0 ; 
   for(int i=2;i*i<=m;i++)
   {
      if(m%i==0)
      {
         int j = m/i ; 
         if( used[{i,j}] || j==1 ){continue;}
        // cout << i << "----" << j << endl ;
         if(i==j)
         {
            if(ar[i]<2){continue;}
            ll a = npr(ar[i],2) ; 
            auto it = lower_bound(v.begin(),v.end(),m) ; 
            auto lt = lower_bound(v.begin(),v.end(),m+i);
            ll add = lt-it ; 
            sum+=(a*add) ; 
            used[{i,j}] = true ; 
         }
         else
         {
            ll a = ar[i] ; 
            ll b = ar[j] ; 
            auto it = lower_bound(v.begin(),v.end(),m) ; 
            auto lt = lower_bound(v.begin(),v.end(),m+i) ;
            ll add = lt-it ; 
            sum+=(a*b*add) ; 
            lt = lower_bound(v.begin(),v.end(),m+j) ;
            add = lt-it ; 
            sum+=(a*b*add) ; 
            used[{i,j}] = true ; 
            used[{j,i}] = true ; 
         }
      }
   }
   cout << m << " ans  " << sum << endl ;
   return sum ; 
}
int main()
{
   debugMode();
   ll co = 0 ,n ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      if(x>1)
      {
         ar[x]++ ; 
         v.push_back(x) ; 
      }
      else{co++;}
   }
   ll ans =  npr(co,3) ;
   for(int i=2;i<maxx;i++)
   {
      ll oc = ar[i] ; 
      if(oc>1)
      {
         ans+=(npr(oc,2)*co) ; 
      }
   }
   sort(v.begin(),v.end()) ; 
   for(auto x : v )
   {
      ans+=calco(x) ; 
   }
   cout << ans << endl ;
   return 0 ;
}