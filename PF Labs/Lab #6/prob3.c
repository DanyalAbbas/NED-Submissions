#include <stdio.h>
#include <string.h>

int main()
{
	int number, i, add = 0, add2 = 0;
	printf("Input any 5 digit number please >:3 : ");
	scanf("%d", &number);

	char pali[5]; 
	
	i = 0;
	while (number >= 1)
	{
		add += number%10;
		pali[i] = number%10;
		i++;
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
		if (add != 0)
			printf("\nThe number is indeed prime >:3");	
	}
	else
	{
		for (int j = 0, k = 4; j<5; j++,k--)
		{
			if (pali[j] != pali[k])
			{
				i = 69;
				break;
			}
		}
		if (i == 69)
			printf("The number is not a palindrome");
		else
			printf("The number is indeed palindrome");
		
	}
	
}