/*
1100 Mars Numbers (20分)
People on Mars count their numbers with base 13:
Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:
For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam

Sample Output:
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
//火星文转数字
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
//字符串转数字
int strToInt(char str[]) {
    int result;
    sscanf(str, "%d", &result);
    return result;
}
//数字转火星文并打印
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
//火星文转数字并打印
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

