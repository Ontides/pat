#include <cstdio>
#include <cstring>
struct Student {
    char name[11], sNo[11];
    int score;
};
int main() {
    int n;
    Student bestStudent, worstStudent, tempStudent;
    scanf("%d", &n);
    scanf("%s %s %d", bestStudent.name, bestStudent.sNo, &bestStudent.score);
    strcpy(worstStudent.name, bestStudent.name);
    strcpy(worstStudent.sNo, bestStudent.sNo);
    worstStudent.score = bestStudent.score;
    for (int i = 1; i < n; i++) {
        scanf("%s %s %d", tempStudent.name, tempStudent.sNo, &tempStudent.score);
        if (tempStudent.score < worstStudent.score) {
            strcpy(worstStudent.name, tempStudent.name);
            strcpy(worstStudent.sNo, tempStudent.sNo);
            worstStudent.score = tempStudent.score;
        } else if (tempStudent.score > bestStudent.score) {
            strcpy(bestStudent.name, tempStudent.name);
            strcpy(bestStudent.sNo, tempStudent.sNo);
            bestStudent.score = tempStudent.score;
        }
    }
    printf("%s %s\n%s %s", bestStudent.name, bestStudent.sNo, worstStudent.name, worstStudent.sNo);
    return 0;
}

