/*
Jacob Gadberry
COP 3223C 0003
2/13/2023
This program simulates a food bank management system. Users can input donations; take requests; and print items in the bank.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    /*Declare the need array. One to keep track of donation amount
    for each specific item.
    */
    int donAm[100];
    char donType[100] [20];

    char reqType[100] [20];
    int reqAm[100];

    //Keep track of TOTAL donations and requests
    int donCount = 0;
    int reqCount = 0;

    /*word keep track of current item being input by the user.
    donQuant keep track of total items user would like to store/take
    */
    char word[10];
    int donQuant;
    int reqQuant;

    //This variable will be used to keep track of position of item in the list
    int found;

    printf("Welcome to the community food bank!\n");
    printf("1. Add a donation\n");
    printf("2. Add a request\n");
    printf("3. Fulfill a request\n");
    printf("4. Print status report\n");
    printf("5. Exit\n");

    //Allows user to navigate the program
    int choice;
    scanf("%d", &choice);

    while(choice!=5)
    {
        int i;
        //Enter a donation
        if(choice == 1)
        {
            printf("Enter the item you would like to give and the amount.\n");
            //scan for donation type and donation amount
            scanf("%s", &word);
            scanf("%d", &donQuant);

            //Assume the item hasn't been found
            found = -99;

            //iterate over the donType array to see if the item exist already
            //Make sure i is outside of the loop due to scope.
            for(i = 0; i<donCount; i++)
            {
                if(strcmp(donType[i], word)==0)
                    found = i;
            }

            //If the item isn't found, add it to the list
            if(found == -99)
            {
                strcpy(donType[i],word);
                donAm[i] = donQuant;
                donCount++;
            }

            /*Item must have been found, then just
            add the new amount to the current amount for the item*/
            else
            {
                donAm[found] += donQuant;
            }

            printf("\n");
        }
        //Enter a request
        if(choice == 2)
        {
            printf("Enter the item that you need along with the amount.\n");
            //scan for request type and request amount
            scanf("%s", &word);
            scanf("%d", &reqQuant);

            strcpy(reqType[reqCount], word);
            reqAm[reqCount] = reqQuant;

            reqCount++;

        }
        //Fulfill a request
        if(choice == 3)
        {
            if(reqCount == 0)
            {
                printf("There is no hunger in this town. Yippee!\n");
            }
            else if(donCount == 0)
            {
                printf("There are no donations in our bank. :(\n");
            }
            else
            {
                found = -99;

                //Loop over donations to see if there is a request of the same type
                for(i = 0; i<donCount; i++)
                {
                    if(strcmp(donType[i],reqType[0])==0)
                        found = i;
                }

                if(found == -99)
                {
                    printf("Request does not have a match in donations. The system will now stall until someone donates it.");
                }
                else
                {
                    /*If this statement executes, then we assume that the item exists in both lists.
                    Now we must fulfill the request.*/

                    //Donation amount equals request amount
                    if(donAm[found] == reqAm[0])
                    {
                        printf("Lucky you! We have the perfect amount for you.\n");
                        //Delete the request
                        for(i = 1; i<reqCount; i++)
                        {
                            //Moving requests into one position higher
                            strcpy(reqType[i-1], reqType[i]);
                            reqAm[i-1] = reqAm[i];
                        }

                        reqCount--;
                        //Delete the donation
                        for(i = found; i<donCount-1; i++)
                        {
                            strcpy(donType[i], donType[i+1]);
                            donAm[i] = donAm[i+1];
                        }

                        donCount--;
                    }

                    //Donation amount is greater than request amount
                    else if(donAm[found] > reqAm[0])
                    {
                        printf("Amazing! We have enough food for you.\n");

                        donAm[found]-=reqAm[0];

                        //Remove the requests
                        for(i = 1; i<reqCount; i++)
                        {
                            strcpy(reqType[i-1], reqType[i]);
                            reqAm[i-1] = reqAm[i];
                            reqCount--;
                        }
                    }

                    //Donation amount is less than request amount
                    else
                    {
                        printf("Sadly, we can only fill some of your request.\n");
                        reqAm[0] -= donAm[found];
                        //Remove donations
                        for(i = found; i<donCount-1;i++)
                        {
                            strcpy(donType[i], donType[i+1]);
                            donAm[i] = donAm[i+1];
                        }
                        donCount--;
                    }

                }
            }
        }
        //Print a status report
        if(choice == 4)
        {
            //loop over donType and print the item with total amount
            for(int i = 0; i<donCount; i++)
            {
                printf("Report %s %d \n", donType[i], donAm[i]);
            }
        }

        //Check for another choice to start the loop again
        scanf("%d", &choice);
    }

    printf("Thank you for running software! Bye for now! :)\n");

    return 0;
}
