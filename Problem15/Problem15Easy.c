#include <stdio.h>

/**
 * * *
 * General Formula:
 * - For an m×n grid:
 * C(m+n, n) = (m+n)! / (m! * n!)
 * Straightforward Recursive Solution (Inefficient)
 * Approach:
 * - Base case: If we reach either edge (m=0 or n=0), there's only 1 path (straight line)
 * - Recursive case: Paths to (m,n) = Paths to (m-1,n) + Paths to (m,n-1)
 * 
 * Why it's inefficient:
 * - Exponential time complexity: O(2^(m+n))
 * - Massive recomputation of the same subproblems
 * Only suitable for very small grids (n <= 10-12)
 */
long long countRoutesStraightforward(int m, int n)
 {
    if (m == 0 || n == 0) {
        return 1;
    }
    return countRoutesStraightforward(m, n - 1) + countRoutesStraightforward(m - 1, n);
}

int main() {
    int small_grid_size = 3;
    printf("Straightforward solution (%dx%d grid): %lld\n", 
           small_grid_size, small_grid_size, 
           countRoutesStraightforward(small_grid_size, small_grid_size));
    
    printf("Note: This approach is too slow for 20x20 grid (would take years)\n");
    return 0;
}