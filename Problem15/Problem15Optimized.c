#include <stdio.h>

/**
* We want:
 *     C(2n, n) = (2n)! / (n! * n!)
 * Breaking (2n)! into two parts:
 *     (2n)! = (n+1)(n+2)...(2n) * n!
 * Substituting back:
 *     C(2n, n) = [(n+1)(n+2)...(2n) * n!] / (n! * n!)
 *               = (n+1)(n+2)...(2n) / n!
 * This means:
 *     C(2n, n) = ∏(i=1 to n) (n+i)/i
 *
 * - After n iterations, we have exactly the product above
 */
long long countRoutesOptimized(int n) {
    long long result = 1;
    
    //calculate C(2n, n) = ∏(i=1 to n) (n + i)/i
    //avoiding large factorials and prevents overflow issues
    for (int i = 1; i <= n; i++) {
        result = result * (n + i) / i;
    }
    
    return result;
}

int main() {
    int grid_size = 20;
    
    printf("Optimized combinatorial solution (%dx%d grid): %lld\n", 
           grid_size, grid_size, 
           countRoutesOptimized(grid_size));
    
    printf("This solution works instantly even for very large grids\n");
    return 0;
}