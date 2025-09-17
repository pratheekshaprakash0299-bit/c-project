#include <stdio.h>

long long fact(int n) {
    if (n < 0) return -1;
    long long f = 1;
    for (int i = 2; i <= n; ++i) f *= i;
    return f;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long f = fact(n);
    if (f < 0) { puts("invalid"); return 1; }
    printf("%lld\n", f);
    return 0;
}

