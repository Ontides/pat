/**
 1048 数字加密 (20分)
 本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

 输入格式：
 输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

 输出格式：
 在一行中输出加密后的结果。

 输入样例：
 1234567 368782971
 
 输出样例：
 3695Q8118
 */
#include <cstdio>
#include <cmath>
#include <cstring>
int getNum(char a[], int index) {
    if (index < 0) {
        return 0;
    } else {
        return a[index] - '0';
    }
}
int main() {
    char a[101], b[101];
    char numMap[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    scanf("%s %s", a, b);
    int lenA = (int)strlen(a), lenB = (int)strlen(b);
    int max = fmax(lenA, lenB);
    char result[max+1];
    for (int i = lenA-1, j = lenB-1; i >= 0 || j >= 0; i--, j--) {
        if ((lenA-i) % 2) {
            //如果是奇数位
            result[max - (lenA-i)] = numMap[(getNum(a, i) + getNum(b, j)) % 13];
        } else {
            //如果是偶数位
            result[max - (lenA-i)] = numMap[(getNum(b, j) - getNum(a, i) + 10) % 10];
        }
    }
    //由于前面按字符手动赋值，需要补上结束标志
    result[max] = '\0';
    printf("%s\n", result);
    return 0;
}

