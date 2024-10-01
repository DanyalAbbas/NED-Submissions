#include <stdio.h>

int main()
{
	int fact=1, num, i;
	
	printf("enter a number : ");
	scanf("%d", &num);
	if (num >= 0)
	{
		for (i=num ; i>1 ; i--)
		   fact *= i;
		
	
		printf("The factorial is %d", fact);
	}
}

