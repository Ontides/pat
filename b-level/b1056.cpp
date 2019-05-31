#include <cstdio>

int compose(int a, int b) {
    return a * 10 + b;
}

int main() {
    int n, a[10], result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                result += compose(a[i], a[j]);
            }
        }
    }
    printf("%d", result);
    return 0;
}

