#include <cstdio>
#include <cmath>

int main() {
    int n, m, a[101];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int start = (n - m % n) % n;
    printf("%d", a[start]);
    for (int i = start + 1; i < start + n; i ++) {
        printf(" %d", a[i >= n ? i % n : i]);
    }
    return 0;
}

