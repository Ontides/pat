/**
 1050 螺旋矩阵 (25分)
 本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

 输入格式：
 输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10^4​​ ，相邻数字以空格分隔。

 输出格式：
 输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

 输入样例：
 12
 37 76 20 98 76 42 53 95 60 81 58 93
     
 输出样例：
 98 95 93
 42 37 81
 53 20 76
 58 60 76
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct step {
    int x;
    int y;
    step(int _x, int _y) : x(_x), y(_y) {}
};
//从大到小比较函数
bool cmp (int a, int b) {
    return a > b;
}
int main() {
    int N;
    scanf("%d", &N);
    int m = 0, n = 0;
    //计算m和n
    for (m = (int)ceil(sqrt((double)N)); m <= N; m++) {
        if (N % m == 0) {
            n = N / m;
            break;
        }
    }
    
    int result[m][n], input[N-1];
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
    sort(input, input + N, cmp);
    
    //初始化
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }

    //四个行走方向
    const int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    //按螺旋方式填数据 direction为行走方向
    for (int i = 0, j = 0, count = 0, direction = 0; count < N; i += step[direction][0], j+= step[direction][1]) {
        result[i][j] = input[count++];
        int nextI = i + step[direction][0], nextJ = j + step[direction][1];
        //如果下一步不合法则改变方向
        if (nextI >= m || nextI < 0 || nextJ >= n || nextJ < 0 || result[nextI][nextJ] != 0) {
            direction = (direction + 1) % 4;
        }
    }
    //打印结果
    for (int i = 0; i < m; i++) {
        printf("%d", result[i][0]);
        for (int j = 1; j < n; j++) {
            printf(" %d", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

