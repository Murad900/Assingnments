#include <stdio.h>

void swap(int x, int y){

	printf("Before swap:\n x: %d\n y: %d\n", x, y);
	
	int temp;

	temp = x;
	x = y;
	y = temp;
	
	printf("\nAfter swap:\n x: %d\n y: %d\n", x, y);

}


int main(void){

	int x = 10, y = 15;

	swap(x,y);

}
