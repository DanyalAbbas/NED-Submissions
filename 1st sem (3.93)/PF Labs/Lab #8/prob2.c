#include <stdio.h>
#include <string.h>

int main()
{
	char name[20], course1[20], course2[20];
	int freq[26] = {0};
	int maxf = 0;
	char maxc;
	
	printf("Enter your name bbg : ");
	gets(name);
	printf("Enter the course 1 : ");
	gets(course1);
	printf("Enter the course 2 : ");
	gets(course2);
	
	strcat(course1, course2);
	
	int i = 0;
	while (course1[i] != NULL)
	{
		int yes = 0;
		for (int j = 0; j < strlen(name); j++)
		{
			if (course1[i] == name[j])
				yes = 1;
		}
		if (yes == 1)
		{
			int alpha = course1[i] - 'a';
			freq[alpha]++;
		}
		i++;
		
	}
	
	
	for (int i = 0; i < 26; i++)
	{
		if (freq[i] > maxf)
		{
			maxf = freq[i];
			maxc = 'a' + i;
			
		}
	}
	
	if (maxf > 0)
		printf("The max frequency of character is %c : %d", maxc, maxf);
	else
		printf("the characters in name not found in characters");
	
	
	
}