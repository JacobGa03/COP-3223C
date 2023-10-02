/*
Jacob Gadberry
Imperial to Metric Converter
1/12/2023
A basic program that converts imperial units of length to metric.
*/

#include <stdio.h>

#define FEETINKILO 3281.0 //No semicolon at the end of const

    int main(void)
    {
        int feetWalked;
        printf("Welcome to 'Feet to Kilometers converter'!\nPlease enter the amount of feet you traveled:\n");
        scanf("%d", &feetWalked);
        double kiloWalked = (feetWalked/FEETINKILO); //We cast our denominator to ensure we get decimal points

        printf("You walked %2.3f kilometers", kiloWalked);

        return 0;
    }
