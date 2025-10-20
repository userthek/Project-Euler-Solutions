#include <stdio.h>

/*
Using the formulas of the arithmetic series, we know that the sum of the first n natural numbers is given by:
	S = n(n + 1) / 2	and the sum of the squares of the first n natural numbers is given by:
	S2 = n(n + 1)(2n + 1) / 6
*/

int sumOfSquares(int n ){
	return n*(n+1)*(2*n+1)/6;
}

int squareOfSum(int n){
	int sum = n*(n+1)/2;
	return sum*sum;
}

int main(void){
	int n = 100;
	int result = squareOfSum(n) - sumOfSquares(n);
	printf("%d\n", result);
	return 0;
}