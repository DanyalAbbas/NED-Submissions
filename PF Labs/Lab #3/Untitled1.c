#include <stdio.h>

int main()
{
	double tot, tax_rate, salary;
	printf("Hello ji input tax rate perchance? : ");
	scanf("%lf", &tax_rate);
	printf("\nHello again input salary: ");
	scanf("%lf", &salary);
	
	tot = salary - ((tax_rate/100)*salary);
	printf("\ntch tax was like: %.2lf",((tax_rate/100)*salary));
	printf("\nThats what you have now got : %.2lf",tot);
	
	 
	
}