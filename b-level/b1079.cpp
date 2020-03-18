/**
 1079 延迟的回文数 (20分)
 给定一个 k+1 位的正整数 N，写成 ak⋯a​1a0​ 的形式，其中对所有 i 有 0≤a​i​​ <10 且 a​k​​ >0。N 被称为一个回文数，当且仅当对所有 i 有 ai​​ =a​k−i​​ 。零也被定义为一个回文数。
 非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。（定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number ）
 给定任意一个正整数，本题要求你找到其变出的那个回文数。

 输入格式：
 输入在一行中给出一个不超过1000位的正整数。

 输出格式：
 对给定的整数，一行一行输出其变出回文数的过程。每行格式如下
 A + B = C
 其中 A 是原始的数字，B 是 A 的逆转数，C 是它们的和。A 从输入的整数开始。重复操作直到 C 在 10 步以内变成回文数，这时在一行中输出 C is a palindromic number.；或者如果 10 步都没能得到回文数，最后就在一行中输出 Not found in 10 iterations.。

 输入样例 1：
 97152
 输出样例 1：
 97152 + 25179 = 122331
 122331 + 133221 = 255552
 255552 is a palindromic number.

 输入样例 2：
 196
 输出样例 2：
 196 + 691 = 887
 887 + 788 = 1675
 1675 + 5761 = 7436
 7436 + 6347 = 13783
 13783 + 38731 = 52514
 52514 + 41525 = 94039
 94039 + 93049 = 187088
 187088 + 880781 = 1067869
 1067869 + 9687601 = 10755470
 10755470 + 07455701 = 18211171
 Not found in 10 iterations.
 */
#include <cstdio>
#include <cstring>
#include <cmath>
//判断是否是回文数
bool isPalindrome(char n[]) {
    int len = (int)strlen(n);
    bool flag = true;
    for (int i = 0; i <= int(len / 2); i++) {
        if (n[i] != n[len-1-i]) {
            flag = false;
            break;
        }
    }
    return flag;
}
//逆转数字
void reverse(char n[], char m[]) {
    int len = (int)strlen(n);
    for (int i = 0; i < len; i++) {
        m[i] = n[len-1-i];
    }
    m[len] = '\0';
}
//字符转数字 '9' -> 9
int charToInt(char c) {
    return (int)(c - '0');
}
//数字相加
void plus(char n[], char m[]) {
    int len = (int)strlen(n);
    int carry = 0;
    for (int i = len-1; i >= 0; i--) {
        int sum = charToInt(n[i]) + charToInt(m[i]) + carry;
        carry = floor(sum / 10);
        n[i] = (char)((sum % 10) + '0');
    }
    //最高位多一位进位，则所有位后移一位，首位为1
    if (carry > 0) {
        for (int i = len; i >= 0; i--) {
            n[i] = n[i-1];
        }
        n[0] = '1';
        n[len+1] = '\0';
    }
}
int main(){
    char n[1010];
    int calCount = 0;
    bool flag = true;
    scanf("%s", n);
    while (!isPalindrome(n)) {
        if (calCount >= 10) {
            flag = false;
            break;
        }
        //获得逆转数字
        char nReverse[strlen(n)+1];
        reverse(n, nReverse);
        printf("%s + %s = ", n, nReverse);
        //获得相加后的数字
        plus(n, nReverse);
        printf("%s\n", n);
        calCount++;
    }
    if (flag) {
        printf("%s is a palindromic number.\n", n);
    } else {
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}
