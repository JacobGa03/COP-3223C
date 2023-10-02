/*
Jacob Gadberry
*/



#include <stdio.h>
struct car
{
    float distance;
    float gas;
    float mpg;
};

void setMPG(struct car *car1);

int main(void)
{
    struct car car1;
    car1.distance = 100.0;
    car1.gas = 20.0;
    struct car *car;
    car = &car1;

    setMPG(car);

    printf("%.2f", car1.mpg);


    return 0;
}

void setMPG(struct car *car1)
{
    (*car1).mpg = ((*car1).distance)/((*car1).gas);
}
