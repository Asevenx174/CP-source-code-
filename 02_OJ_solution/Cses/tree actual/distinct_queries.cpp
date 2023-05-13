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
const ll maxx = 2e5+10,mod=1e9+7,imax=1e18+10;
ll node = 0 ,in[maxx],out[maxx],arr[maxx],brr[2*maxx],pq[maxx],tim=0,kk=0,k,sum;
ll fr[maxx],ans[maxx];
vector < int > g[maxx];
struct query
{
    int l,r,id ;
}
qq[maxx];
bool com(query &a,query &b)
{
   int x = a.l/k , y = b.l/k ;
   if(x==y){return a.r<b.r ; }
   return (x<y);
}
void add(int idx){ fr[brr[idx]]++;  if(fr[ brr[idx] ]==1){sum++;}  }
void dlt(int idx){ fr[brr[idx]]--;  if(fr[ brr[idx] ]==0){sum--;}   }
void dfs(int p,int c)
{
    pq[c]=++node ;
    in[c]=++tim;
    brr[++kk]=arr[c];
    for(auto x : g[c])
    {
        if(x!=p)
        {
            dfs(c,x);
        }
    }
    out[c]=++tim ;
    brr[++kk]=arr[c];
}
set < int > s ;
map < int ,int > ww ;
int main()
{
   int n ;
   cin >> n ;
   k = ceil(sqrt(n));

   for(int i=1;i<=n;i++)
   {
       cin >> arr[i] ;
       s.insert(arr[i]);
   }
   int ii = 1  ;
   for(auto x : s )
   {
       ww[x]=ii++;
   }
   for(int i=1;i<=n;i++)
   {
       arr[i] = ww[arr[i]] ;
   }

   for(int i=1;i<n;i++)
   {
       int u,v ;
       cin >> u >> v ;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(0,1);

   for(int i=0;i<n;i++)
   {
       int idx = i+1 ;
       ///int l = in[idx] , r = out[idx] ;
       ///cout << idx << " " << l << " " << r << endl;
       qq[i].l = in[idx];
       qq[i].r = out[idx];
       qq[i].id = i+1 ;
   }
   sort(qq,qq+n,com);

   int l = 0 , r = -1 ;
   sum = 0 ;
   for(int i=0;i<n;i++)
   {
       int x = qq[i].l , y = qq[i].r , who = qq[i].id ;
       while(r<y){r++;add(r);}
       while(y<r){dlt(r);r--;}
       while(l<x){dlt(l);l++;}
       while(x<l){l--;add(l);}
       ans[who]=sum ;
   }
   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ;}
       cout << ans[i] ;
   }
   cout << endl;
   return 0 ;
}
