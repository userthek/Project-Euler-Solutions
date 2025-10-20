#include <stdio.h>
//we will generate all fibonacci numbers below 4 million and add only the even ones -- not recommended
long long int fibonacciEvenSum(int limit){
	long long int a = 1;
	long long int b = 2;
	long long int sum = 0;
	while(a < limit){
		if(a % 2 == 0){
			sum += a;
		}
		long long int next = a + b; //next fibonacci number
		a = b; //update a and b
		b = next; // update b
	}
	return sum;
}

int main(void){
	int limit = 4000000;
	long long int sum = fibonacciEvenSum(limit);
	printf("%lld\n", sum);
	return 0;
}
