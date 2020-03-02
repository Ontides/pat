/**
 1059 C语言竞赛 (20分)
 C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：
 0、冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
 1、排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
 2、其他人将得到巧克力。
 给定比赛的最终排名以及一系列参赛者的 ID，你要给出这些参赛者应该获得的奖品。

 输入格式：
 输入第一行给出一个正整数 N（≤10^4），是参赛者人数。随后 N 行给出最终排名，每行按排名顺序给出一位参赛者的 ID（4 位数字组成）。接下来给出一个正整数 K 以及 K 个需要查询的 ID。

 输出格式：
 对每个要查询的 ID，在一行中输出 ID: 奖品，其中奖品或者是 Mystery Award（神秘大奖）、或者是 Minion（小黄人）、或者是 Chocolate（巧克力）。如果所查 ID 根本不在排名里，打印 Are you kidding?（耍我呢？）。如果该 ID 已经查过了（即奖品已经领过了），打印 ID: Checked（不能多吃多占）。

 输入样例：
 6
 1111
 6666
 8888
 1234
 5555
 0001
 6
 8888
 0001
 1111
 2222
 8888
 2222
     
 输出样例：
 8888: Minion
 0001: Chocolate
 1111: Mystery Award
 2222: Are you kidding?
 8888: Checked
 2222: Are you kidding?
 */
#include <cstdio>
#include <cmath>
// 判断是否为素数
bool isPrime(int n) {
    bool result = true;
    int nSqrt = floor(sqrt((double)n));
    if (n >= 4) {
        if (n % 6 != 1 && n % 6 != 5) {
            result = false;
        } else {
            for (int i = 5; i <= nSqrt; i+=6) {
                if (n % i == 0 || n % (i+2) == 0) {
                    result = false;
                    break;
                }
            }
        }
    }
    return result;
}
int main() {
    int n, k, rank[10010] = {0}, temp;
    const char RANK_MAP[5][20] = {"Are you kidding?", "Mystery Award", "Minion", "Chocolate", "Checked"};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        if (i == 1) {
            rank[temp] = 1;
        } else if (isPrime(i)) {
            rank[temp] = 2;
        } else {
            rank[temp] = 3;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &temp);
        printf("%04d: %s\n", temp, RANK_MAP[rank[temp]]);
        if (rank[temp]) {
            rank[temp] = 4;
        }
    }
    return 0;
}

