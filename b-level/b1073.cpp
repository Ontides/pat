/**
 1073 多选题常见计分法 (20分)
 批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：如果考生选择了部分正确选项，并且没有选择任何错误选项，则得到 50% 分数；如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助老师批改多选题，并且指出哪道题的哪个选项错的人最多。

 输入格式：
 输入在第一行给出两个正整数 N（≤1000）和 M（≤100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

 输出格式：
 按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后 1 位。最后输出错得最多的题目选项的信息，格式为：错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号。如果有并列，则每行一个选项，按题目编号递增顺序输出；再并列则按选项号递增顺序输出。行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

 输入样例 1：
 3 4
 3 4 2 a c
 2 5 1 b
 5 3 2 b c
 1 5 4 a b d e
 (2 a c) (3 b d e) (2 a c) (3 a b e)
 (2 a c) (1 b) (2 a b) (4 a b d e)
 (2 b d) (1 e) (1 c) (4 a b c d)

 输出样例 1：
 3.5
 6.0
 2.5
 2 2-e
 2 3-a
 2 3-b
 
 输入样例 2：
 2 2
 3 4 2 a c
 2 5 1 b
 (2 a c) (1 b)
 (2 a c) (1 b)

 输出样例 2：
 5.0
 5.0
 Too simple
 */
#include <cstdio>
#include <algorithm>
using namespace std;

struct question {
    int wrongPersonCount = 0;
    int fullScore;//题目满分
    int optionCount;//题目选项数量
    int correctOptionCount;//正确选项数量
    int index;//题目编号
    char correctOption[6];//正确选项
    int wrongOptionRecord[5] = {0};//学生选择的错误选项个数
    int maxWrongOptionCount = 0;//最大错误选项个数
};
bool cmp(question a, question b) {
    return a.maxWrongOptionCount > b.maxWrongOptionCount;
}
void getMaxWrongOptionCount(question &q) {
    for (int i = 0; i < 5; i++) {
        if (q.wrongOptionRecord[i] > q.maxWrongOptionCount) {
            q.maxWrongOptionCount = q.wrongOptionRecord[i];
        }
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    question q[m];
    //输入题目信息
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &q[i].fullScore, &q[i].optionCount, &q[i].correctOptionCount);
        getchar();
        for (int j = 0; j < q[i].correctOptionCount; j++) {
            scanf("%c", &q[i].correctOption[j]);
            q[i].correctOption[q[i].correctOptionCount] = '\0';
            getchar();
        }
        q[i].index = i + 1;
    }
    //录入学生答题信息，并评分
    for (int i = 0; i < n; i++) {
        double score = 0;
        for (int j = 0; j < m; j++) {
            int selectedCount;//该学生对应题目选择的数量
            scanf("(%d", &selectedCount);
            char selectedAnswer[selectedCount];
            for (int k = 0; k < selectedCount-1; k++) {
                scanf(" %c", &selectedAnswer[k]);
            }
            scanf(" %c)", &selectedAnswer[selectedCount-1]);
            int correct = 2;//当前题目是否回答正确 2：完全正确 1：部分正确 0 错误
            
            for (int k = 0, curIndex = 0; k < q[j].correctOptionCount || k < selectedCount; k++) {
                if (selectedAnswer[curIndex] == q[j].correctOption[k]) {
                    //答案正确，学生答案对应指针+1
                    curIndex++;
                } else {
                    bool curOptionRight = false;//学生答案里是否有当前正确选项
                    for (int l = curIndex + 1; l < selectedCount; l++) {
                        if (selectedAnswer[l] == q[j].correctOption[k]) {
                            //如果后面匹配到和当前正确答案相同的选项，则中间的选项全部为错误选项
                            for (int p = curIndex; p < l; p++) {
                                q[j].wrongOptionRecord[selectedAnswer[p]-'a']++;
                            }
                            curOptionRight = true;
                            curIndex = l+1;
                            correct = 0;
                            break;
                        }
                    }
                    if (!curOptionRight) {
                        //当前正确选项漏选
                        q[j].wrongOptionRecord[q[j].correctOption[k] - 'a']++;
                        correct = correct > 0 ? 1 : 0;
                    }
                }
                if (curIndex == selectedCount) {
                    //如果当前学生选项已经过完，则正确答案里剩下的选项全部为漏选
                    if ((k+1) < q[j].correctOptionCount) {
                        for (int l = k+1; l < q[j].correctOptionCount; l++) {
                            q[j].wrongOptionRecord[q[j].correctOption[l] - 'a']++;
                        }
                        correct = correct > 0 ? 1 : 0;
                    }
                    break;
                }
                if ((k+1) == q[j].correctOptionCount && curIndex < selectedCount) {
                    //如果当前正确答案已经过完，则学生答案里剩余选项全部为错选
                    for (int l = curIndex; l < selectedCount; l++) {
                        q[j].wrongOptionRecord[selectedAnswer[l] - 'a']++;
                    }
                    correct = 0;
                    break;
                }
            }
            //根据该题是否回答正确做相应处理
            switch (correct) {
                case 2:
                    //完全正确
                    score += (q[j].fullScore / 1.0);
                    break;
                case 1:
                    //部分正确
                    score += (q[j].fullScore / 2.0);
                    break;
                default:
                    break;
            }
            getchar();//吸收空格和换行符
        }
        printf("%.1f\n", score);
    }
    //获取每道题最多错误选项个数
    for (int i = 0; i < m; i++) {
        getMaxWrongOptionCount(q[i]);
    }
    //对各个题目根据错误人数排序
    sort(q, q + m, cmp);
    int maxWrongOptionCount = q[0].maxWrongOptionCount;
    if (maxWrongOptionCount == 0) {
        printf("Too simple\n");
    } else {
        for (int i = 0; q[i].maxWrongOptionCount == maxWrongOptionCount; i++) {
            for (int j = 0; j < 5; j++) {
                if (q[i].wrongOptionRecord[j] == maxWrongOptionCount) {
                    printf("%d %d-%c\n", maxWrongOptionCount, q[i].index, (char)(j + 'a'));
                }
            }
        }
    }
    return 0;
}


