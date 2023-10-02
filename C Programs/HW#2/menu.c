/*
Jacob Gadberry
COP 3223C 0003
2/6/2023
This program puts coasters2 and lastnames into a menu interface. This allows the user to select which program they would like to run.
*/

#include <stdio.h>
#include <string.h>

int main (void)
{
    int n=0;
    //Print instructions
    printf("Use 1 - Run coasters2 program.\n");
    printf("Use 2 - Run lastnames program.\n");
    printf("Use 3 - to print instructions.\n");
    printf("Use -1 - to quit.\n");

    while(n!=-1)
    {
        scanf("%d", &n);

            if(n==1)
            {
               //run coasters2.
                printf("Running 1\n");
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
                        people = totalCars * 4;

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

            }

            else if(n==2)
            {
                //run lastnames.
                printf("Running 2\n");
                int n;
                char lastName[1000];
                char name1[30];
                int found =-1;

                printf("Enter n followed by the last names (each name should be one word).\n");
                scanf("%d",&n);
                printf("\n");

                //Read in the first last name
                scanf("%s", name1);

                //We iterate n-1 because we ALREADY read in one name.
                for(int i = 0; i<n-1; i++)
                {
                    scanf("%s", lastName);

                    if(strcmp(lastName, name1)== 0)
                        found = 1;
                }

                    //If found is set to 1, the first name is repeated
                    if(found== 1)
                    {
                        printf("The first name is repeated.");
                    }
                    //If found is not 1, then the first name isn't repeated
                    else
                    {
                        printf("The first name is not repeated.");
                    }


                printf("\n");

            }

            else if(n==3)
            {
                //Print instructions
                printf("Use 1 - Run coasters2 program.\n");
                printf("Use 2 - Run lastnames program.\n");
                printf("Use 3 - to print instructions.\n");
                printf("Use -1 - to quit.\n");
            }
            else
            {
                printf("Not a valid option. Please try again.\n");
            }

        }

    printf("\nThank you for using.");
    return 0;
}
