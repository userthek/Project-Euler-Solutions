#include <stdio.h>

int main() {
    int a, b, c;

    for (a = 1; a <= 1000; a++) {
        for (b = a; b <= 1000; b++) {
            c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                printf("The Pythagorean triplet is %d, %d, %d\n", a, b, c);
                printf("The product abc is %d\n", a * b * c);
                return 0;
            }
        }
    }

    printf("No Pythagorean triplet found\n");
    return 0;
}
