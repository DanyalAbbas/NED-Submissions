#include <stdio.h>

typedef struct
{
    char course_name[20];
    float gpa;
}Course;

typedef struct 
{
    char street[20];
    char city[10];
    char state[10];
    int zip;
}Address;

typedef struct
{
    float CGPA;
    Course courses[5];
    Address home_address;
}StudentData;

int main()
{
    StudentData std1, std2;
    printf("Enter CGPA : ");
    scanf("%f", &std1.CGPA);
    
    for (int i = 0; i < 5; i++)
    {
        printf("Enter course %d name : ", i);
        scanf("%s", &std1.courses[i].course_name);
        printf("Enter course gpa : ");
        scanf("%f", &std1.courses[i].gpa);
    }

    printf("Enter street: ");
    scanf("%s", std1.home_address.street);
    fflush(stdin);
    printf("Enter city: ");
    scanf("%s", std1.home_address.city);
    fflush(stdin);
    printf("Enter state: ");
    scanf("%s", std1.home_address.state);
    fflush(stdin);
    printf("Enter zip: ");
    scanf("%d", std1.home_address.zip);


    // Student ke liye bhi saari lambi same hai, then for loop me if condition chale gi :3

    printf("%s", std1.courses[3].course_name);


}

