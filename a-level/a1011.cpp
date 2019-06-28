#include <cstdio>

int main() {
    int index = -1;
    double temp, max = -1, ans = 1;
    char choose[3], map[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++) {
        max = -1;
        index = -1;
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &temp);
            if (temp > max) {
                max = temp;
                index = j;
            }
        }
        choose[i] = index;
        ans *= max;
    }
    ans = (ans * 0.65 - 1) * 2;
    printf("%c %c %c %.2f", map[choose[0]], map[choose[1]], map[choose[2]], ans);
    return 0;
}

