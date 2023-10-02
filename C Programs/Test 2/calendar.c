#include <stdio.h>

int main(void) {
  int i, start, days, p;
  printf("How many days in the calndar?\n");
  scanf("%d", &days);
  printf("On what day does the month start? 1- Sun 7- Sat\n");
  scanf("%d", &start);


  for (i=1; i<start;i++)
   printf("...");

  for (i=1; i<=days; i++){
        printf(" %2d", i);
      //We need to offset the start because if we start on 3, then we need to print 5
      //numbers before the end of the week
      if ((start-1 +i)%7==0)
       printf("\n");
    }
}



/* ADD 6 TWIST
if(i%6==0)
            printf(" %2d6",i);
        else
            printf(" %3d",i);

    Make 3rd Wed blank

    Just keep a tracker of weeks and days
*/
