#include <stdio.h>
#include <string.h>

int main()
{
	char f_name[20], l_name[20];
	
	printf("Enter your first name: ");
	scanf("%s", &f_name);
	printf("Enter your last name : ");
	scanf("%s", &l_name);
	
	strcat(f_name, l_name);
	
	int i = strlen(f_name) -1;
	
	while (i >= 0)
	{
		printf("%c", f_name[i]);
		i--;
	}
	
	
		
}
