/**
 1051 复数乘法 (15分)
 复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i^2​​ =−1；也可以写成极坐标下的指数形式 (R×e^​(Pi)​​ )，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 R(cos(P)+isin(P))。
 现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

 输入格式：
 输入在一行中依次给出两个复数的 R​1, P​1​​, R​2​ , P​2，数字间以空格分隔。

 输出格式：
 在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该写成 A-|B|i 的形式。

 输入样例：
 2.3 3.5 5.2 0.4
 输出样例：
 -8.68-8.23i
 */
#include <cstdio>
#include <cmath>
struct complexNum {
    double r, p, a, b;
};
complexNum mul (complexNum c1, complexNum c2) {
    complexNum c;
    c.a = c1.r * cos(c1.p) * c2.r * cos(c2.p) - c1.r * sin(c1.p) * c2.r * sin(c2.p);
    c.b = c1.r * cos(c1.p) * c2.r * sin(c2.p) + c1.r * sin(c1.p) * c2.r * cos(c2.p);
    return c;
}
int main() {
    complexNum c1, c2;
    scanf("%lf %lf %lf %lf", &c1.r, &c1.p, &c2.r, &c2.p);
    complexNum c = mul(c1, c2);
    //判0
    if (fabs(c.a) < 0.001) {
        printf("0.00");
    } else {
        printf("%.2f", c.a);
    }
    //判0
    if (fabs(c.b) < 0.001) {
        printf("+0.00i");
    } else if (c.b > 0) {
        printf("+%.2fi", c.b);
    } else {
        printf("%.2fi", c.b);
    }
    return 0;
}

