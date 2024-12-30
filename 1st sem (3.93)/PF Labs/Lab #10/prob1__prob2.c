#include <stdio.h>
#include <conio.h>

// PROBLEM #1
typedef struct
{
	int employee_id;
	char name[20];
	int salary;
	char dept[20];
}Employee;

// PROBLEM #2
int main()
{
	Employee emp1, emp2;
	printf("For Employee 1\n");
	printf("Input name pls >:3 : ");
	gets(emp1.name);
	printf("Input department pls >:3 : ");
	gets(emp1.dept);
	printf("Input employee id pls >:3 : ");
	scanf("%d", &emp1.employee_id);
	printf("Input salary pls >:3 : ");
	scanf("%d", &emp1.salary);
	
	fflush(stdin);
	printf("For Employee 2\n");
	printf("Input name pls >:3 : ");
	gets(emp2.name);
	printf("Input department pls >:3 : ");
	gets(emp2.dept);
	printf("Input employee id pls >:3 : ");
	scanf("%d", &emp2.employee_id);
	printf("Input salary pls >:3 : ");
	scanf("%d", &emp2.salary);
	
	
	printf("\nEmployee ID : %d\nName : %s\nSalary : %d\nDepartment : %s", emp1.employee_id, emp1.name, emp1.salary, emp1.dept);
	printf("\n\nEmployee ID : %d\nName : %s\nSalary : %d\nDepartment : %s", emp2.employee_id, emp2.name, emp2.salary, emp2.dept);
	
	if (emp1.salary > emp2.salary)
		printf("\n\n%s's salary is greater than %s's", emp1.name, emp2.name);
	else if (emp2.salary > emp1.salary)
		printf("\n\n%s's salary is greater than %s's", emp2.name, emp1.name);
	else
		printf("\n\nBoth are equal :O");
			                                                                                                                       
	
	
}