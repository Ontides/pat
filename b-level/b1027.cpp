#include <cstdio>
#include <cmath>
#include <cstdlib>

int main() {
    int n, m, remain;
    char symbol;
    scanf("%d %c", &n, &symbol);
    m = floor(sqrt((n+1)/2));
    remain = n - (2 * m * m - 1);
    for (int i = 1; i <= 2 * m - 1; i++) {
        int blankNum = m - 1 - abs((double)i - (double)m);
        int starNum = 2 * m - 1 - blankNum * 2;
        for (int j = 0; j < blankNum; j++) {
            printf(" ");
        }
        for (int j = 0; j < starNum; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
    printf("%d\n", remain);
    return 0;
}

