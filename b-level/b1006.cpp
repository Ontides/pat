#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int intHund = n / 100;
    int intTen = (n / 10) % 10;
    int intSingle = n % 10;
    for (int i = 0; i < intHund; i++) {
        printf("B");
    }
    for (int i = 0; i < intTen; i++) {
        printf("S");
    }
    for (int i = 1; i <= intSingle; i++) {
        printf("%d", i);
    }
    return 0;
}

