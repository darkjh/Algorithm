#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int data[100][50];
    int result[100];
    int res;
    int c;
    int i, j, k;
    char waste;

    res = 0;
    c = 0;
    k = 0;
    memset(result, -1, sizeof(char) * 100);
    fp = fopen("file_problem_13", "r");

    for (i = 0; i < 100; i++) {
	for (j = 0; j < 50; j++) {
	    fscanf(fp, "%c", &waste);
	    data[i][j] = waste - '0';
	}
	fscanf(fp, "%c", &waste);
    }
    fclose(fp);

    for (j = 49; j >= 0; j--) {
	for (i = 0; i < 100; i++) {
	    res += data[i][j];
	}
	res += c;
	result[k++] = (int) (res % 10);
	c = (int) (res / 10);
    }
    while (c != 0) {
	result[k++] = (int) (c % 10);
	c /= 10;
    }

    i = 0;
    while (result[i] >= 0)
	printf("%d", result[i++]);
    return 0;
}
