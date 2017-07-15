#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stdprint(int a, int b)
{
	printf("%d --> %d\n", a, b);
}

void tower(int disks, int initial, int destination, int temp)
{
	if(disks == 1)
		stdprint(initial, destination);
	else
	{
		tower(disks-1,initial,temp,destination);
		tower(1,initial,destination,temp);
		tower(disks-1,temp,destination,initial);
	}




}

int main(int argc, char* argv[])
{
	int disks, initial, destination, temp;
	scanf("%d %d %d %d", &disks, &initial, &destination, &temp);
	tower(disks, initial, destination, temp);

	return 0;
}
