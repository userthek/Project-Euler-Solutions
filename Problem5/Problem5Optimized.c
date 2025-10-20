#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
For a number to be divisible by all numbers from 1 to n, it must include the highest powers of all prime numbers less than or equal to n.
For example, for n = 10, the prime numbers are 2, 3, 5, and 7. The highest powers of these primes that are less than or equal to 10 are: 
2^3 (8), 3^2 (9), 5^1 (5), and 7^1 (7).
Thus, the smallest number divisible by all numbers from 1 to 10 is 2^3 * 3^2 * 5^1 * 7^1 = 2520.
To find the smallest number divisible by all numbers from 1 to 20, we can follow the same approach.
*/

//using the Sieve of Eratosthenes to generate all primes up to n
void sieve_of_eratosthenes(int n, bool* is_prime) {
	for (int i = 2; i <= n; i++) {
		is_prime[i] = true; // assume all numbers are prime initially
	}
	is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers

	for (int p = 2; p * p <= n; p++) {
		if (is_prime[p]) {
			for (int multiple = p * p; multiple <= n; multiple += p) {
				is_prime[multiple] = false; // mark multiples of p as non-prime
			}
		}
	}
}

long long int smallest_multiple(int n) {
	bool* is_prime = (bool*)malloc((n + 1) * sizeof(bool));
	sieve_of_eratosthenes(n, is_prime);

	long long int result = 1;

	for (int p = 2; p <= n; p++) {
		if (is_prime[p]) {
			// find the highest power of p that is <= n
			int power = p;
			while (power * p <= n) {
				power *= p;
			}
			result *= power; // multiply the result by this highest power
		}
	}

	free(is_prime);
	return result;
}

int main(void) {
	int n = 20;
	printf("%lld\n", smallest_multiple(n));
	return 0;
}