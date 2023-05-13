#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>
#include<set>
#include<cstring>
#include<stdio.h>
#include<cmath>
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define pii              pair <int,int>
#define MP               make_pair
#define vi               vector < int >
#define MOD              1000000007
#define sc               scanf
#define pf               printf
#define ll               long long
#define si(a)            scanf("%d",&a)
#define sii(a,b)          scanf("%d %d",&a,&b)
#define loop(i,n)        for(int i=0;i<n;i++)
using namespace std ;
const int maxx = 1e5+10;
int arr[maxx],tree[maxx];
void update(int idx,int n,int val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx += (idx&(-idx));
    }
}
int query(int idx,int n)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= idx&(-idx) ;
    }
    return sum ;
}
void build(int n)
{
    loop(i,n){tree[i+1]=0;}
    loop(i,n)
    {
        update(i+1,n,arr[i+1]);
    }
}
int main()
{
   int n,q;
   sii(n,q);
   loop(i,n)
   {
       int x ; si(x) ; arr[i+1]=x ;
   }
   build(n);
   while(q--)
   {
       int idx,val,sym;
       si(sym);
       if(sym==1)
       {
           sii(idx,val);
           update(idx,n,val);
       }
       else
       {
           si(idx);
           int ans = query(idx,n);
           pf("%d\n",ans);
       }
   }
   return 0 ;
}
