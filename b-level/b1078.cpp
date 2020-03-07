/**
 1078 字符串压缩与解压 (20分)
 文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。
 解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。
 本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。

 输入格式：
 输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过 1000 个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过 1MB。

 输出格式：
 根据要求压缩或解压字符串，并在一行中输出结果。

 输入样例 1：
 C
 TTTTThhiiiis isssss a   tesssst CAaaa as
 输出样例 1：
 5T2h4is i5s a3 te4st CA3a as

 输入样例 2：
 D
 5T2h4is i5s a3 te4st CA3a as10Z
 输出样例 2：
 TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
 */
#include <cstdio>
#include <cstring>
int main() {
    char instruction, input[1010];
    scanf("%c", &instruction);
    getchar();
    fgets(input, 1010, stdin);
    int len = (int)strlen(input);
    if (instruction == 'C') {
        int printCount = 1;//记录当前字符重复次数
        for (int i = 0; i < len; i++) {
            if (i < len-1 && input[i+1] == input[i]) {
                printCount++;
            } else {
                if (printCount > 1) {
                    printf("%d", printCount);
                }
                printf("%c", input[i]);
                printCount = 1;
            }
        }
    } else if (instruction == 'D') {
        int printCount = 1;//当前字符打印次数
        for (int i = 0; i < len; i++) {
            if (input[i] >= '0' && input[i] <= '9') {
                if (i && input[i-1] >= '0' && input[i-1] <= '9') {
                    printCount = printCount*10 + input[i] - '0';
                } else {
                    printCount = input[i] - '0';
                }
            } else {
                for (int j = 0; j < printCount; j++) {
                    printf("%c", input[i]);
                }
                printCount = 1;
            }
        }
    }
    return 0;
}

