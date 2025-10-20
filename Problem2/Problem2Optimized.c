#include <stdio.h>

/*
If  we look closely at the Fibonacci sequence, we can see that every third number is even:
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
O  O  E  O  O  E  O   O   E   O   O   E
This pattern occurs because the sum of two odd numbers is even, and the sum of an odd and an even number is odd.
Thus, we can generate only the even Fibonacci numbers using the relation:
E(n) = 4 * E(n-1) + E(n-2)
That is beacause E(n) = O(n-1) + O(n) = (E(n-1) + O(n-2)) + (E(n-1) + E(n-2)) = 4*E(n-1) + E(n-2)
This approach is more efficient as it reduces the number of iterations and avoids unnecessary calculations.

*/

long long int fibonacciEvenSum(int limit){
	long long int a = 2; // first even Fibonacci number
	long long int b = 8; // second even Fibonacci number
	long long int sum = a; // start sum with the first even Fibonacci number

	while(b < limit){	
		sum += b; // add the even Fibonacci number to the sum
		long long int next = 4 * b + a; // calculate the next even Fibonacci number
		a = b; // update a and b
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