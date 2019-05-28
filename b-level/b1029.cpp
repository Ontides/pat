#include <cstdio>
#include <cstring>

int main() {
    char input1[90], input2[90];// 输入的两行
    int gap = 'a' - 'A', broken[40] = {}, brokenCount = 0;// broken数组由坏掉的键对应数字组成
    scanf("%s %s", input1, input2);
    int len = strlen(input1);
    int pos1 = 0, pos2 = 0;
    while (pos1 < len) {
        if (input1[pos1] == input2[pos2]) {//如果对应，则看下一个字符
            pos2++;
        } else {
            int temp = (int)input1[pos1];
            // 如果是小写字母，转换为大写
            if (temp >= 'a' && temp <= 'z') {
                temp -= gap;
            }
            // 判断该坏道的键是否已经存在过
            int flag = true;
            for (int i = 0; i < brokenCount; i++) {
                if (broken[i] == temp) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                broken[brokenCount++] = temp;
            }
        }
        pos1++;
    }
    for (int i = 0; i < brokenCount; i++) {
        printf("%c", (char)broken[i]);
    }
    return 0;
}

