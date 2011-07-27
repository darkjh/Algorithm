#include <stdio.h>
#include <string.h>
#include <math.h>

void strait_forward()
{
    //nested fucntion to count one number's factor
    //It counts only from 2 to sqrt(n), which is a half of all factors
    int count_factor(int base) {
	int i;
	int count = 0;

	for (i = 2; i <= sqrt(base); i++) {
	    if (base % i == 0)
		count++;
	}
	//return factor number
	return (count + 1) * 2;
    }

    //start from 3, constructing the triangle numbers
    int num = 3;
    int sum = 3;

    while (1) {
	sum += (num++);
	//when one number's factors exceed 500, break
	if (count_factor(sum) >= 500)
	    break;
    }
    printf("Result: %d", sum);
}




int main()
{
    strait_forward();
    return 0;
}
