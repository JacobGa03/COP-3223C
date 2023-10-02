// DRAW a DIAMOND
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ROWS 20
int main()
{

  int row, col, numstars=1;
  int half, rate = 1;

  //We add one to acount for ints that are NOT divisible by 2
    if(TOTAL_ROWS%2 ==0)
        half = TOTAL_ROWS/2;
    else
        half = (TOTAL_ROWS/2)+1;

  // Loop through each row.
  for (row=1; row<=TOTAL_ROWS; row++) {

     // Draw the blanks before the stars
     // As number of numstars goes up, spaces goes down
     for (col=0; col< half-numstars; col++)
       printf(" ");

     // Draw the stars
     // 2*numstars-1 <-- Def of an odd. It will start at 1, then, 3, 5, etc.
     for (col=1; col<= 2*numstars-1 ; col++)
       printf("*");

     // If we hit the middle of the diamond, negate the rate.
     if ((numstars == (half)))
       rate = -rate;

     // Change numstars by the rate
     numstars += rate;

     // Go to the new line.
     printf("\n");
  }
 system("pause");
  return 0;
}
