#include <cstdio>
#include <cmath>

int main() {
    int m;
    long long tempK;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &tempK);
        int kSquare = tempK * tempK;
        int power = floor(log10((double) tempK)) + 1;
        int dividend = (int)pow(10.0, power);
        bool flag = false;
        for (int n = 0; n < 10; n++) {
            if (kSquare * n % dividend == tempK) {
                printf("%d %d\n", n, kSquare * n);
                flag = true;
                break;
            }
        }
        if (!flag) {
            printf("No\n");
        }
    }
    return 0;
}

