/*  Jacob Gadberry
    COP 3223 0003
    Programming Assignment #1
    1/14/2023
    This program will calculate approximate weight lost based of physical activity. */

#include <stdio.h>

#define WALK_CAL 5
#define STAND_CAL 2
#define DRINK_CAL 20
#define FOOD_CAL 40
#define CALS_PER_POUND 3500

int main(void)
{
    int minsWalking;
    int minsStanding;
    int minsDrinking;
    int minsEating;
    double weightLost = 0.0;

    //Ask how many minuets were spent walking
    printf("How many minuets were you walking?\n");
    scanf("%d", &minsWalking);
    weightLost += (minsWalking*WALK_CAL);

    //Ask how many minuets were spent standing
    printf("How many minuets were you standing?\n");
    scanf("%d", &minsStanding);
    weightLost += (minsStanding*STAND_CAL);

    //Ask how many minuets were spent drinking
    printf("How many minuets were you drinking?\n");
    scanf("%d", &minsDrinking);
    weightLost -= (minsDrinking*DRINK_CAL);

    //Ask how many minuets were spent eating
    printf("How many minuets were you eating?\n");
    scanf("%d", &minsEating);
    weightLost -= (minsEating*FOOD_CAL);

    //Check to see if the amount lost is greater than 0
    if(weightLost>0)
        printf("You lost %.3f pounds today!\n", weightLost/CALS_PER_POUND);
    else
        printf("Weight lost is %.3f pounds.\n",weightLost/CALS_PER_POUND);

    return 0;
}
