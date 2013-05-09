#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//#define LIMIT 2000000;

void prime_brute_force()
{
    //long long int to store result
    unsigned long long sum = 0;
    unsigned int i;

    //nested brute force prime search, skip pair numbers
    int prime(unsigned int n) {
	unsigned int i;
	for (i = 3; i <= sqrt(n); i += 2) {
	    if (n % i == 0)
		return 0;
	}
	return 1;
    }
    //calling part
    for (i = 3; i < 2000000; i += 2) {
	if (prime(i))
	    sum += (unsigned long long) i;
    }
    //add back skipped 2
    sum += 2;
    //IMPORTANT! for output have to put %llu here, not %d
    printf("%llu", sum);
}

void prime_sieve()
{
    int LIMIT = 2000000;
    char sieve[LIMIT];
    unsigned long long sum = 2;
    unsigned int total;
    unsigned int i, j;

    memset(sieve, 1, sizeof(char) * LIMIT);

    sieve[0] = 0;

    for (i = 3; i < LIMIT; i += 2) {
	//according to the array, if the number is 1, then it's a prime
	//we start from 3, so the first one is a prime
	if (sieve[i]) {
	    sum += (unsigned long long) i;
	    total++;

	    //mark all of current i's multilpes
	    for (j = i + i; j < LIMIT; j += i) {
		sieve[j] = 0;
	    }
	}
    }
    printf("%llu\n", sum);
}

int main()
{
    //prime_brute_force();
    prime_sieve();
}

/* #include <stdio.h> */
/* #include <string.h> */
/* #include <math.h> */

/* #define HIGHEST 2000000 */

/* char Prime[HIGHEST / 2]; */

/* int main(int argc, char** argv) */
/* { */
/*    unsigned int i, j; */
/*    unsigned long long sum = 2; */
/*    unsigned int total = 0; */

/*    /\* Set entire array to true (prime) *\/ */
/*    memset(Prime, 1, sizeof(char)*HIGHEST / 2); */
/*    /\* except for 1 *\/ */
/*    Prime[0] = 0; */

/*    for(i = 3; i < HIGHEST; i += 2) { */
/*       if(Prime[i / 2] == 1) { */
/*          sum += (unsigned long long)i; */
/*          total++; */
/*       } */
/*       for(j = (i+i+i)/2; j < HIGHEST/2; j += i) { */
/*          Prime[j] = 0; */
/*       } */
/*    } */
/*    printf("Sum: %llu (%d prime numbers)\n", sum, total); */
/* } */
