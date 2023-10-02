#include <stdio.h>

    int main(void)
    {
        float amountD; //Make sure you are using correct format codes for different primative types
        float taxRate;

        amountD = 100.0; //Initial amount of money
        taxRate = .10;  //Rate of tax ~ 10%

        float finalAmount;
        finalAmount = (amountD - (amountD*taxRate));

        printf("Your final amount: %f\n", finalAmount);


        //Printing the area of different shapes

        int side = 4;
        int length = 4;

        int area = side*length;

        printf("The area of your rectangle is %d", area);

        return 0; //Have this at the end of main since our return type is int


    }
