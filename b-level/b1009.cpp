#include <cstdio>

int main() {
    char a[100][100];
    int count = 0; //单词数量
    while (scanf("%s", a[count]) != EOF){
        count++;
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", a[i]);
        if (i) {
            printf(" ");
        }
    }
    return 0;
}

