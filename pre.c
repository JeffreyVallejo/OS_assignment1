#include<stdio.h>

int main()
{
	char name[10][10];
	int classes[10] = {0};
	int users = 0;
	int chars = 0;
	int c = 0;
	
	printf("\n\nenter the student a space then the number of classes \n");
	printf("(eg. john 6)\n");
	
	while (( c = getchar()) != EOF)
	{
		if(c >= '0' && c<= '9')
			if(classes[users] != 0)
				classes[users] = 10 + (c - '0');
				
			else
				classes[users] += (c - '0');
		else if (c == '\n')
		{
			users++;
			chars = 0;
		}
		else
		{
			name[users][chars] = c;
			chars++;
		}
	}
	printf("\nDisplaying all students that have taken more than 5 classes\n");
	for (int i  = 0; i < users; i++)
	{
		int a = 0;
		if(classes[i] > 5)
		{
			printf("*");
			while(name[i][a] != ' ')
			{
				putchar(name[i][a]);
				a++;
			}
			printf("\n");
		}
	}
	return 0;
}
