#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int reverse(int num)
{
	int divisor = 10;
	int reverse = 0; 
	int ctr = 0;
	//determine how many digits
	while((num / divisor) != 0)
	{
		ctr++;
		divisor*=10;
	}
	//reset
	divisor = 10;	
	while(ctr >= 0)
	{
		reverse = reverse + (num % divisor) * pow(10, ctr);
		num = num / divisor;
		ctr--;
	}
	return reverse; 
}

int main(int argc, char* argv[])
{
	int num;
	scanf("%d", &num);

	printf("%d\n", reverse(num));

	

	return 0;
}
