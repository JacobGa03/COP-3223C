/*
Jacob Gadberry
COP 3223C 0003
3/20/2023
Tax: Compute the pay and taxes owed by an individual employee based on input from a .txt file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 20
#define REGTAXRATE .10
#define OVERTAXRATE .20

struct employee
{
    //Obtained from FormatOfClock txt file
    char first[MAXLEN];
    char last[MAXLEN];
    double payPerHr;
    //Updated at the end of the week
    double gross;
    double taxes;
    //Keeps track of ALL hours worked by the employee
    double hoursInWeek;
};

double totalTimeWorked(int hrIn, int minIn, int hrOut, int minOut);

int main(void)
{
    //First open each of the files that will be needed for the program.
    FILE *clockInfo;
    FILE *w2Info;
    //Open each file
    clockInfo = fopen("clock.txt", "r");
    w2Info = fopen("w2.txt", "w");

    //First, establish how many employees there are.
    int numEmployees=0;
    fscanf(clockInfo, "%d", &numEmployees);

    //Create an array of employees based on the given number of employees.
    struct employee employeesIn[MAXLEN];

    //Create some variables to store amount of data to be collected.
    char fName[MAXLEN];
    char lName[MAXLEN];
    int weeks;
    int amountClockin;
    int hrIn, hrOut, minIn, minOut;

    for(int i = 0; i<numEmployees; i++)
    {
        //Read in the name of the new employee.
        fscanf(clockInfo, "%s %s", employeesIn[i].first, employeesIn[i].last);
        fscanf(clockInfo,"%lf", &employeesIn[i].payPerHr);
        employeesIn[i].gross = 0.0;
    }

    //Read in how many weeks of information will be read in
    fscanf(clockInfo, "%d", &weeks);

    //Loop over the amount of weeks to read-in time and and out data
    for(int i =0; i<weeks; i++)
    {
        //Read in how many lines of clock in/out lines are going to be read.
        fscanf(clockInfo, "%d", &amountClockin);

        //Loop over the amount of clock in/out inputs and sum the time.
        for(int j = 0; j<amountClockin; j++)
        {
            //Keeps track of which person we are on.
            int emLoc=-1;

            //Read in the name
            fscanf(clockInfo,"%s %s", lName, fName);
            fscanf(clockInfo, "%d %d %d %d", &hrIn, &minIn, &hrOut, &minOut);

            //Check and see if the employee exists in the data base.
            for(int k = 0; k<numEmployees; k++)
            {
                if((strcmp(employeesIn[k].first,fName)==0) && (strcmp(employeesIn[k].last,lName)==0))
                {
                    //Now that the employee is found, we can use the emLoc variable to keep track when indexing into our array.
                    emLoc = k;
                    break;
                }
            }
            //Calculate hours worked and add it to hoursInWeek.
            double timeWorked = totalTimeWorked(hrIn,minIn,hrOut,minOut);
            employeesIn[emLoc].hoursInWeek += timeWorked;
        }

        //Iterate over each employee and calculate pay/overtime pay and taxes owed.
        for(int j = 0; j<numEmployees; j++)
        {
            //Calculate the amount of pay for the employee.
            if(employeesIn[j].hoursInWeek <=40.0)
            {
                employeesIn[j].gross += (employeesIn[j].hoursInWeek)*(employeesIn[j].payPerHr);
            }
            else
            {
                //Overtime pay.
                employeesIn[j].gross += ((employeesIn[j].hoursInWeek)-40.0)*1.5*(employeesIn[j].payPerHr);
                //Regular pay.
                employeesIn[j].gross += (40.0)*(employeesIn[j].payPerHr);
            }

            //Calculate the amount of taxes the employee owes.
            //Take out regular taxes
            if(employeesIn[j].hoursInWeek <= 40.0)
            {
                employeesIn[j].taxes += REGTAXRATE*((employeesIn[j].hoursInWeek)*(employeesIn[j].payPerHr));
            }
            else
            {
                employeesIn[j].taxes += REGTAXRATE*((employeesIn[j].hoursInWeek)*(employeesIn[j].payPerHr));
                employeesIn[j].taxes += OVERTAXRATE *(((employeesIn[j].hoursInWeek)-40)*1.5*(employeesIn[j].payPerHr));
            }
            //Now that the "week" is over, we reset the amount worked to 0.0 hours.
            employeesIn[j].hoursInWeek = 0.0;
        }
    }

    //Write to the W2 file and input the gross pay, taxes, and net pay to a text file.
    fprintf(w2Info, "Number of employees: %d\n\n", numEmployees);

    for(int j = 0; j<numEmployees; j++)
    {
        fprintf(w2Info, "W2 Form\n-------\n");

        //Print name
        fprintf(w2Info,"Name: %s %s\n", employeesIn[j].first, employeesIn[j].last);
        //Print gross pay.
        fprintf(w2Info, "Gross Pay: $%.2lf\n", employeesIn[j].gross);
        //Print taxes withheld.
        fprintf(w2Info,"Taxes Withheld: $%.2lf\n", employeesIn[j].taxes);
        //Print net pay.
        fprintf(w2Info, "Net Pay: $%.2lf\n", (employeesIn[j].gross)-(employeesIn[j].taxes));
    }

    //Close the files now that the program is over.
    fclose(clockInfo);
    fclose(w2Info);

    return 0;
}

double totalTimeWorked(int hrIn, int minIn, int hrOut, int minOut)
{
        double hrWorked, minsWorked;

        //Since the time out is after the time just subtract to get the amount of hours.
        hrWorked = hrOut-hrIn;

        //If the minuet you clocked in comes before the minuet you clocked out then we simply take the difference
        //between the minuets you clocked in/out to find "minuets worked."
        if(minIn<=minOut)
            minsWorked = minOut-minIn;

        //If the minuet you clocked in came before the time you clocked out
        //we subtract an hour since you did reach the point where you worked one full hour.
        else
        {
            minsWorked = 60-(minIn-minOut);
            hrWorked--;
        }

        return hrWorked + (minsWorked/60);
}
