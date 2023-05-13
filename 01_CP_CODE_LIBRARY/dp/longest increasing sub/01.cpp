#include<bits\stdc++.h>
#define maxx 10000
using namespace std ;
int value[]={-100000,5,0,9,2,7,3,4},dp[maxx],dir[maxx],n=7;
int longest(int u)
{
    if(dp[u]!=-1){return dp[u];}///dp krlam
    int m=0;/// u er jnno longest path er length store krbo
    for(int v=u+1;v<=n;v++)///first con i<j
    {
        if(value[v]>value[u])///2nd cond value[i]<value[j]
        {
            if(longest(v)>m)
            {
                m=longest(v);
                dir[u]=v;///here u is starting point and v is end point
            }
        }
    }
    dp[u]=1+m;/// u er length ta count kri nai so 1 +
    return dp[u];
}
void print(int start)
{
    while(dir[start]!=-1)
    {
        cout << start << " " << value[start] << endl;
        start=dir[start];
    }
}
int main()
{
    /// dp[i]= for i store the longest path length
    ///dir will store the path like staring to end point of lis
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    int lis=0,start;///here lis is to store max lis
    for(int i=1;i<=7;i++)
    {
        int x = longest(i);
        if(x>lis)
        {
            lis=x;
            start=i;
        }
    }
    printf("from %d we will get lic which is %d",start,lis);
    print(start);
    return 0;
}
