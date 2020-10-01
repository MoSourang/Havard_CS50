#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

int gray_avg;

for(int i = 0; i < height ; i++)

{
for(int j = 0; j < width ; j++)

    {

    gray_avg = round((image[i][j].rgbtBlue  + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);

    image[i][j].rgbtBlue = gray_avg ;

    image[i][j].rgbtGreen = gray_avg ;

    image[i][j].rgbtRed = gray_avg ;

    }
}
 return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
int max = 255;

for(int i = 0;  i < height; i++)

for(int j = 0; j < width; j++)
  {

// calculating the value for the new sepia pixels

    int new_red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
    int new_green = round(.349 * image[i][j].rgbtRed + .686 *  image[i][j].rgbtGreen  + .168 * image[i][j].rgbtBlue);
    int new_blue = round(.272 * image[i][j].rgbtRed  + .534 * image[i][j].rgbtGreen  + .131 * image[i][j].rgbtBlue);

// setting the values of the old pixels, to the values caculated above

    image[i][j].rgbtBlue =  new_blue;
    image[i][j].rgbtGreen = new_green;
    image[i][j].rgbtRed =  new_red;

// checking  if any of the new values are greater than 255

       if( new_blue > 0xFF)
        {
        image[i][j].rgbtBlue = 0xFF;
        }

        if(new_green > 0xFF)
       {
          image[i][j].rgbtGreen = 0xFF;
       }

        if(new_red > 0xFF)
       {

        image[i][j].rgbtRed = 0xFF;
       }


  }
      return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

int m = round((float) width/2);

for(int i = 0; i < height; i++)

for(int j = 0, l = width - 1; j < m; j++, l--)
{
      RGBTRIPLE temp = image[i][j];
      image[i][j] = image[i][l];
      image[i][l] = temp;
}
 return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
int new_red , new_blue , new_green;
float counter;
///copying images into a new array
RGBTRIPLE imageO[height][width];

for (int i = 0 ; i < height ; i++)

for (int j = 0 ; j < width; j++)
{
      imageO[i][j] = image[i][j];
}
///looping over copied imaged and storing values into variables: new_red , new_blue , new_green
for(int i = 0 ; i < height ; i++)

for(int j = 0; j < width ; j++)
{
counter = 0;
new_red = 0;
new_blue = 0;
new_green = 0;
///adding right pixel
if(j == 0)
{
new_red = imageO[i][j + 1].rgbtRed + imageO[i][j].rgbtRed;
new_green =  imageO[i][j + 1].rgbtGreen + imageO[i][j].rgbtGreen;
new_blue = imageO[i][j + 1].rgbtBlue + imageO[i][j].rgbtBlue;
counter =  2;
}
// adding left pixel
if(j == width - 1 )
{
new_red = imageO[i][j - 1].rgbtRed + imageO[i][j].rgbtRed;
new_green = imageO[i][j - 1].rgbtGreen  + imageO[i][j].rgbtGreen;
new_blue = imageO[i][j - 1].rgbtBlue  + imageO[i][j].rgbtBlue;
counter =  2;
}
// adding right and left pixel
if((j > 0 ) && (j < width -1))
{
new_red = imageO[i][j + 1 ].rgbtRed +  imageO[i][j - 1 ].rgbtRed + imageO[i][j].rgbtRed;
new_green = imageO[i][j + 1 ].rgbtGreen +  imageO[i][j - 1 ].rgbtGreen +  imageO[i][j].rgbtGreen;
new_blue = imageO[i][j + 1 ].rgbtBlue +  imageO[i][j - 1 ].rgbtBlue +  imageO[i][j].rgbtBlue;
counter =  3;
}
//adding pixels above and to the right
if((i > 0) && (j == 0))
{
new_red += imageO[i - 1][j].rgbtRed + imageO[i - 1][j + 1].rgbtRed;
new_green += imageO[i - 1][j].rgbtGreen + imageO[i - 1][j + 1].rgbtGreen;
new_blue += imageO[i - 1][j].rgbtBlue + imageO[i - 1][j + 1].rgbtBlue;
counter +=   2;
}
//adding pixels above and to the left
if((i > 0) && (j == width - 1 ))
{
new_red += imageO[i - 1][j].rgbtRed + imageO[i - 1][j - 1].rgbtRed;
new_green += imageO[i - 1][j].rgbtGreen + imageO[i - 1][j - 1].rgbtGreen;
new_blue += imageO[i - 1][j].rgbtBlue + imageO[i - 1][j - 1].rgbtBlue;
counter += 2;
}
//adding pixels above to the right and left
if((i > 0 ) && (j > 0 && j < width - 1))
{
new_red += imageO[i - 1][j].rgbtRed + imageO[i - 1][j - 1].rgbtRed + imageO[i - 1][j + 1].rgbtRed;
new_green += imageO[i - 1][j].rgbtGreen + imageO[i -  1][j - 1].rgbtGreen + imageO[i - 1][j + 1].rgbtGreen;
new_blue += imageO[i - 1][j].rgbtBlue + imageO[i -  1][j - 1].rgbtBlue +  imageO[i - 1][j + 1].rgbtBlue;
counter +=  3;
}
///adding pixels below  and to the right and left
if((i < height - 1) && (j > 0 && j < width - 1))
{
new_red += imageO[i + 1][j].rgbtRed + imageO[i + 1][j - 1].rgbtRed + imageO[i + 1][j + 1].rgbtRed;
new_green += imageO[i + 1][j].rgbtGreen + imageO[i + 1][j - 1].rgbtGreen + imageO[i + 1][j + 1].rgbtGreen;
new_blue += imageO[i + 1][j].rgbtBlue + imageO[i + 1][j - 1].rgbtBlue +  imageO[i + 1][j + 1].rgbtBlue;
counter +=  3;
}
///adding pixels below and to the right
if((i < height - 1) && (j == 0))
{
new_red += imageO[i + 1][j].rgbtRed +imageO[i + 1][j + 1].rgbtRed;
new_green += imageO[i + 1][j].rgbtGreen +imageO[i + 1][j + 1].rgbtGreen;
new_blue += imageO[i + 1][j].rgbtBlue +imageO[i + 1][j + 1].rgbtBlue;
counter  +=   2;
}
//adding pixles below and to the left
if((i < height - 1) && (j == width - 1))
{
new_red += imageO[i + 1][j].rgbtRed +imageO[i + 1][j - 1].rgbtRed;
new_green += imageO[i + 1][j].rgbtGreen +imageO[i + 1][j - 1].rgbtGreen;
new_blue += imageO[i + 1][j].rgbtBlue +imageO[i + 1][j - 1].rgbtBlue;
counter +=   2;
}


image[i][j].rgbtBlue =  round(new_blue/counter);
image[i][j].rgbtGreen = round(new_green/counter);
image[i][j].rgbtRed =  round(new_red/counter);


}

 return;

}
