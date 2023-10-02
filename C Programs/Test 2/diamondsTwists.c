#include <stdio.h>

int main()
{
    int rows = 30, numstars = 1, rate =1;
    int half;

    //Used for P twist. Used to keep track of the position in the diamond
    int pos = 1;

    if(rows%2==0)
        half = rows/2;
    else
        half = (rows/2) +1;

    for(int j = 1; j<=rows; j++)
    {
            for(int i =1; i<=half-numstars; i++)
                printf(" ");

            for(int i =1; i<=(2*numstars)-1; i++)
            {
                if(j == half || i == numstars)
                    printf("S");
                else
                    printf("*");
            }

            if(numstars == half)
                rate = -rate;

            numstars+=rate;
            printf(" %d", numstars);
            printf("\n");
    }

    return 0;
}

/* TWIST TO ADD S ON THE SPINE OF THE DIAMOND
for(int i =1; i<=2*numstars-1; i++)
        {
            if(j == half || i == numstars)
                printf("S");
            else
                printf("*");
        }
TWIST TO ADD SPACES IN THE VERTICAL DIRECTION
for(int i =1; i<=2*numstars-1; i++)
    {
        if(i == numstars+1 || i== numstars+2)
            printf(" ");
        else
            printf("*");
    }
PRINTING HORIZONTAL NEW LINES
if(j == half+1)
    printf("\n\n\n");

PRINT A P FOR A * IN A POSITION THAT IS PRIME
you will need to create a is function to test for primality: 0 - not prime 1 - prime
if(isPrime(pos) == 0)
    printf("*");
else
    printf("P");

    pos++;
*/
