#include <stdio.h>
#include <stdint.h>

#include <stdio.h>

/*
  Fundamental mathematical fact:

  If a number n is not prime (that is, it is composite),
  then it can be written as a product:
      n = a × b
  with some positive integers a and b.

  Without loss of generality, assume a ≤ b.
  Then we have:
      a^2 ≤ a × b = n  ⇒  a ≤ √n

  Therefore, every composite number has at least one factor
  less than or equal to its square root.

  This is why in trial division we only need to test divisors
  up to √n. If no divisor is found up to that point, n must be prime.
*/

unsigned long long largest_prime_factor(unsigned long long n) {
    unsigned long long largest = 1;
    unsigned long long i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            largest = i;   // found a factor
            n /= i;        // divide it out
        } else {
            i++;           // try next integer
        }
    }
    if (n > 1) largest = n;  // leftover prime
    return largest;
}

int main(void) {
    unsigned long long n = 600851475143ULL;
    printf("%llu\n", largest_prime_factor(n)); 
    return 0;
}