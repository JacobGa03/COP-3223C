#include <stdio.h>

int main(void) {

  int grade1 = 75;
  int grade2 = 80;

  // Calculate the average in 5 separate ways.
  // Regular int division, which has truncation
  int average1 = (grade1+grade2)/2;
  int average2 = grade1 + grade2/2;
  int average3 = grade2 + grade1/2;


  // Float division, which will include decimal points
  // Ave 4-7 demonstrate how to cast ints into doubles
  double average4 = (grade1+grade2)/2;
  double average5 = (double)(grade1+grade2)/2;
  double average6 = (grade1+grade2)/2.0;
  double average7 = (double)((grade1+grade2)/2);
  int average8 = (grade1+grade2)/2.0;

  // Print out the result of each.
  printf("Ave #1 = %d\n", average1);
  printf("Ave #2 = %d\n", average2);
  printf("Ave #3 = %d\n", average3);
  printf("___________________\n");
  printf("Ave #4 = %lf\n", average4);
  printf("Ave #5 = %lf\n", average5);
  printf("Ave #6 = %lf\n", average6);
  printf("Ave #7 = %lf\n", average7);
  printf("Ave #8 = %d\n", average8);

  return 0;
}
