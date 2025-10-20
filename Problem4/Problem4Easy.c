#include <stdio.h>
#include <stdlib.h>

int isPlindrome(int n){
	int reversed = 0;
	int original = n;
	while (n>0){
		reversed  = n%10 + reversed*10;
		n/=10;
	}
	return reversed == original;
}

int main(void){
	int best = 0;
	int a = 0, b = 0;
	for (int i=100; i<1000; i++){
		for (int j=100; j<1000; j++){
			int product = i*j;
			if (isPlindrome(product) && product > best){
				best = product;
				a = i;
				b = j;
			}
		}
	}
	printf("%d = %d * %d\n", best, a, b);
}