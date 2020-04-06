/**
 1024 科学计数法 (20分)
 科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。
 现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

 输入格式：
 每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

 输出格式：
 对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

 输入样例 1：
 +1.23400E-03

 输出样例 1：
 0.00123400

 输入样例 2：
 -1.2E+10

 输出样例 2：
 -12000000000
 */
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int main(){
    char input[10000];
    int exponentPart = 0, exponentIndex = -1, dotIndex = -1;
    char integerSign, exponentSign = '+';
    scanf("%c%s", &integerSign, input);
    if (integerSign == '-') {
        printf("-");
    }
    //获取小数点下标，并获取指数数值
    for (int i = 0; i < (int)strlen(input); i++) {
        if (input[i] == '.') {
            dotIndex = i;
            continue;
        }
        if (~exponentIndex) {
            exponentPart = exponentPart * 10 + (input[i] - '0');
        } else if (input[i] == '+' || input[i] == '-') {
            exponentIndex = i;
            exponentSign = input[i];
        }
    }
    if (exponentSign == '+') {
        int len = max(exponentIndex-1, exponentPart+2);
        for (int i = 0; i < len; i++) {
            if (input[i] == '.') {
                continue;
            }
            if (i < exponentIndex - 1) {
                printf("%c", input[i]);
            } else {
                printf("0");
            }
            if (i == dotIndex + exponentPart && i != len-1) {
                //如果不是最后一位，则补上移位后的小数点
                printf(".");
            }
        }
    } else if (exponentSign == '-') {
        int start = -exponentPart + 1;
        printf("0.");
        for (int i = start; i < exponentIndex-1; i++) {
            if (i < 0) {
                printf("0");
            } else {
                if (input[i] != '.') {
                    printf("%c", input[i]);
                }
            }
        }
    }
    return 0;
}

