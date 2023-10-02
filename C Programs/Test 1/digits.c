#include <stdio.h>

int main() {

    // Get the user input
    int n;
    printf("Enter an integer\n");
    scanf("%d", &n);

    // Use mod to split out the units digit. The mod gives you the digit in the ones place
    int units = n%10;

    // Use integer division to get the rest of the number, then mod
    // to get the original tens digit.
    // Division "deletes" the number in the ones place, thereby making the number in the tens place in the ones place
    int tens = (n/10)%10;

    // Output both.
    printf("units digit is %d\n", units);
    printf("tens digit is %d\n", tens);
    return 0;
}
