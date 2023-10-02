/*  Jacob Gadberry
    COP 3223 0003
    Programming Assignment #1
    1/14/2023
    This program will calculate the cost of an item(s) for the user. */

#include <stdio.h>

#define TAX_RATE 0.065

int main(void)
{
    double price;
    int quantity;
    int taxed;
    //Ask user for price
    printf("What is the cost of the item to be purchased (in dollars)?\n");
    scanf("%lf", &price);

    //Ask for quantity
    printf("How many of the item are you purchasing?\n");
    scanf("%d",&quantity);

    //Ask if the item is taxed
    printf("Is the item taxed? 0 - NO, 1 - YES\n");
    scanf("%d", &taxed);

    //Return the price to the user
    double finalPrice = (price * quantity) + (taxed * (price * quantity) * TAX_RATE);
    printf("Your total purchase will cost $%.2lf.\n",finalPrice);

    return 0;
}
