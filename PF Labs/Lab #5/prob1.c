#include <stdio.h>
int main()
{
	char sure;
	
	printf("Are you sure to delete [Y/y] / [N/n]? ");
	scanf("%c", &sure);
	switch(sure)
	   {
	   	case 'Y':
		case 'y': 
		printf("\nDeleted Successfully");
		break;
		case 'N':
		case 'n':
		printf("\nDelete Cancelled");
		break;
		default:
		printf("invalid input bbg");
		break;      		
		}
}