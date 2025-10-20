#include <stdio.h>

/* 
using the property that gcd(a,b) = gcd(b, a mod b)
we can find the lcm(a,b) = a*b / gcd(a,b)
*/

int gcd(int a, int b){
	while(b!=0){
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

long long int lcm(int a, int b){
	return (long long int)a * b / gcd(a,b);
}

int main(void){
	long long result = 1;
	for(int i=1; i<=20; i++){
		result = lcm(result, i);
	}
	printf("%lld\n", result);
	return 0;
}