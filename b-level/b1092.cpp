#include <cstdio>

int main() {
    int N, M, temp, bestCount = 0;
    int mooncake[1010] = {0};
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &temp);
            mooncake[j] += temp;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (mooncake[i] > bestCount) {
            bestCount = mooncake[i];
        }
    }
    printf("%d\n", bestCount);
    bool first = true;
    for (int i = 1; i <= N; i++) {
        if (mooncake[i] == bestCount) {
            if (first) {
                printf("%d", i);
                first = false;
            } else {
                printf(" %d", i);
            }
        }
    }
    return 0;
}

