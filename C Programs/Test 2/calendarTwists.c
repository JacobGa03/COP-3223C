#include <stdio.h>

int main()
{
    int days = 28, start = 1;
    int weekCount = 1, dayCount = 1;
    int sum;

    for(int i = 1; i<start; i++)
        printf("...");

    for(int i = 1; i<=days; i++)
    {
        printf(" %2d", i);

        if((start-1+i)%7==0)
        {
            printf("\n");
        }

    }

    return 0;
}

/*
PRINTS A 2D IF THE DAY IS DIVISBLE BY 2
if(i%2 == 0)
            printf(" 2D");

PRINTS A BLANK ON THE WEDNESDAY OF THE 3RD WEEK
if(weekCount == 3 && dayCount == 4)
    printf("   ");
else
    printf(" %2d", i);

    if((start-1+i)%7==0)
    {
        printf("\n");
        dayCount = 0;
        weekCount++;
    }

    dayCount++;

IF ITS THE 3RD WEEK, SUM ALL OF THE DATES AND SEE IF THEY'RE DIVISLBE BY 7
if(weekCount==3)
    sum+=i;

if(sum%7 == 0)
    printf("\nsum: %d", sum);
else
    printf("Sum is not divisble by 7");

*/
