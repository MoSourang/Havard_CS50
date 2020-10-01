#include <cs50.h>
#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h>
/// Delclaration of Function
int shift(char c);
/// start of program 
int main(int argc, string argv[])
{
/// ensure that no more than 2 inputs are provided on the commmand 
//
  if(argc == 2)
/// iterates over argv[1] and ensure that every character is an alphabet   
    {
       for(int i = 0, n = strlen(argv[1]); i < n ; i++)
       if(!isalpha(argv[1][i]))
      {
         printf("Usage: ./caesar key\n");
         return 1;
      }
//   Get the plaintext from our user and then intializing key with the second input on the command prompt      
     string P = get_string("plaintext:");
     string key = (argv[1]);
     string C = P;
//// looping over my plaintext and my key while adding each values of my key to the corspending value on then plain text while ignoring --
//non-alpha values on my plaint text 
   for(int i = 0 , j =  0 , n = strlen(P); i < n; i++)
   {
       if(isalpha(P[i]) && isupper(P[i]))
       {
        ;
         P[i] = P[i] - 65;
         C[i] = ((P[i] +  shift(key[j])) % 26) + 65;
         j++;
         if(j == strlen(key))  
          {
           j = 0;
          }
       }
       
       else if(isalpha(P[i]) && islower(P[i]))
       {   
         shift(key[j]);
         P[i] = P[i] - 97;
         C[i] = ((P[i] + shift(key[j])) % 26 ) + 97;
         j++;
         if(j == strlen(key))  
        {
           j = 0;
        }
       }        

      
   } 
///// printing the value of my cypher text 
      printf("ciphertext: %s\n", C);
      printf("%s\n", key);
      return 0;
   }
////// Returns an errors message if more than two input are provided in the command prompt 
  else 
    {
       printf("Usage: ./caesar key\n");
       return 1;
    }
}
/// functions that takes in the alphabetical keys and convert them into their indeces 
int shift(char c)
{
     if(isalpha(c) && isupper(c))
       {
        c = (c - 65);
       }
    else 
       {
         c = (c - 97);
       }
    return c;
}




