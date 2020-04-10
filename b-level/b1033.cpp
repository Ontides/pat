/**
 1033 旧键盘打字 (20分)
 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

 输入格式：
 输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过 10^5个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。题目保证第 2 行输入的文字串非空。
 注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

 输出格式：
 在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

 输入样例：
 7+IE.
 7_This_is_a_test.
     
 输出样例：
 _hs_s_a_tst
 */
#include <cstdio>
#include <cstring>
using namespace std;
//判断是否数组是否存在某个字符，这里其实用map会更好一些，不需要这么手动查找，速度也更快
bool exist(char str[], char c) {
    int len = (int)strlen(str);
    bool result = false;
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            result = true;
            break;
        }
    }
    return result;
}
int main() {
    char badKey[100], input[100001];
    fgets(badKey, 100, stdin);//考虑到可能没有坏键，第一行可能为空行
    scanf("%s", input);
    int inputLen = (int)strlen(input),
        badKeyLen = (int)strlen(badKey);
    bool shiftForbidden = false;//shift是否被禁用
    for (int i = 0; i < badKeyLen; i++) {
        if (badKey[i] == '+') {
            shiftForbidden = true;
        }
    }
    bool existPrintedChar = false;
    for (int i = 0; i < inputLen; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z' && shiftForbidden) {
            continue;
        } else {
            char curChar = input[i];
            if (curChar >= 'a' && curChar <= 'z') {
                //如果是小写字母，则转化成大写字母
                curChar = (char)(input[i] - 'a' + 'A');
            }
            if (exist(badKey, curChar)) {
                continue;
            } else {
                printf("%c", input[i]);
                existPrintedChar = true;
            }
        }
    }
    //不存在输出字符则输出空行（不过经过测试，不打印也是可以通过）
    if (!existPrintedChar) {
        printf("\n");
    }
    return 0;
}

