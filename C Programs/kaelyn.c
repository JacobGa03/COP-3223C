/*Kaelyn Gadberry
Array functions
Date:3/19/23
Assignment 8*/
#include <stdio.h>
#include <math.h>
#define NUMSCORES 100
/* This function reads an unknown number of grades (maximum
of 100) into the array grades and counts the data items
that have been read. You are not supposed to prompt the
user to enter the grades. Just use scanf to read in the
grades. The end of the input is represented by a negative
number –999 */ /*
Preconditions: An empty array which is initialized to 0
must be passed to the function.
Postconditions: Array holds the input values and n is the
effective size of the array (i.e the number of data items
read) */
void readGrades(double grades[], int *n)
{
    grades[NUMSCORES];
    int i, counter = 0;
    double temp;
    for (i=0; i<NUMSCORES; i++) //initalize empty array
    {
        grades[i]=0;
    }
    while (temp != -999.0) //to input grades until -999 is entered
    {
        scanf("%lf", &temp);
        grades[counter] = temp; //store grades in array
        counter++; //increase array size
    }
    //double g = sizeof(grades);
    *n = counter - 1;

}

/*void frequency(double grades[], int n)
{
    int i, j;
    printf("Here is a histogram of the adjusted data:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d- %d| ", ,);
        for (j = 0; j < grades[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}*/
/* Given an array of real numbers, this function finds out
frequency (number of students) for  each interval 0-4, 5-
9,.....,95 – 99, 100 prints out the frequency values and
plots the histogram */

int maximum(double grades[], int n)
{
    double max = grades[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(grades[i]> max)
        max = grades[i];
    }
    return max;
}
/* Given an array of real numbers and the effective size of
the array (i.e. count of the numbers in the array), this
function returns the location of the highest number in the
array */

int minimum(double grades[], int n)
{
    double min = grades[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(grades[i]< min)
        min = grades[i];
    }
    return min;
}
/* Given an array of real numbers and the effective size of
the array (i.e. count of the numbers in the array), this
function returns the location of the lowest number in the
array */

//void deleteElement(double grades[], int *n, int loc);
/* Given an array of real numbers, the effective size of
the array and the location of the element to be deleted,
this function deletes that element from the array and
decrements the effective size, n, by one */

/*double mean(double grades[], int n)
{
    double gradeAvg = 0;
    for(int i=0;i<n;i++)
    {
     gradeAvg += grades[i];
    }
    return gradeAvg/(double)n;
}*/
/* Given an array of numbers and the effective size of the
array this function computes and returns the mean */

/*double StandardDeviation(double grades[], int n)
{
    double sumGrade = 0;
    int i;
    for(i = 0; i < n; i++){
        sumGrade += pow(avg was here but I don't have it - grades[i],2);
    }
    double stadeviat;
    stadeviat = sqrt(sumSqaure / numScores);
    return stadeviat;
    return sqrt(sumGrade / (double)n);
}*/
/* Given an array of numbers and the effective size of the
array, this function computes and returns the standard
deviation as described in the previous section */

int main()
{
    double grades[NUMSCORES];
    int *i;
    readGrades(grades, i);
    printf("i ptr val: %d \n", *i);
    int num = *i;
    int max = maximum(grades, num);
    int min = minimum(grades, num);
    printf("Max: %d and Min: %d", max, min);
    return 0;
}
