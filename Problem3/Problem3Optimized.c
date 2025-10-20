#include <stdio.h>
#include <stdint.h>

/*
  Optimized factorization strategy:

  1. Remove all factors of 2 first
     - If the number is even, keep dividing until it is odd

  2. Then check only odd divisors
     - 3, 5, 7, 9, ... up to √n
     - This alone cuts the work roughly in half

  3. Even better: check only numbers of the form 6k ± 1
     - Every prime greater than 3 has this form
     - This skips obvious composites like 9, 15, 21, etc

  4. Continuous division
     - Whenever we find a divisor, divide n completely
     - This makes n shrink quickly

  5. Finish
     - If at the end n > 1, then n itself is prime
     - That leftover prime is the largest prime factor
*/
unsigned long long largest_prime_factor(unsigned long long n) {
	unsigned long long largest = 1;

	// Step 1: Remove all factors of 2
	while (n % 2 == 0) {
		largest = 2;
		n /= 2;
	}

	// Step 2 and 3: Check odd divisors of the form 6k ± 1
	unsigned long long i = 3;
	while (i * i <= n) {
		if (n % i == 0) {
			largest = i;   // found a factor
			while (n % i == 0) {
				n /= i;    // divide it out completely
			}
		}
		i += 2; // check next odd number
		if (i % 3 == 0) i += 2; // skip multiples of 3
	}

	// Step 5: If n is still greater than 1, then it is prime
	if (n > 1) largest = n;  // leftover prime

	return largest;
}

int main(void) {
	unsigned long long n = 600851475143ULL;
	printf("%llu\n", largest_prime_factor(n)); 
	return 0;
}