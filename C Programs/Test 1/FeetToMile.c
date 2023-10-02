/* Arup Guha
   My Second C Program
   8/25/05
   Computes the number of feet in a mile. */

#include <stdio.h>

int main(void) {

  // Declare variables.
  int feet_in_mile, yards_in_mile; //Requesting space in the memory to store values in
  int feet_in_yard; //NOTE: You could have declared each variable on its own line

  // int a;
  // int b; etc..

  // Initialize known values.
  yards_in_mile = 1760; // = is really <--, it is an assignment operator and NOT and equality
  feet_in_yard = 3;

  // Calculate the number of feet in a mile.
  feet_in_mile = yards_in_mile*feet_in_yard;

  // Output the result.
  printf("Yards in Ml=%d\n\n\nfeet in MI=%d.\n", yards_in_mile, feet_in_mile); //You can put two variables! The order matters
  printf("Goodbye!");
  return 0; //Still returning 0
}
