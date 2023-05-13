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
const ll maxx = 2e5+10,mod=1010,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,k,ar[maxx+10],f[mod+10],used[mod+10] ; 
vector < int > pq[mod+5] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i <= mod ; ++i)
      {
         used[i] = 0 ; 
         f[i] = 0 ;
         pq[i].clear() ; 
      }
      std:: vector < vector < int > > v ;
      ll n,k ;
      cin >> n >> k ;
      v.resize(k+10) ; 
      for (int i = 0 ; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         ll r = ar[i+1]%k ; 
         pq[r].push_back(ar[i+1]) ; 
         f[r]++ ; 
      }
      for (int i = 0; i < k ; ++i)
      {
         v[i].resize(f[i]+5) ;
         sort(pq[i].begin(),pq[i].end(),greater<int>()) ; 
         auto it = pq[i].begin() ; 
         int idx = 1 ; 
         //cout << i << "->" << endl ;
         while(idx<=f[i])
         {
            //cout << idx << " " << *it << endl ;
            v[i][idx++]=*it ; it++ ; 
         }
      }
      ll ans = 0 ; 
      for(int r=0;r<k;r++)
      {
         int i = r ; 
         while(i>=0)
         {
            int j = r-i ; 
            if(i==j && used[i]+2<=f[i] )
            {
               while(i==j && used[i]+2<=f[i])
               { 
               ll a = v[i][used[i]+1] ; 
               ll b = v[i][used[i]+2] ; 
               ll sum = a+b ; 
               used[i]+=2 ; 
               ans+=(sum/k) ; 
               cout << i << " " << j << endl ;
               cout << a << " " << b << endl ;
               }
            }
            else if(used[i]+1<=f[i] && used[j]+1<=f[j] && i!=j)
            {
               while(used[i]+1<=f[i] && used[j]+1<=f[j])
               {
               used[i]++ ; 
               used[j]++ ; 
               ll a = v[i][used[i]] ; 
               ll b = v[j][used[j]] ; 
               ll sum = a+b ; 
               ans+=(sum/k) ; 
               cout << i << " " << j << endl ;
               cout << a << " " << b << endl ;
               }
            }
            i-- ; 
         }
      }
      cout << ans << endl ; 
   }
   return 0 ;
}