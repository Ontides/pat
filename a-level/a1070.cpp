/*
1070 Mooncake (25分)
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.
Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (≤1000), the number of different kinds of mooncakes, and D (≤500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

Sample Input:
3 200
180 150 100
7.5 7.2 4.5

Sample Output:
9.45
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

