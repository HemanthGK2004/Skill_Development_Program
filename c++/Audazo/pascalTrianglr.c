#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long val = 1;  // First value in every row is always 1
    for (int k = 0; k < n; k++) {
        printf("%lld ", val);
        val = val * (n - 1 - k) / (k + 1);
    }
    return 0;
}
