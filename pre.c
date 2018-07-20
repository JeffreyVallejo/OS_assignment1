#include<stdio.h>

main()
{
	char name[10][10];
	int class[10] = {0};
	int userCount = 0;
	int charCount = 0;
	int c = 0;
	
	
	while (( c = getchar()) != EOF)
	{
		if(c >= '0' && c<= '9')
			if(class[userCount] != 0)
				class[userCount] = 10 + (c- '0');
				
			else
				class[userCount] += (c - '0');
		else if (c == '\n')
		{
			userCount++;
			charCount = 0;
		}
		else
		{
			name[userCount][charCount] = c;
			putchar(name[userCount][charCount]);
			charCount++;
		}
	}
	
	for (int i  = 0; i < userCount; i++)
	{
		int a = 0;
		if(class[i] > 5)
		{
			while(name[i][a] != ' ')
			{
				putchar(name[i][a]);
				a++;
			}
			printf("\n");
		}
	}
}
