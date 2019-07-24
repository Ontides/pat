#include <cstdio>

int main() {
    int t;
    long long a, b, c;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a > (c - b)) {
            printf("Case #%d: true\n", i+1);
        } else {
            printf("Case #%d: false\n", i+1);
        }
    }
    return 0;
}

