#include <stdio.h>

/* 
Using the property of palindromes, we can optimize the search for the largest palindrome made from the product of two 3-digit numbers.
A palindrome reads the same forwards and backwards. For a 6-digit palindrome, it can be expressed as:
	100000a + 10000b + 1000c + 100c + 10b + a = 100001a + 10010b + 1100c
This can be factored as:
	11 * (9091a + 910b + 100c)
This means that any 6-digit palindrome is divisible by 11. Therefore, at least one of the two 3-digit factors must be a multiple of 11.
This reduces the number of iterations significantly, as we can iterate one factor in steps of 11.
*/

int isPalindrome(int n){
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
		// ensure one factor is a multiple of 11
		// if i is a multiple of 11, start j from 100, else start from the next multiple of 11
		int jStart = (i % 11 == 0) ? 100 : 110; 
		for (int j=jStart; j<1000; j+=11){
			int product = i*j;
			if (isPalindrome(product) && product > best){
				best = product;
				a = i;
				b = j;
			}
		}
	}
	printf("%d = %d * %d\n", best, a, b);
	return 0;
}