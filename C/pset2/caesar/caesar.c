#include <cs50.h>
#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>
/// Declare Variable 

int main(int argc, string argv[])
{
      if (argc == 2)
/// loops to check in input is a digit or not     
     {
       for(int i = 0, n = strlen(argv[1]); i < n ; i++)
       if(!isdigit(argv[1][i]))   
      {
         printf("Usage: ./caesar key\n");
         return 1;
      } 
/// Key is stored a variable k abd converted into a digit 
        int k = atoi(argv[1]); 
        string P = get_string("plaintext:  ");
        string C = P;
/// loops interates over the values in plain text and encrypt those values         
        for(int i = 0, n = strlen(P); i <= n ; i++)    
       {
        if(isalpha(P[i]) && isupper(P[i]))
         {
              C[i] = (P[i] - 65);  
              C[i] = ((P[i] + k) % 26) + 65;
         }
          else if (isalpha(P[i]) && islower(P[i]))
         {
              C[i]  = (C[i] - 97);  
              C[i]  = ((C[i] + k) % 26) + 97;
         } 
       }   
/// fianl value of the cypher text is printed out 
             printf("ciphertext: %s\n", P);
             return 0;
     }
    else  
     {
       printf("Usage: ./caesar key\n");
       return 1;
     }
    
}
