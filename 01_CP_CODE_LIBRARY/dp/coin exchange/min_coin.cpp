#include<iostream>
#include<map>
#include<cstring>
int coins[25],make,num,mincoin[50005];
using namespace std ;
int best()
{
/// like make = 100 , so ami 1 to 100 prjon proti number jnno minimim coin ber kri age
    memset(mincoin,60000,sizeof(mincoin));
/// intially 1,2 .. 100 banaor jno coin shonkha inf kre nichi ,jate minimum ber krte pari
    mincoin[0]=0; /// base case
    for(int i=1;i<=make;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(coins[j]<=i)
            {
                /// like i = 17 , coin[j]=7 , 17-7 banao jae ans = 1 ta coin dia
                /// so 7 + (14-7) banano jabe 1 + ans coin dia
                int req_coin = mincoin[i-coins[j]];
                if(req_coin!=60000 && req_coin+1<mincoin[i])
                {
                    mincoin[i]=req_coin+1;
                }
            }
        }
    }
    return mincoin[make];
}
int main()
{
    cin >> make >> num ;
    for(int i=0;i<num;i++)
    {
        int x ;
        cin >> x ;
        coins[i]=x;
    }
   cout <<  best() << endl;
    return 0;
}
