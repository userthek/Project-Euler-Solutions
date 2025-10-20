#include <stdio.h>
#include <math.h>

//really slow -inefficient solution

int count_divisors(int n) {
    int count = 0;
    int sqrt_n = (int)sqrt(n);
    
    for (int i = 1; i <= sqrt_n; i++) {
        if (n % i == 0) {
            count += 2;
        }
    }
    
    if (sqrt_n * sqrt_n == n) {
        count--;
    }
    
    return count;
}

int main() {
    int n = 1;
    int triangle = 0;
    
    while (1) {
        triangle += n; // triangle = n(n+1)/2
        
        int divisors = count_divisors(triangle);
        
        if (divisors > 500) {
            printf("Triangle number: %d\n", triangle);
            printf("Term number: %d\n", n);
            printf("Divisors: %d\n", divisors);
            break;
        }
        
        n++;
    }
    
    return 0;
}