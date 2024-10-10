#include <stdio.h>

int main()
{
	int a,b, temp, i = 1;
	
	a = 0;
	b = 1;
	while (i==1)
	{
		if (a+b <= 1000)
		{
			printf("%d\n", a+b);
			if (((a+b) % 3 == 0) || ((a+b) % 5 == 0) || ((a+b) % 7 == 0))
	   			printf("The number %d is indeed divisible by 3/5/7 >:3\n", a+b);
			else
				printf("The number %d is not divisible by 3/5/7 >:(\n", a+b);
			temp = a;
			a = b;
			b = temp + a;	  	
	   }
	   else
	   		i = 0;
	}	
}