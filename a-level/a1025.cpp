#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Test {
    char registration_number[15];// 考号
    int score;// 成绩
    int final_rank;// 总排名
    int location_number;// 考场号
    int local_rank;// 考场排名
} test[30010];

bool cmp (Test test1, Test test2) {
    if (test1.score != test2.score) {
        return test1.score > test2.score;
    } else {
        return strcmp(test1.registration_number, test2.registration_number) < 0;
    }
}

int main() {
    int n, m, count = 0;// count为考生总和
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%s %d", test[count].registration_number, &test[count].score);
            test[count].location_number = i;// 输入数据的时候标注考场号
            count++;
        }
        sort(test + count - m, test + count, cmp);// 对当前考场学生成绩排序
        // 标注当前考场成绩排名
        test[count - m].local_rank = 1;
        for (int j = count - m + 1; j < count; j++) {
            if (test[j].score == test[j - 1].score) {
                test[j].local_rank = test[j - 1].local_rank;
            } else {
                test[j].local_rank = j - count + m + 1;
            }
        }
    }
    sort(test, test + count, cmp);// 全部考场数据输入完毕后就进行整体排序
    // 标注全体考生成绩排名
    test[0].final_rank = 1;
    for (int i = 1; i < count; i++) {
        if (test[i].score == test[i-1].score) {
            test[i].final_rank = test[i-1].final_rank;
        } else {
            test[i].final_rank = i + 1;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s %d %d %d\n", test[i].registration_number, test[i].final_rank, test[i].location_number, test[i].local_rank);
    }
    return 0;
}

