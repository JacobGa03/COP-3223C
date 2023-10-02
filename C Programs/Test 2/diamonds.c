/*
Jacob Gadberry
1/30/2023
Diamonds
Draws a diamond of specified height and length

*/
#include <stdio.h>

int main(void)
{

    int height = 20;
    int length = 20;
    int numstars = 1;
    int temp = 0;

    //Print out the desired height of the diamond
    for(int i = 0; i < height+1; i++)
    {
        //Print the spaces
        for(int j = 0; j<length-temp; j++)
        {
            printf(" ");
        }

        //Print the stars
        for(int j = 0; j<numstars; j++)
        {
            printf("*");
        }

        //If the height is less than half, continue to add 2 stars
        if(i < (height/2))
        {
            numstars+=2;
        }
        else
        {
            numstars -=2;
            //Temp will help get the desired amount of space once you hit the halfway point
            temp-=2;
        }

        temp++;

        printf("\n");
    }

    return 0;
}
