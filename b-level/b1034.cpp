/**
 1034 有理数四则运算 (20分)
 本题要求编写程序，计算 2 个有理数的和、差、积、商。

 输入格式： 输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

 输出格式：
 分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

 输入样例 1：
 2/3 -4/2

 输出样例 1：
 2/3 + (-2) = (-1 1/3)
 2/3 - (-2) = 2 2/3
 2/3 * (-2) = (-1 1/3)
 2/3 / (-2) = (-1/3)

 输入样例 2：
 5/3 0/6

 输出样例 2：
 1 2/3 + 0 = 1 2/3
 1 2/3 - 0 = 1 2/3
 1 2/3 * 0 = 0
 1 2/3 / 0 = Inf
 */

//由于运算过程两个数相乘可能超过int范围，所以方便起见都用long long
#include <cstdio>
#include <cmath>

//最大公约数
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

//分数格式
struct fraction {
    long long up, down;
};

//分数化简（约分等）
fraction reduction(fraction a) {
    if (a.down < 0) {
        a.up = -a.up;
        a.down = -a.down;
    }
    if (a.up == 0) {
        a.down = 1;
    } else {
        long long aGCD = gcd(fabs(a.up), fabs(a.down));
        a.up /= aGCD;
        a.down /= aGCD;
    }
    return a;
}

fraction add(fraction a, fraction b) {
    fraction result;
    result.up = a.up * b.down + a.down * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}

fraction minus(fraction a, fraction b) {
    fraction result;
    result.up = a.up * b.down - a.down * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}

fraction mul(fraction a, fraction b) {
    fraction result;
    result.up = a.up * b.up;
    result.down = a.down * b.down;
    return reduction(result);
}

fraction div(fraction a, fraction b) {
    fraction result;
    if (b.up == 0) {
        result.up = 1;
        result.down = 0;
    } else {
        result.up = a.up * b.down;
        result.down = a.down * b.up;
    }
    return reduction(result);
}

fraction operation(fraction a, fraction b, char targetOperator) {
    if (targetOperator == '+') {
        return add(a, b);
    } else if (targetOperator == '-') {
        return minus(a, b);
    } else if (targetOperator == '*') {
        return mul(a, b);
    } else {
        return div(a, b);
    }
}

//按题目要求格式打印
void printFraction(fraction a) {
    a = reduction(a);
    if (a.down == 0) {
        printf("Inf");
    } else {
        a.up < 0 && printf("(");
        if (a.down == 1) {
            printf("%lld", a.up);
        } else if (fabs(a.up) > a.down) {
            printf("%lld %lld/%lld", a.up / a.down, (long long)fabs(a.up) % a.down, a.down);
        } else {
            printf("%lld/%lld", a.up, a.down);
        }
        a.up < 0 && printf(")");
    }
}

int main(){
    const char operatorMap[4] = {'+', '-', '*', '/'};
    fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    a = reduction(a);
    b = reduction(b);
    for (int i = 0; i < 4; i++) {
        printFraction(a);
        printf(" %c ", operatorMap[i]);
        printFraction(b);
        printf(" = ");
        printFraction(operation(a, b, operatorMap[i]));
        printf("\n");
    }
    return 0;
}

