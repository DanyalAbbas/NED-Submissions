#include <stdio.h>

int main()
{
	int a,b, temp, fibonacci, i = 1;
	
	a = 0;
	b = 1;
	while (i==1)
	{
		if (a+b <= 1000)
		{
			printf("%d ", a+b);
			if ((a+b % 3 == 0) || (a+b % 5 == 0) || (a+b % 7 == 0))
	   			printf("\nThe number %d is indeed divisible by 3/5/7 >:3");
			temp = a;
			a = b;
			b = temp + a;
			fibonacci += a;   		  	
	   }
	   else
	   		i = 0;
	}	
}