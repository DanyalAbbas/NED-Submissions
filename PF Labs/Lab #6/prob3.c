#include <stdio.h>

int main()
{
	int number, i, add = 0, add2 = 0;
	printf("Input any 5 digit number please >:3 : ");
	scanf("%d", &number);
	
	while (number >= 1)
	{
		add += number%10;
		number /= 10;
		printf("%d ", add);
		printf("%d\n", number);
	}
	
	if (add % 2 == 0)
	{
		for (i = 2 ; i<=(add/2) ; i++)
		{
			if (add % i == 0)
			{
				printf("\nThe number is not prime >:(");
				add = 0;
				break;	
			}	
		}
		if (number != 0)
			printf("\nThe number is indeed prime >:3");	
	}
	
}