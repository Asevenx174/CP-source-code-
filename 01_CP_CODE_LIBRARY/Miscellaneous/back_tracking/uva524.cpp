#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std ;
vector < int > v ;
int n,used[35],prime[35];
void isprime(int idx,int last)
{
    if(v.size()==n){for(int i=0;i<n-1;i++){printf("%d ",v[i]);}printf("%d\n",v[n-1]);return ;}
    int start = idx%2==1 ? 2 : 3 ;
    for(int i=start;i<=n;i+=2)
    {
        if(used[i]==0 && prime[last+i]==1 )
        {
            if(n-1==v.size() && prime[i+1]==0){continue;}
            used[i]=1;
            v.push_back(i);
            isprime(idx+1,i);
            used[i]=0;
            v.pop_back();
        }
    }
}
int main()
{
    int t=1;
    prime[2]=1;prime[3]=1;prime[5]=1;prime[7]=1;prime[11]=1;prime[13]=1;prime[17]=1;
    prime[19]=1;prime[23]=1;prime[29]=1;prime[31]=1;
    while(scanf("%d",&n)!=EOF)
    {
     if(t!=1){printf("\n");}
     v.clear();
     memset(used,0,sizeof(used));
     v.push_back(1);
     printf("Case %d:\n",t++);
     isprime(1,1);
    }
    return 0;
}
