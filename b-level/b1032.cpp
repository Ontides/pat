#include <cstdio>
int record[100001] = {}; //记录学校总分
int main() {
    int n, targetSchool = 1; // targetSchool为总分最高的学校id
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int schoolNo, grade;
        scanf("%d %d", &schoolNo, &grade);
        record[schoolNo] += grade;
    }
    for (int i = 1; i <= n; i++) {
        if (record[targetSchool] < record[i]) {
            targetSchool = i;
        }
    }
    printf("%d %d", targetSchool, record[targetSchool]);
    return 0;
}

