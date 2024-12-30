#include <stdio.h>

int main()
{
	int i, sum = 0, userinput = 0, positive = 0;
	
	printf("what should be the size of the array? : ");
	scanf("%d", &userinput);
	
	int arr[userinput];

	
	
	for (i=0;i<=userinput-1;i++)
	{	
		printf("write a number: ");  
		scanf("%d", &arr[i]);
		if (arr[i] > 0)
		{
			sum += arr[i];
			positive++;
		}
	}
	
	// ignore this! this is just to print out the array
	printf("array : {");
	for (i=0;i<=userinput-2;i++) // for loop to print the array
	{
		printf("%d, ", arr[i]);	
	}
	printf("%d}",arr[userinput-1]);
	
	
	printf("\nThe sum is %d", sum);
	printf("\nThe average of %d is %d", sum, sum/positive);	
	
}