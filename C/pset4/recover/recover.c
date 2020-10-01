#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{

// variable declaration
typedef uint8_t BYTE;
string filename = malloc(20);
FILE *img;
BYTE storage[520];
bool found = false;
int n = 2049;
int f = 0;

if (argc == 2)
{
/// Open card.raw
FILE *source = fopen(argv[1], "r");

while(fread(storage, 1 , 512, source) == 512)

{
// Reading the data from card.raw & temporarly storing the current 512 bytes being read into an array

// Checking that the current 512 that's stored cointains the signature of a JPEG
    if(storage[0] == 0xff  && storage[1] == 0xd8 && storage[2] == 0xff && (storage[3] & 0xe0) == 0xe0)
      {

// if this is the the first JPEG, opening new file and initiating writting process

        if(f == 0 )
       {
              sprintf(filename, "%03i.jpg", f);
              img = fopen(filename, "w");
              found = true;
              f++;
       }

// if this is not the first JPEC, close old file and open a new file and initiating the writting process
       else if(f > 0)
       {
            fclose(img);
            sprintf(filename, "%03i.jpg", f);
            img = fopen(filename, "w");
            f++;
        }
     }

// if i already found a JPEG, i keep writting to the file
    if (found == true )
    {
          fwrite(storage, 1, 512, img);
    }


// checking if i have reached the end of the file






}

free(filename);
fclose(img);
fclose(source);
}

else
{

//Error messaging for when the user's input is incorrect-
    printf("Please enter a valid input\n");
    return 1;
}

}