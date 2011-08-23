#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 6000
#define MAX_LEN 30


int compare(const void *a, const void *b)
{
    const char **pa = (const char **) a;
    const char **pb = (const char **) b;
    return strcmp(*pa, *pb);
}

int give_score(char *str)
{
    int sum = 0;
    while (*str != '\0') {
	sum += (int) (*str - 64);
	str++;
    }
    return sum;
}

int print_string(char **str, size_t len)
{
    size_t i;

    for (i = 0; i < len; i++)
	printf("%s | ", str[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    char *array[MAX_LINE];
    FILE *fp = fopen("file_problem_22", "r");
    int i = 0, max = 0;
    char tmp[MAX_LEN];
    long long int sum = 0;

    while (fscanf(fp, "%s", tmp) != EOF) {
	array[i] = (char *) malloc(sizeof(char) * MAX_LEN);
	strcpy(array[i], tmp);
	i++;
    }
    max = i;

    qsort(array, max, sizeof(char *), compare);

    for (i = 0; i < max; i++)
	sum += (i + 1) * give_score(array[i]);

    printf("res: %lli\n", sum);
    return 0;
}
