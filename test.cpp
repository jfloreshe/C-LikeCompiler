#include <iostream>
#include <stdio.h>
#include <string>
int main(int argc, char *argv[]){
	char *temp;
	int a = 123123;
	temp = itoa(a,temp,10);
	printf("value of temp: %s",temp);
}
