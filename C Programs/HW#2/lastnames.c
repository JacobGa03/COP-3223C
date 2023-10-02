/*
Jacob Gadberry
COP 3223 0003
2/6/2023
This program takes in n last names and check to see if the first is repeated.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    char lastName[1000];
    char name1[30];
    int found =-1;

    printf("Enter n followed by the last names (each name should be one word).\n");
    scanf("%d",&n);
    printf("\n");

    //Read in the first last name
    scanf("%s", name1);

    //We iterate n-1 because we ALREADY read in one name.
    for(int i = 0; i<n-1; i++)
    {
        scanf("%s", lastName);

        if(strcmp(lastName, name1)== 0)
            found = 1;
    }

    //If found is set to 1, the first name is repeated
    if(found == 1)
    {
        printf("The first name is repeated.");
    }
    //If found is not 1, then the first name isn't repeated
    else
    {
        printf("The first name is not repeated.");
    }

    printf("\n");
    return 0;
}
