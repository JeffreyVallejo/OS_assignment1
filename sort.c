#include<stdio.h>

main()
{
	char namesArr[10][10];
	int indexArr[10];
	int names = 0;
	int index = 0;
	int chars = 0;
	int c = 0;
	int a = 0;
	
	while (( c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			names++;
			chars = 0;
		}
		else
		{
			namesArr[names][chars] = c;
			putchar(namesArr[names][chars]);
			chars++;
		}
	}
	printf("\n");
	
	while(a >= 0)
	{
		for(int i = 0; i < names; i++)
		{
			if(97 + a == namesArr[i][0])
			{
				indexArr[index++] = names;
				putchar(indexArr[i]);
				printf("\n");
			}	
			if(65 + a == namesArr[i][0])
			{
				indexArr[index++] = names;
				putchar(indexArr[i]);
				printf("\n");
			}	
		}
	}
	
	
	
	
}
