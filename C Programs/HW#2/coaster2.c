/*
Jacob Gadberry
COP 3223C 0003
2/3/2023
This program maximizes the people on each train
*/

#include <stdio.h>

#define FIRST_CAR_LENGTH 10
#define NORMAL_CAR_LENGTH 8
#define CAR_CAPACITY 4

int main(void)
{
    int length;
    int workingDist;
    int people;
    int maxPeople = 0;
    int corrCar;
    //Keep track of ALL ratios found. This will be used to find the average ratio at the end.
    float ratioSum = 0.0;
    //Now we need to start from 10, first car length, and add up until we hit a max train length
    //Over each iteration, we will check
    int carCounter = 1;


        //Get the total length of the entire track
        printf("What is total length of the track, in feet?\n");
        scanf("%d", &length);
        workingDist = (.25 * length); //This will give us the max amount of space our cars can take up.

        //Get the length of the train cars
        int trainLength;
        printf("What is the maximum length of a train, in feet?\n");
        scanf("%d",&trainLength);

        for(int trainLen = 10; trainLen <= trainLength; trainLen+=8)
        {
            //25% of total track / the length of the train
            int nTrains = (workingDist/trainLen);

            //Amount of cars that can fit in a train
            int totalCars = nTrains * carCounter;

            //Total roller coaster length is number of trains * the length of each individual train.
            int totalLength = trainLen * nTrains;

            //Keep track of the cumulative car length
            int cumCarLen = trainLen * nTrains;

            //Print the max amount of people for the train
            people = totalCars * CAR_CAPACITY;

            if(people > maxPeople)
            {
                //Update the known max amount of people
                maxPeople = people;
                //Keep track of which amount of cars makes this possible.
                corrCar = carCounter;
            }

            //Print the ratio of people to totalLength
            float ratio = (float)people/totalLength;

            //Add the current ratio to a running sum that we will divide later to find the average.
            ratioSum+=ratio;
            //After all calculations are done, increase the amount of cars your train has.
            carCounter++;
        }

        printf("\n");
        printf("Your ride can have at most %d people.\n", maxPeople);
        printf("This can be achieved with %d trains of cars.\n", corrCar);
        printf("AVG Ratio: %.3f \n", (ratioSum/(carCounter-1)));

        printf("\n");

    return 0;
}
