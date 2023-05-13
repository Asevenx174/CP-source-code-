#include<stdio.h>
int nways[11] ;//0-10 er tk gula nia kaj krbo
int main()
{
    /* 0 1 2 3 4 5 6
       1 0 0 0 0 0 0
       1 1 2 2 3 3 4
       1 1 2 2 3 4 5
    */
    int i,j,k;
    int coins[3]={1,2,5};//3,4,5 tk coin nia kaj krbo
    nways[0]=1;// 0 tk ek upae nite pari
    for(i=0;i<3;i++)// coin 3 type er
    {
       //at first 3 tk coin nia kaj krbo,jehetu 3 tk coin nia 3 or er beshi tk banano jae
       // mane 3-10,for that coin[j]=3 and then j++ till 10
       for(j=coins[i],k=0;j<=6;j++,k++)
       {
           nways[j]=nways[j]+nways[k];

       }
       printf("\n");
       // coins[3]=coins[3]+coins[0];//here 1 will be added since coins[0]=1
       // coins[4]=coins[4]+coins[1];
       // coins[5]=coins[5]+coins[2];
       // coins[6]=coins[6]+coins[3];//here 1 will be added since coins[3]=1
       // coins[7]=coins[7]+coins[4];
       // coins[8]=coins[8]+coins[5];
       // coins[9]=coins[9]+coins[6];//here 1 will be added since coins[6]=1
    }
    for(i=0;i<=6;i++)
    {
        printf("%d\t",nways[i]);
    }
    return 0 ;
}
