/*
1020 月饼 (25分)
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：
每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

输入样例：
3 20
18 15 10
75 72 45

输出样例：
94.50
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct MoonCake {
    double inventory, totalPrice, averPrice;
} moonCake[1010];

bool cmp(MoonCake a, MoonCake b) {
    return a.averPrice > b.averPrice;
}

int main() {
    int N, D;
    double income = 0.0;
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++) {
        //输入库存
        scanf("%lf", &moonCake[i].inventory);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lf", &moonCake[i].totalPrice);
        //计算单价
        moonCake[i].averPrice = moonCake[i].totalPrice / moonCake[i].inventory;
    }
    //按单价从高到低排序
    sort(moonCake, moonCake + N, cmp);
    //从单价高的开始卖，按贪心原则计算收入
    for (int i = 0; i < N; i++) {
        if (moonCake[i].inventory < D) {
            D -= moonCake[i].inventory;
            income += moonCake[i].totalPrice;
        } else {
            income += moonCake[i].averPrice * D;
            break;
        }
    }
    printf("%.2f\n", income);
    return 0;
}

