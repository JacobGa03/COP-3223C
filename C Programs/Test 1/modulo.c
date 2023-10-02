/*
Jacob Gadberry
1/13/2023 Modulo
A little program that demonstrates the function of the mod operator
*/

#include <stdio.h>


    int main(void)
    {
        int a,b;
        printf("Enter two numbers you want to use to mod operator with: \n");
        scanf("%d %d",&a,&b); //Again, DO NOT for get the &, for 'address of' the variable mentioned
        printf("%d and, %d\n", a,b);

        printf("a mod b = %d\n", (a%b));
        return 0;
    }
