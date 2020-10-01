#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)  
{
  
    float Owed;
    int New_owed;
    int coins_Q = 0;
    int coins_D = 0;
    int coins_N = 0;
    int coins_P = 0;
    int coins_total;
    int change;
   
    do 
    {
    Owed = get_float("How Much are you owed?");
    }
    while (Owed < 0 );
    
    New_owed  = round(Owed *100);
    change = New_owed; 
  
     while (change >= 25)
     {
         coins_Q = change / 25;
         change = change  % 25;    
     }
    
     while (change >= 10)
     {
         coins_D = change /10;
         change = change% 10;  
     }
    
    while (change >= 5)
    {
         coins_N = change/5;
         change = change %5;
    }
    
   
     coins_P = change;
     coins_total = (coins_Q + coins_D + coins_N + coins_P) ;
     printf("%i\n", coins_total);
      
}
        
 


    





