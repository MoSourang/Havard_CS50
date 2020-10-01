#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int Height;
   int i;
   int j; 
   int d;
    
    // Asking the user for a positive interger between 1-8 
    do 
    {
    Height = get_int("Please Enter a Height between 1-8:");
    }
    while (Height <= 0 || Height  >=9);
  
    // first outer loop move the staris one level down 
    for(i = 1; i <= Height ; i++)
    {
        printf("\n");
    // First inner loop add a space for each row 
      for (d = Height ; d > i ; d--)
      {
      printf(" ");
      }
    ///Second inner loop creates the # 
      for(j = 0; j < i; j++)      
      {
      printf("#");  
       } 
     }       
       printf("\n"); 
}
