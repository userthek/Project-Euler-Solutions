#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int target = 10001;
    
    // Estimate upper bound using prime number theorem: n-th prime ≈ n*ln(n) + n*ln(ln(n))
    int upper_bound = (int)(target * log(target) + target * log(log(target))) + 1000;
    // Create sieve array
    char *is_prime = (char*)calloc(upper_bound + 1, sizeof(char));
    is_prime[0] = is_prime[1] = 1;
    //Sieve of Eratosthenes
    for (int i = 2; i * i <= upper_bound; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= upper_bound; j += i) {
                is_prime[j] = 1;
            }
        }
    }
    // Count primes until we reach the target
    int count = 0;
    int result = 0;
    for (int i = 2; i <= upper_bound; i++) {
        if (!is_prime[i]) {
            count++;
            if (count == target) {
                result = i;
                break;
            }
        }
    }
    printf("The %dth prime number is %d\n", target, result);
    free(is_prime);
    return 0;
}