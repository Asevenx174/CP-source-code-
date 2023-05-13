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
int arr[maxx],brr[maxx];
int main()
{
   vector < pii > v ;
   int n,m ;
   cin >> n >> m ;
   for(int i=1;i<=n;i++)
   {
       int x ;
       cin >> x ;
       v.push_back({x,i});
   }
   sort(v.begin(),v.end());
   for(auto p : v )
   {
       //cout << p.ff << " ?? " << p.ss << endl;
       arr[p.ff]=p.ss ;
       brr[p.ss]=p.ff ;
   }
   int sum = 1  ;
   for(int i=2;i<=n;i++)
   {
       if(arr[i]<arr[i-1])
       {
           sum++;
       }
   }

   while(m--)
   {
       int a,b ;
       cin >> a >> b ;
       int x = brr[a];
       int y = brr[b];
       //cout << a << " ??  " << x << endl;
       //cout << b << " ??  " << y << endl;
       int p=0,q=0;
       if(arr[x]<arr[x-1] && x>1)
       {
           p++;
           if(x-1==y){p--;}
       }
       if(arr[x]>arr[x+1] && x<n)
       {
           p++;
           if(x+1==y){p--;}
       }
       if(arr[y]<arr[y-1] && y>1)
       {
           p++;
       }
       if(arr[y]>arr[y+1] && y<n)
       {
           p++;
       }

       //cout << a << " ?? " << x << " " <<  arr[x-1] << " " << arr[x] << " " << arr[x] << endl;

       arr[x]=b;
       brr[b]=x;
       arr[y]=a;
       brr[a]=y;

       if(arr[x]<arr[x-1] && x>1)
       {
           q++;
           if(x-1==y){q--;}
       }
       if(arr[x]>arr[x+1] && x<n)
       {
           q++;
           if(x+1==y){q--;}
       }
       if(arr[y]<arr[y-1] && y>1)
       {
           q++;
       }
       if(arr[y]>arr[y+1] && y<n)
       {
           q++;
       }
       sum+=(q-p);
       cout << sum << endl;
   }
   return 0 ;
}
