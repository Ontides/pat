#include <cstdio>

int main() {
    int M, N, A, B, replacement, temp;
    scanf("%d%d%d%d%d", &M, &N, &A, &B, &replacement);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &temp);
            if (j) {
                printf(" ");
            }
            if (temp >= A && temp <= B) {
                printf("%03d", replacement);
            } else {
                printf("%03d", temp);
            }
        }
        printf("\n");
    }
    return 0;
}

