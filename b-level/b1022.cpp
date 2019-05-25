#include <cstdio>
int record[100] = {};
int main() {
    int d, count = 0;
    long long a, b, temp;
    scanf("%lld %lld %d", &a, &b, &d);
    temp = a + b;
    do {
        record[count++] = temp % d;
        temp /= d;
    } while (temp != 0);
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", record[i]);
    }
    return 0;
}

