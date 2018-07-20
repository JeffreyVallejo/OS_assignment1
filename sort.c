#include <stdio.h>

//void swap(


int main()
{
	char name[10][10] = {0};
	int index[10] = {0};
	int temp[10] = {0};
	int users = 0;
	int chars = 0;
	int c = 0;
	int count = 0;
	
	
	
	
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
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

	
	//Sorting function
	int j = 0;
	while(j <= 26)
	{
		for(int nameCounter = 0; nameCounter < users; nameCounter++)
		{
				if(65 + j == name[nameCounter][0])
					index[count++] = nameCounter;
			
				if(97 + j == name[nameCounter][0])
					index[count++] = nameCounter;	
		}	
		j++;
	}
	
	
	
	
	for(int i = 0; i < users; i++)
	{

		if((name[index[i]][0] + 32) == name[index[i]+1][0])
		{
			for(int j = 0; j < 10; j++)
				{
					temp[j] = name[index[i]][j];
					name[index[i]][j] =  name[index[i]+1][j];
					name[index[i]+1][j] = temp[j];
				}	
		}
	}
		
	
	for(int i = 0; i < users; i++)
	{
		for(int j = 0; j < 10; j++)
			putchar(name[index[i]][j]);
		
		printf("%s\n", );
	}
	return 0;
}
