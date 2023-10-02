/*  Jacob Gadberry
    COP 3223 0003
    Programming Assignment #1
    1/14/2023
    This program will calculate the amount of people that a roller coaster track can support. */

#include <stdio.h>

#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main(void)
{
    int length;
    int workingDist;
    int people = 0;
    int orignialTrainLength;

    //Scanning n from the user to repeat coaster calculations N times.
    int n;
    printf("What is the value of N?\n");
    scanf("%d",&n);

    for(int i = 0; i<n; i++)
    {
        //Get the total length of the entire track
        printf("What is total length of the track, in feet?\n");
        scanf("%d", &length);
        workingDist = (.25 * length); //This will give us the max amount of space our cars can take up.

        //Get the length of the train cars
        int trainLength;
        printf("What is the maximum length of a train, in feet?\n");
        scanf("%d",&trainLength);
        orignialTrainLength = trainLength;

        //First, subtract ten from the initial length, then use a loop to iteratively down by eight
        //I created a counter variable to keep track of the number of iterations
        int counter =1;
        trainLength-=10;

        //Removing eight from trainLength and keeping track of how many eights removed.
        while(trainLength>=8)
        {
            trainLength-=8;
            counter++;
        }

        //Number of people is determined by the amount of each train: amount of cars * CAR_CAPACITY,
        //and by the number of trains: 25% of the track / train length.
        people = (counter*CAR_CAPACITY)*(workingDist/orignialTrainLength);
        //Display the maximum amount of passengers the ride can hold.
        printf("Your ride can have at most %d people on it at one time.\n", people);

        //Check trainLength value to see if it's greater than 0. If so, then we have a surplus feet; if not,
        //and trainLength == 0, then the train fits perfectly with no remainder.
        if(trainLength>0)
            printf("Maximum train length has a surplus of %d feet.\n", trainLength);
        else
            printf("Maximum train length fits perfectly.\n");

    }

    return 0;
}
