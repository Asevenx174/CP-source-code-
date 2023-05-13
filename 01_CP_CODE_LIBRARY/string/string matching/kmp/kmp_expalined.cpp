#include<bits\stdc++.h>
using namespace std ;
void compute_lps_array(char* pat,int np,char *lps);
int kmp(char* pat,char* txt)
{
    int np,nt;
    np=strlen(pat);
    nt=strlen(txt);
    char lps[np];/// since lps cant be larger than patter length np
    compute_lps_array(pat,np,lps);///lps means longest suffix,prefix array
    ///this func will return an array lps with value
    ///this array will help us from where to start comparing in pattern array with txt
    ///it will prevent us to compute same char in txt array again
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < nt)///txt er ekdom shesh prjonto khujbe
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == np)/// found par in txt
        {
            printf("Found pattern at index %d \n", i - j);/// here j is pattern length
            j = lps[j - 1];/// ekbar patter match krse so j ekhno kotha theke suru krbe ?? lps ble dibe
        }

        // mismatch after j matches
        else if (i < nt && pat[j] != txt[i])///match khae nnai but  txt a khujao shesh hoy nai
        {
            if (j != 0)/// match kre nai so j er back kra lagbe but start krbe kotha theke ,lps help krbe lps[j-1]theke j start krbe
                j = lps[j - 1];
            else
                i = i + 1;///j=0 so j er kisu krar nai so i++
        }
    }
}
void compute_lps_array(char* pat,int np,char *lps)
{
    int j=0,i=1;///j will be increased when match , sometimes j need to go back
    lps[0]=0;
    while(i<np)/// ekdom shesh prjonto jabe pattern
    {
        if(pat[i]==pat[j])///match khaise so value gula insert kri
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=lps[0];
                i++;
            }
            else
            {
                j=lps[j-1];/// i change krbo na cos j er new value sathe i match khete pare
            }
        }
    }

}
int main()
{
    char txt[] = "abcdabcabcbacbbcababc";
    char pat[] = "abc";
    kmp(pat, txt) ;
    return 0;
}
