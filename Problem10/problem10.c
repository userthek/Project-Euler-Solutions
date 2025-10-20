#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    long long sum = 2; // Start with 2 (the only even prime)
    int limit = 2000000;
    // Only check odd numbers (half the memory needed)
    int sieve_size = (limit - 1) / 2;
    char *is_prime = (char*)calloc(sieve_size, sizeof(char));
    memset(is_prime, 1, sieve_size);
    // Sieve for odd numbers only
    for (int i = 1; i < sieve_size; i++) {
        if (is_prime[i]) {
            int prime = 2 * i + 1;
            sum += prime;
            
            // Mark multiples of this prime
            for (int j = 3 * i + 1; j < sieve_size; j += prime) {
                is_prime[j] = 0;
            }
        }
    }
    printf("Sum of primes below %d: %lld\n", limit, sum);
    free(is_prime);
    return 0;
}