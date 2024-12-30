#include <stdio.h>
#include <string.h>


void sortbymarks(int rollno[], char names[][20], float marks[])
{
    for (int i = 0; i < 7-1; i++)
    {
        for (int j = i+1; j < 7; j++)
        {
            if (marks[i] < marks[j])
            {
                float tempmarks = marks[j];
                marks[j] = marks[i];
                marks[i] = tempmarks;

                int temproll = rollno[j];
                rollno[j] = rollno[i];
                rollno[i] = temproll;

                char tempname[10];
                strcpy(tempname, names[j]);
                strcpy(names[j], names[i]);
                strcpy(names[i], tempname);
            }
        }
    }
}

void searchbyroll(int rollno[], char names[][20], float marks[], int wantroll)
{
    for (int i = 0; i < 7; i++)
    {
        if (rollno[i] == wantroll)
        {
            printf("\n\n\n%d\t%s\t%.2f",rollno[i],names[i],marks[i]);
            break;
        }   
    }
}

void searchbyname(int rollno[], char names[][20], float marks[], char wantname[10])
{
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], wantname) == 0)
        {
            printf("\n\n\n%d\t%s\t%.2f",rollno[i],names[i],marks[i]);
            break;
        }   
    }
}


int main()
{
    int rollNo[] = {1001, 1002, 1004, 1005, 1007, 1008, 1009};
    char names[][20] = {"Salman", "Zubair", "Ahsan", "Farah", "Hassan", "Kamran", "Mariyum"};
    float marks[] = {75.5, 80.0, 64.0, 78.0, 65.0, 54.0, 60.0};
    sortbymarks(rollNo,names, marks);
    for (int i = 0; i < 7; i++)
        printf("%.2f\t%s\t%d\n", marks[i], names[i], rollNo[i]);

    searchbyroll(rollNo,names, marks, 1002);
    searchbyname(rollNo,names, marks, "Salman");
    
}
