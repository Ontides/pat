#include <cstdio>
#include <cstring>

int main() {
    char n[1010];
    int count[10] = {};
    scanf("%s", n);
    int len = strlen(n);
    for (int i = 0; i < len; i++) {
        count[n[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (count[i]) {
            printf("%d:%d\n", i, count[i]);
        }
    }
    return 0;
}

