#include<bits/stdc++.h>
#define pii pair <int,int>
#define ff first
#define ss second
using namespace std ;
typedef long long ll ;
int arr[200010];
struct com
{
    bool operator()(const pii &a,const pii &b)
    {
       int ad = a.ss-a.ff ;
       int bd = b.ss-b.ff ;
       if(ad>=bd)
       {
           return a.ff>b.ss;
       }
       else
       {
           return a.ff<b.ss ;
       }
    }
};
priority_queue < pii , vector < pii > , com > pq ;
void calco(int l,int r)
{
    if(l>=r){return ;}
    int m = (l+r)/2;
    pq.push({l,r});
    calco(l,m-1);
    calco(m+1,r);
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int test ;
  cin >> test ;
  int ans=0;
  while(test--)
  {
      memset(arr,0,sizeof(arr));
      int n,k=1;
      cin >> n ;
      calco(1,n);
      while(!pq.empty())
      {
          pii x = pq.top();
          int a = x.ff , b = x.ss ;
          int m = (a+b)/2;
          arr[m]=k++;
          pq.pop();
      }
      for(int i=1;i<=n;i++)
      {
          if(arr[i]==0){arr[i]=k++;}
          if(i!=1){cout << " " ;}
          cout << arr[i] ;
      }
      cout << endl;
  }
  return 0 ;
}
