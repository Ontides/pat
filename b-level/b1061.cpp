#include <cstdio>

int main() {
    int n, m, score, temp;
    int fullMarks[100], answers[100];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &fullMarks[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &answers[i]);
    }
    for (int i = 0; i < n; i++) {
        score = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &temp);
            if (temp == answers[j]) {
                score += fullMarks[j];
            }
        }
        printf("%d\n", score);
    }
    return 0;
}

