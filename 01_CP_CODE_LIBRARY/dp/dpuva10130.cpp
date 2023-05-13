#include<iostream>
#include<cstring>
using namespace std ;
#define max_weight 31
int bestweight[max_weight];

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        memset(bestweight,0,sizeof(bestweight));///intially 0 kre nilam
        int numofpro,provalue,proweight;
        cin >> numofpro ;
        for(int i=0;i<numofpro;i++)
        {
            cin >> provalue >> proweight  ;
            for(int j = max_weight-1 ; j>=proweight ; j--)
            {
  /// at first j=30 kg ,amar taRget 30kg maal emon vabe nibo jate price higgest hoy
  ///onek product asha shuru krlo ,ekek jon ek offer dilo ,jat ta posondo holo nilam then prer
  ///offer gular sathe compare krte thaklam
  /// er mdde abar dekhlam 2ta offer ek sathe nileo prb hoy na
  /// like
 ///       52 4    here [26]=52             /// assume we r looking for the best value for 26
  ///      85 22    here [26]=85
  ///      64 26  here [26]=[26-22]+85
                     ///   = 52+85
                bestweight[j] =  max(bestweight[j] , bestweight[j-proweight]+provalue);
            }
        }
        int temp=0,g,w;
        cin >> g ;
        for(int i=0;i<g;i++)
        {
            cin >> w ;
            temp+=bestweight[w];
        }
        cout << temp << endl;
    }
    return 0;
}
