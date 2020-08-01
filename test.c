#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char *temp;
	int a = 23123;
	itoa(a,temp,10);
	printf("value of temp: %s",temp);
}
