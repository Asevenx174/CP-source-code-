#include<stdio.h>
    int nways[9];/* ৮ টাকা পর্সন্ত চেক করতে হবে,০ হতে ৮= ৯ টা মান*/

    int main()
    {

        int coins[5]= {2,4}; /*আমার কাছে যে সব কয়েন আছে */

        int cent,total;

        nways[0]=1;/*০ টাকা বানানোর উপায় ১ টা*/



        for(int i=0; i<2; i++) /*সবগুলো কয়েন নিয়ে কাজ করছি,কয়েন ২ টা, তাই i<2*/
        {

            for(int j=coins[i],k=0; j<=8; j++,k++) /*৮ টাকা পর্যন্ত চেক করব, তাই j<8*/
            {

                nways[j]+=nways[k];

            }

        }
        return 0 ;
    }
