/*
Jacob Gadberry
1/13/2023 %M.Pf
Understanding how M and P affect output of a float
*/

#include <stdio.h>

    int main(void)
    {
        float num = 0.123456789;

        printf("%2.2f",num);
        /*
        Here if our M is less than our number, then the number will print regularly with the amount of decimals specified.
        However, if M > than our number, then white space will be added ahead of the number to make our number take up M amount of space.

        IF: M = 5, P = 2
        THEN: _0.12 <-- Underscore represents whitespace, notice how it takes up five "spots"

        IF: M = 2, P = 2
        THEN: 0.12 <-- Since our M < the length of the number, the whole number prints with no extra whitespace added ahead

        NOTE: P is really easy to understand. P is just the number of decimal points AFTER the . that you want.
        */
    }
