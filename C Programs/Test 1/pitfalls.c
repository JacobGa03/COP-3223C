// Arup Guha
// 10/5/2012
// If Statement Pitfalls

#include <stdio.h>

int main() {

    int age = 15;

    /*** one equal instead of two, variable changes, value here is true since 16 != 0 ***/
    if (age = 16) //The value of 16 is greater than zero, so it will evaluate to TRUE
        printf("You are 16 years old.\n");

    printf("age = %d\n", age);

    /*** one equal instead of two, variable changes, value here is false since age is set to 0. ***/
    if (age = 0)
        printf("You are 16 years old.\n");

    printf("age = %d\n", age);

    /*** Inadvertent semicolon, gets treated as its own statement, so print isn't in the if. ***/
    age = 15;
    if (age == 16); {
        printf("You can drive now.\n");
    }

    /*** Trying to check a two-sided inequality all at once ***/
    printf("age is %d\n", age);

    if (16 <= age <= 19)
        printf("You can go to a teen night club.\n");

    /*** The fix for the previous problem... ***/
    printf("age is %d\n", age);

    if (16 <= age && age <= 19) //The proper way to write an in equality
        printf("You can go to a teen night club.\n");

    /*** No braces - second statement executes ***/
    age = 25;
    if (age < 21)
        printf("You can not drink alcohol.\n");
        printf("Enjoy your movie."); //This will ALWAYS executes

    /*** No braces causes a syntax error. You can't have an else statement.

    if (age < 21)
        printf("You can not drink alcohol.\n");
        printf("Enjoy your movie.");
    else
        printf("You can drink alcohol.\n")

    ***/

    return 0;
}
