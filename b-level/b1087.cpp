#include <cstdio>

int main() {
    int n, count = 0, cur = -1, temp;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        temp = i/2 + i/3 + i/5;
        if (temp != cur) {
            count++;
            cur = temp;
        }
    }
    printf("%d", count);
    return 0;
}

