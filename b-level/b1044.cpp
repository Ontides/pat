/**
 1044 火星数字 (20分)
 火星人是以 13 进制计数的：
 * 地球人的 0 被火星人称为 tret。
 * 地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
 * 火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
 例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

 输入格式：
 输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

 输出格式：
 对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

 输入样例：
 4
 29
 5
 elo nov
 tam
 
 输出样例：
 hel mar
 may
 115
 13
 */
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const string numToMarsMap[25] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
// 从火星文转化成对应数字大小，如tam->13 hel->26
int marsToNumMap(string str) {
    int index = 0;
    for (int i = 0; i < 25; i++) {
        if (str == numToMarsMap[i]) {
            index = i;
        }
    }
    if (index > 12) {
        return ((index+1) % 13) * 13;
    } else {
        return index;
    }
}
// '123' -> 123
int strToInt(char str[]) {
    int result;
    sscanf(str, "%d", &result);
    return result;
}
void numToMars(int x) {
    if (x <= 12) {
        printf("%s\n", numToMarsMap[x].c_str());
    } else {
        int first = x / 13, second = x % 13;
        if (second) {
            printf("%s %s\n", numToMarsMap[first+12].c_str(), numToMarsMap[second].c_str());
        } else {
            printf("%s\n", numToMarsMap[first+12].c_str());
        }
    }
}
void marsToNum(char mars[]) {
    char first[5], second[5];
    sscanf(mars, "%s %s", first, second);
    string firstStr = first, secondStr = second;
    printf("%d\n", marsToNumMap(firstStr) + marsToNumMap(secondStr));
}
int main() {
    int n;
    char input[10];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(input, 10, stdin);
        if (input[0] >= '0' && input[0] <= '9') {
            numToMars(strToInt(input));
        } else {
            marsToNum(input);
        }
    }
    return 0;
}

