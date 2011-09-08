#include <stdio.h>

int main()
{
    int a, b;
    int c;

    for (a = 1; a <= 500; a++) {
	for (b = 1; b <= 500; b++) {
	    c = 1000 - a - b;
	    if ((a * a + b * b) == c * c)
		break;
	}
    }

    printf("%d", a * b * c);
    return 0;
}
