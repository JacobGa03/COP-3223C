/*
Jacob Gadberry
1/13/2023
Conditionals
*/

#include <stdio.h>

    int main(void)
    {
        // && - AND, || - OR, ! - NOT
        int a = 2;

        if(a%2 == 0) //If the statement here is true
        {
            printf("a is even!"); //This will execute
        }
        else
        {
            printf("a is odd!"); //If the above isn't true, then this code executes.
        }
        return 0;
    }
