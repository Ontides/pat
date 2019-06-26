#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    double sqrt_n;
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 6 != 1 && n % 6 != 5) {
        return false;
    }
    sqrt_n = floor(sqrt((double)n));
    for (int i = 5; i <= sqrt_n; i += 6) {
        if (n % i == 0 || n % (i+2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, count = 0;
    bool start = false;//开始增加素数对数
    scanf("%d", &n);
    for (int i = 3; i <= n; i += 2) {
        if (isPrime(i)) {
            if (start) {
                count++;
            } else {
                start = true;
            }
        } else {
            start = false;
        }
    }
    printf("%d", count);
    return 0;
}

