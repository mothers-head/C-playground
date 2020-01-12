#include <stdio.h>

int collatz();

int main(int argc, char** argv) {
	
	int num;
	
	if (sscanf(argv[1], "%i", &num) != 1){ 
		fprintf(stderr, "error - not an integer\n");
		return -1;
	}

	printf("Running collatz calculation with %i\n", num);
	int res = collatz(num) - 1;
	printf("The result is %i\n", res);
}

int collatz(int n){
	int count = 0;
	
	if(n == 1)
		return 0;
	else if(n % 2 == 0)
		return  collatz(n / 2) + 1;
	else
		return  collatz(n * 3 + 1) + 1;
}
