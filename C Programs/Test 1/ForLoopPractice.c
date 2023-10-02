#include <stdio.h>

int main(void)
{
    int sum = 0;
    int num;

    for(int i = 0; i<5; i++)
    {
        printf("Input a number:\n");
        scanf("%d",&num);


        if((num*10)>=85)
        {
            sum+=num;
        }
    }
    sum*=100;

    printf("Your sum: %d\n",sum);

    return 0;
}
