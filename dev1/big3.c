#include <stdio.h>

int main(void) {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("%d\n", max);
    return 0;
}

