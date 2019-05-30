#include <cstdio>

int main() {
    int n;
    char input[101][20];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(input[i], 20, stdin);
        for (int j = 0; j < 4; j++) {
            if (input[i][j*4+2] == 'T') {
                switch (input[i][j*4]) {
                    case 'A':
                        printf("1");
                        break;
                    case 'B':
                        printf("2");
                        break;
                    case 'C':
                        printf("3");
                        break;
                    case 'D':
                        printf("4");
                        break;
                    default:
                        break;
                }
            }
        }
    }
    printf("\n");
    return 0;
}

