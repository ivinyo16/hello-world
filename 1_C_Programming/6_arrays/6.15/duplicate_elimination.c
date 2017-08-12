#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	int numbers[20];
	int i, j, input;
	bool hasDuplicate = false;
	for(i = 0; i < 20; i++)
	{
		scanf("%d", &input);
		numbers[i] = input;
		for(j = i-1; j >= 0; j--)
		{
			//printf("j=%d\n",j);
			if(numbers[i] == numbers[j])
				hasDuplicate = true;
		}
		if(!hasDuplicate)
			printf("print: %d\n", numbers[i]);
		hasDuplicate = false;

	}

	

	return 0;
}
