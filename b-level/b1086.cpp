#include <cstdio>

int main() {
    int a, b, product, result = 0;
    scanf("%d%d", &a, &b);
    product = a * b;
    while (product > 0) {
        result = result * 10 + (product % 10);
        product /= 10;
    }
    printf("%d", result);
    return 0;
}

