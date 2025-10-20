#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000000

//global array for memoization
long long *values;

/**
 * Optimized recursive function with memoization and step optimization
 * 
 * Key optimizations explained:
 * 
 * 1. MEMOIZATION: Store previously computed results to avoid redundant calculations
 *    When we calculate Collatz(26), we get: 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *    Instead of recalculating the entire chain for 13, we store Collatz(13) = 10 and reuse it
 *    So Collatz(26) = 1 + Collatz(13) = 11
 *    This avoids exponential recomputation and is the most crucial optimization
 * 
 * 2. STEP OPTIMIZATION FOR ODD NUMBERS: Combine two steps into one
 *    For odd n: n → 3n+1 (which is always even) → (3n+1)/2
 *    Instead of: Collatz(n) = 1 + Collatz(3n+1)
 *    We use: Collatz(n) = 2 + Collatz((3n+1)/2)
 *    This saves function calls and improves performance
 * 
 * 3. RANGE REDUCTION: Only check numbers from LIMIT/2 to LIMIT-1
 *    Mathematical insight: Collatz(2k) = Collatz(k) + 1
 *    Therefore: Collatz(2k) > Collatz(k) for all k
 *    This means the maximum chain length must come from numbers ≥ LIMIT/2
 *    So we only need to check numbers from 500,000 to 999,999
 */
long long countChain(long long n) {
    // Base case
    if (n == 1) {
        return 1;
    }
    //optimization 1: check if we have already computed this value
    if (n < LIMIT * 3 && values[n] != 0) {
        return values[n];
    }
    long long result;
    if (n % 2 == 0) {
        //Even:n→n/2
        result = 1 + countChain(n / 2);
    } else {
        //Odd:n→3n+1 
		//optimization 2: combine two steps into one
        result = 2 + countChain((3 * n + 1) / 2);
    }
    if (n < LIMIT * 3) {
        values[n] = result;
    }
    
    return result;
}

int main() {
    // Allocate memory for memoization (accommodate numbers up to 3×LIMIT)
    values = (long long*)calloc(LIMIT * 3 + 1, sizeof(long long));
    if (values == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    values[1] = 1;
    long long longest_chain = 0;
    long long answer = 0;
    //optimization 3: only check numbers from LIMIT/2 to LIMIT-1
	//Since Collatz(2k) = Collatz(k) + 1 > Collatz(k), the maximum chain length must come from numbers >= LIMIT/2
    for (long long number = 500000; number < LIMIT; number++) {
        long long chain_length = countChain(number);
        if (chain_length > longest_chain) {
            longest_chain = chain_length;
            answer = number;
        }
    }
    printf("Starting number with longest chain: %lld\n", answer);
    printf("Chain length: %lld terms\n", longest_chain);
    free(values);
    return 0;
}