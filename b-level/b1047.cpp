#include <cstdio>

int main() {
    int n, score[1010] = {}, curTeamNo, useless, singleScore, chanpionNo = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &curTeamNo);
        getchar();
        scanf("%d %d", &useless, &singleScore);
        score[curTeamNo] += singleScore;
        if (score[curTeamNo] > score[chanpionNo]) {
            chanpionNo = curTeamNo;
        }
    }
    printf("%d %d", chanpionNo, score[chanpionNo]);
    return 0;
}

