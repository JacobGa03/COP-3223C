// Arup Guha
// 8/29/05
// Program shown in lecture 8/30 or 9/1.

#include <stdio.h>

// Constants.
//const int YARDS_IN_MILE  = 1760; //Constant 1

//#define FEET_IN_YARD 3 //Constant 2

int main() {


  /* Declare and initialize variables.
  int feet_in_mile, num_miles;

  // Calculate the number of feet in a mile.
  feet_in_mile = YARDS_IN_MILE*FEET_IN_YARD;

  // Prompt and read in the number of miles run on the current day.
  printf("How many miles did you run?\n");
  scanf("%d", &num_miles);

  // Print out the final answer.
  printf("You ran a total of %d feet.\n", feet_in_mile*num_miles);

  */

  //New program to use scanf()

  int numGrand;
  int amountMoney; //Amount of money you have

  printf("How many grandkids do you have?\n");
  scanf("%d", &numGrand); //Don't forget the &!!! It assigns the value the user put in into the address of numGrand.

  printf("How much money do you have to split?\n");
  scanf("%d", &amountMoney);

  int amountPerKid = (amountMoney/numGrand);

  printf("Thats about $%d per kiddo.\n", amountPerKid);


  return 0;
}
