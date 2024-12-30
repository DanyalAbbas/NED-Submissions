#include <stdio.h>

void AssignJob(int m);

int main()
{
    int marks;
    printf("What are your marks ji :3 : ");
    scanf("%d", &marks);


    if (marks >= 50)
        AssignJob(marks);
    else
        printf("nuh uh");
}

void AssignJob(int m)
{
    int ex;
    if (m >= 60)
    {
        printf("write number of year experience you have : ");
        scanf("%d", &ex);
        if (ex >=2 && m >= 70)
            printf("YOU GOT THE ASSOCIATE DEVELOPER POST !!");
        else if(ex >=1 && m >= 60)
            printf("YOU GOT THE ASSISTANT DEVELOPER POST !!");
        else if (ex == 0)
            printf("YOU GOT TRAINEE ENGINEER POST !!");
    
    } 
    else if (m >= 50)
        printf("YOU GOT TRAINEE ENGINEER POST !!");
}