#include <cstdio>
#include <cmath>

int main() {
    int n, k, tempScore;
    int score[101] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tempScore);
        score[tempScore]++;
    }
    scanf("%d", &k);
    scanf("%d", &tempScore);
    printf("%d", score[tempScore]);
    for (int i = 1; i < k; i++) {
        scanf("%d", &tempScore);
        printf(" %d", score[tempScore]);
    }
    return 0;
}

