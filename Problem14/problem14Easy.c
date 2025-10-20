#include <stdio.h>

/**
 * Straightforward recursive solution without optimization
 * Calculates Collatz sequence length for a given number
 */
long long countChain(long long n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return 1 + countChain(n / 2);
    } else {
        return 1 + countChain(3 * n + 1);
    }
}

int main() {
    long long longest_chain = 0;
    long long answer = 0;
    for (long long number = 1; number < 1000000; number++) {
        long long chain_length = countChain(number);
        if (chain_length > longest_chain) {
            longest_chain = chain_length;
            answer = number;
        }
    }
    
    printf("Starting number with longest chain: %lld\n", answer);
    printf("Chain length: %lld terms\n", longest_chain);
    return 0;
}