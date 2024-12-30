#include <stdio.h>
#include <math.h>

int main ()
{
	float a, b, c, discriminant, ans1, ans2;
	
	printf("Enter values of a, b and c : ");
	scanf("%f %f %f", &a, &b, &c);
	
	discriminant = pow(b,2) - 4*a*c;
	if (discriminant > 0)
	   {
	   	ans1 = (-b + sqrt(discriminant))/(2*a);
	   	ans2 = (-b - sqrt(discriminant))/(2*a);
	   	printf("The Answers will be %f and %f", ans1, ans2);
		}
	else if (discriminant == 0)
	   {
	   	ans1 = -b/(2*a);
	   	printf("The answer will be %f", ans1);   
		}
	else{
		   printf("The roots are imaginary");
		}
	 
}                                               