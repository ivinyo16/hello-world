#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int prodNum;
	int quantity;
	double subtotal;
	printf("Enter: ");
	while ( scanf("%d %d", &prodNum, &quantity) == 2 ) //returns the amount successfully read
	{
		switch(prodNum)
		{
			case 1:
				subtotal = subtotal + quantity*2.98;	
				break;
	                case 2:
                                subtotal = subtotal + quantity*4.5;
                                break;
                        case 3:
                                subtotal = subtotal + quantity*9.98;
                                break;
                        case 4:
                                subtotal = subtotal + quantity*4.49;
                                break;
                        case 5:
                                subtotal = subtotal + quantity*6.87;
                                break;
			default:
				printf("not  a valid prod number\n");
			
		}
	}
	printf("total sales for the week is %.2lf\n", subtotal);
	

	return 0;
}
