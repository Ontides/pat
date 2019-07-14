#include <cstdio>
#include <cmath>
#include <cstring>

bool isPrime(int n) {
    double sqrt_n;
    if (n == 1) {
        return false;
    }
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

void printResult(int n, int length) {
    int result[11];
    for (int i = 0; i < length; i++) {
        result[i] = n % 10;
        n /= 10;
    }
    for (int i = length - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
}

int main() {
    int L, K, temp = 0;
    char N[1010];
    
    scanf("%d%d", &L, &K);
    scanf("%s", N);
    bool flag = false;
    for (int i = 0; i <= L - K; i++) {
        temp = 0;
        for (int j = i; j < i + K; j++) {
            temp = temp * 10 + (N[j] - '0');
        }
        if (isPrime(temp)) {
            flag = true;
            printResult(temp, K);
            break;
        }
        if (flag) {
            break;
        }
    }
    if (!flag) {
        printf("404\n");
    }
    return 0;
}

