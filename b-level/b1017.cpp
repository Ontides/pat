/*
 1017 A除以B (20 分)
 本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。
 
 输入格式：
 输入在一行中依次给出 A 和 B，中间以 1 空格分隔。
 
 输出格式：
 在一行中依次输出 Q 和 R，中间以 1 空格分隔。
 
 输入样例：
 123456789050987654321 7
 输出样例：
 17636684150141093474 3
 */
#include <cstdio>
#include <cstring>
int main() {
    char A[1010];
    int B, R = 0;
    scanf("%s%d", A, &B);
    int len = (int)strlen(A);
    for (int i = 0; i < len; i++) {
        R = R * 10 + (A[i] - '0');
        if (R >= B) {
            printf("%d", R / B);
        } else if (i) {
            printf("0");
        }
        R = R % B;
    }
    // 如果A本身小于B则商为0
    if (len == 1 && A[0] - '0' < B) {
        printf("0");
    }
    printf(" %d", R);
    return 0;
}

