#include <stdio.h>

/*
a^2 + b^2 = c^2
a + b + c = 1000 <=> c = 1000 - a - b
so by substituting in the first equation we get:
a^2 + b^2 = (1000 - a - b)^2
which can be simplified to:
a^2 + b^2 = 10^6 - 2*10^3(a + b) + (a+b)^2 <=> 0 = 10^6 - 2*10^3(a + b) + 2ab
so by solving for b we get:
b = (10^6 - 2*10^3*a) / (2*(10^3 - a))
we can iterate over a and calculate b, then check if b is an integer and if a < b < c to find the triplet 
the upper bound for a is 333 beacause suppose that a=b=c, then we have 3a=1000 => a=333.33 
*/

int main(){
	int target = 1000;
	int a,b,c;
	for (int a=1; a<=333; a++){
		int denominator = 2*(target - a);
		int numerator = target*target - 2*target*a;
		if (numerator % denominator == 0){ // check if b is an integer
			b = numerator / denominator;
			c = target - a - b;
			if (a < b && b < c){ // check if a < b < c
				printf("The Pythagorean triplet is %d, %d, %d\n", a, b, c);
				printf("The product abc is %d\n", a*b*c);
				return 0;
			}
		}
	}
		printf("No Pythagorean triplet found\n");
}