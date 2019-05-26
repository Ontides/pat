#include <cstdio>
#include <cstring>

int main() {
    char input[101], numMap[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int count = 0, len, result[4], resultLen = 0; //len为输入数字位数，count为各数字相加的结果，resultLen为结果数字的位数
    scanf("%s", input);
    len = strlen(input);
    for (int i = 0; i < len; i++) {
        count += (int)(input[i] - '0');
    }
    while (count > 0) {
        int temp = count % 10;
        result[resultLen++] = temp;
        count /= 10;
    }
    for (int i = resultLen - 1; i >= 0; i--) {
        printf("%s", numMap[result[i]]);
        if (i) {
            printf(" ");
        }
    }
    return 0;
}

