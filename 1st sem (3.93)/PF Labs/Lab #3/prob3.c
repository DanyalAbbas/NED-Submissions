 #include <stdio.h>
 
 int main()
 {
 	double hours, tot, nom;
 	printf("How much time in hours did it take (please no input negative or number more than 5 values): ");
 	scanf("%lf", &hours);
   	printf("\ngive distance traveled in %.2lf hours : ", hours);
   	scanf("%lf", &tot);
	
	printf("\nThe Average Speed of car was : %.3lf", tot/hours);
	 	
 	
 }