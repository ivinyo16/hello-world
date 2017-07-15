#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int toFaren(int celsius)
{
	return (celsius * 9 / 5 + 32 );
}

int toCelsius(int faren)
{
	return (faren - 32) * 5 / 9;
}

int main(int argc, char* argv[])
{
	int temp;
	// scanf("%d", &temp);

	// printf("%d\n", toCelsius(temp));
	// printf("%d\n", toFaren(temp));
	printf("%4s%15s%20s%15s\n", "Celsius","Farenheit", "Farenheit","Celsius");
	for( temp = 0 ; temp < 212 ; temp++)
	{
		if( temp  <= 32)
			printf("%4d%15d\n", temp, toFaren(temp));
		else if( temp <= 100)
			printf("%4d%15d%20d%15d\n", temp, toFaren(temp), temp, toCelsius(temp));
		else
			printf("%39d%15d\n", temp, toCelsius(temp));
	}	

	return 0;
}
