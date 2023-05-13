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
int ar[maxx+10] ;
long long merge(int a[], int temp[], int left, int mid, int right)
{
   int i, j, k;
   long long count = 0;
   i = left;
   j = mid;
   k = left;
   while ((i <= mid - 1) && (j <= right))
   {
      if (a[i] <= a[j])
      {
          temp[k++] = a[i++];
      }
      else
      {
         temp[k++] = a[j++];
         count += (mid - i);
      }
   }
   while (i <= mid - 1)
   {
      temp[k++] = a[i++] ; 
   }
   while (j <= right)
   {
      temp[k++] = a[j++];
   }
   for (i=left; i <= right; i++)
   {
      a[i] = temp[i];
   }
   return count;
}
long long mergeSort(int a[], int temp[], int left, int right)
{
   int mid;
   ll count = 0;
   if (right > left)
   {
      mid = (right + left)/2;
      count = mergeSort(a, temp, left, mid);
      count += mergeSort(a, temp, mid+1, right);
      count += merge(a, temp, left, mid+1, right);
   }
   return count;
}
ll aInversion(int a[], int n)
{
   int temp[n] ;
   return mergeSort(a, temp, 0, n - 1) ;
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      lp(i,1,n)
      {
         cin >> ar[i-1] ; 
      }
      ll ans = aInversion(ar,n) ;
      ll idx = 0 ; 
      while(idx<n)
      {
         ll c = 1 ; 
         while(ar[idx]==ar[idx+1] && idx+1<n)
         {
            idx++;
            c++;
         }
         ll add = c*(c-1LL) ; 
         add = add/2LL ;
         ans+=add ; 
         idx++;
      }
      cout << ans << endl ;
   }
   return 0 ;
}