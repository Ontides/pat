#include <cstdio>

int main() {
    int n, rows; //rows为要打印的行数
    char c;
    scanf("%d %c", &n, &c);
    rows = (n % 2) ? n / 2 + 1 : n / 2;
    for (int i = 1; i <= rows; i++) {
        if (i == 1 || i == rows) { //第一行和最后一行全为字符
            for (int j = 0; j < n; j++) {
                printf("%c", c);
            }
            printf("\n");
        } else { //其他行中间全为空格
            printf("%c", c);
            for (int j = 1; j < n - 1; j++) {
                printf(" ");
            }
            printf("%c\n", c);
        }
    }
    return 0;
}

