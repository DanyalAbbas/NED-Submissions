#include <stdio.h>
int main()
{
	int nts_marks, fsc_marks; 
	printf("Enter your NTS marks >:3 : ");
	scanf("%d", &nts_marks);
	printf("Enter your Fsc marks >:3 : ");
	scanf("%d", &fsc_marks);
	
	if (nts_marks > 70 && fsc_marks > 70)
	   printf("woah! you can go in IT, Electronics and Telecommunication departments of Oxford University >:3\n");
	else if (nts_marks > 60 && fsc_marks > 70)
	   printf("woah! you can go in Electronics and Telecommunication departments of Oxford University >:3\n");
	else if (nts_marks > 50 && fsc_marks > 70)
	   printf("woah! you can go in Telecommunication department of Oxford University >:3\n");
	
	if (nts_marks >= 50 && fsc_marks > 60)
	   printf("woah! you can go in IT, Chemical and Computer departments of MIT University >:3\n");
	else if (nts_marks >= 50 && (fsc_marks > 40 && fsc_marks < 50))
	   printf("woah! you can go in Chemical and Computer departments of MIT University >:3\n");
	else
	   printf("woah! you can go in Computer department of MIT University >:3\n");
}