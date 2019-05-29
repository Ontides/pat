#include <cstdio>
#include <cstring>

int main() {
    char input1[1010], input2[1010];
    char flag[1010] = {};// 标记哪些珠子已经用过了
    int len1, len2, notFoundCount = 0, remainCount = 0;
    scanf("%s %s", input1, input2);
    len1 = strlen(input1);
    len2 = strlen(input2);
    for (int i = 0; i < len2; i++) {
        bool found = false;
        for (int j = 0; j < len1; j++) {
            if (flag[j] != 1 && input2[i] == input1[j]) {// 跳过flag标记为1的珠子
                flag[j] = 1;
                found = true;
                break;
            }
        }
        if (!found) {
            notFoundCount++;
        }
    }
    remainCount = len1;
    for (int i = 0; i < len1; i++) {
        if (flag[i] == 1) {
            remainCount--;
        }
    }
    if (notFoundCount == 0) {
        printf("Yes %d\n", remainCount);
    } else {
        printf("No %d\n", notFoundCount);
    }
    return 0;
}

