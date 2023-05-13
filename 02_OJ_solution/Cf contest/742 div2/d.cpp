// C Program to convert decimal to any given base
#include <stdio.h>
#include <string.h>

// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
char reVal(int num)
{
   if (num >= 0 && num <= 9)
      return (char)(num + '0');
   else
      return (char)(num - 10 + 'A');
}

// Utility function to reverse a string
void strev(char *str)
{
   int len = strlen(str);
   int i;
   for (i = 0; i < len/2; i++)
   {
      char temp = str[i];
      str[i] = str[len-i-1];
      str[len-i-1] = temp;
   }
}

// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(char res[], int base, int inputNum)
{
   int index = 0; // Initialize index of result

   // Convert input number is given base by repeatedly
   // dividing it by base and taking remainder
   while (inputNum > 0)
   {
      res[index++] = reVal(inputNum % base);
      inputNum /= base;
   }
   res[index] = '\0';

   // Reverse the result
   strev(res);

   return res;
}

// Driver program
int main()
{
   debugMode() ;
   int inputNum = 282, base = 11 ;
   for(int i=1;i<inputNum;i++)
   {
      char res[100];
      printf("%d---"
      " %s\n", i,fromDeci(res, base, i));
   }
   return 0;
}
