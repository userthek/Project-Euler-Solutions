#include <stdio.h>

int main() {
    int digits[350] = {0}; //2^1000 has ~302 digits, 350 is safe
    digits[0] = 1;
    int length = 1;

    for (int i = 0; i < 1000; i++) {
        int carry = 0;
        for (int j = 0; j < length; j++) {
            int product = digits[j] * 2 + carry;
            digits[j] = product % 10;
            carry = product / 10;
        }
        if (carry > 0) {
            digits[length] = carry;
            length++;
        }
    }

    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += digits[i];
    }

    printf("Sum of digits of 2^1000: %d\n", sum);
    return 0;
}