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
    int m, n, count = 0;
    scanf("%d %d", &m, &n);
    int i = 2;
    while (count < n) {
        if (isPrime(i)) {
            count++;
            if (count >= m && count <= n) {
                if (count == n) {
                    printf("%d", i);
                    break;
                } else if ((count - m) % 10 == 9) {
                    printf("%d\n", i);
                } else {
                    printf("%d ", i);
                }
            }
        }
        i++;
    }
    return 0;
}

