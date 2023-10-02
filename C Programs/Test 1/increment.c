#include <stdio.h>

    int main(void)
    {
         int a = 5;

    // Using the ++ operator
    printf("a = %d\n", a);
    printf("a++ = %d\n", a+=1);
    printf("a = %d\n", a);

    // Using the += operator
    a = 5;
    printf("a = %d\n", a);
    printf("a += 10 = %d\n", a += 10);
    printf("a = %d\n", a);

    return 0;
    }
