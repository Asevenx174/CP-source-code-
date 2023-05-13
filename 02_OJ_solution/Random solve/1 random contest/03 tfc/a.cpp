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
const int imin = 1e9+100;
const ll maxx = 4e5+10,mod=1e9+7,imax=1e18+10;
int lrr[maxx],rrr[maxx],wrr[maxx];
vector < vector < pii > > p(maxx) ;

ll dp[maxx+10] ; 

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

int main()
{
    debugMode();
    map < int ,int > mp ;
    set < int > s ;
    ll n ,m ;
    cin >> n >> m  ;
    for(int i=1;i<=m ;i++)
    {
        ll l,r,w=1;
        cin >> l >> r  ;
        r = l+r-1 ; 
        mp[l];
        mp[r];
        lrr[i]=l ;
        rrr[i]=r ;
        wrr[i]=w;
    }
    int idx = 1 ;
    for(auto & x : mp )
    {
       x.ss = idx++ ;
    }
    for(int i=1;i<=m;i++)
    {
        int r = mp[rrr[i]],l = mp[lrr[i]] , w = wrr[i] ;
        p[r].emplace_back(l,w);
    }
    for(int i=1;i<idx;i++)
    {
        for(auto x : p[i])
        {
            dp[i]=max(dp[i],dp[x.first-1]+x.second);
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout << dp[idx-1] << endl;
    return 0 ;
}