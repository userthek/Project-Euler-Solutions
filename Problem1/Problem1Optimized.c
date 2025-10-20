#include <stdio.h>

/* compute the sum of all multiples of n below limit
   idea: multiples are n, 2n, 3n, ..., kn where k = (limit - 1) / n
   sum = n * (1 + 2 + 3 + ... + k) = n * k * (k + 1) / 2 */
int multipleSum(int n, int limit){
	int numOfTerms = (limit - 1) / n;
	return n*numOfTerms*(numOfTerms + 1)/2;
}

int main(void){
	int limit = 1000;
	// subtract multiples of 15 because they are counted twice
	int sum = multipleSum(3, limit) + multipleSum(5, limit) - multipleSum(15, limit);
	printf("%d\n", sum);
	return 0;
}