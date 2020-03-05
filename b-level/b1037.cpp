/**
 1037 在霍格沃茨找零钱 (20分)
 如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

 输入格式：
 输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 [0, 10^7​​ ] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。
 输出格式：
 在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

 输入样例 1：
 10.16.27 14.1.28
 输出样例 1：
 3.2.1
     
 输入样例 2：
 14.1.28 10.16.27
 输出样例 2：
 -3.2.1
 */
#include <cstdio>
struct money {
    int galleon;
    int sickle;
    int knut;
    int sign = 1;
};
//仅支持两个正数相减
money minus (money a, money b) {
    money result;
    result.galleon = a.galleon - b.galleon;
    result.sickle = a.sickle - b.sickle;
    result.knut = a.knut - b.knut;
    //判断是否需要从sickle借一位
    if (result.knut < 0) {
        result.sickle -= 1;
        result.knut += 29;
    }
    //判断是否需要从galleon借一位
    if (result.sickle < 0) {
        result.galleon -= 1;
        result.sickle += 17;
    }
    //判断是否结果是负数，如果是负数，则通过借位让所有值都变成负数，最后取反
    if (result.galleon < 0) {
        result.sign = -1;
        if (result.sickle > 0) {
            result.galleon++;
            result.sickle -= 17;
        }
        if (result.knut > 0) {
            result.sickle++;
            result.knut -= 29;
        }
        result.galleon = -result.galleon;
        result.sickle = -result.sickle;
        result.knut = -result.knut;
    }
    return result;
}
void moneyPrint(money a) {
    //判断符号是否为负
    if (!~a.sign) {
        printf("-");
    }
    printf("%d.%d.%d\n", a.galleon, a.sickle, a.knut);
}
int main() {
    money expectPayment, realPayment;
    scanf("%d.%d.%d", &expectPayment.galleon, &expectPayment.sickle, &expectPayment.knut);
    scanf("%d.%d.%d", &realPayment.galleon, &realPayment.sickle, &realPayment.knut);
    moneyPrint(minus(realPayment, expectPayment));
    return 0;
}

