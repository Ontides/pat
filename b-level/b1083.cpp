#include <cstdio>
#include <cmath>
#include <cstdlib>

int card[10010];
int flag[10010] = {0};

int main() {
    int n, temp, max = -1, min = 9999, dif;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        dif = (int)(abs((double)i - (double)temp));
        flag[dif]++;
        if (flag[dif] > 1) {
            if (dif > max) {
                max = dif;
            }
            if (dif < min) {
                min = dif;
            }
        }
    }
    for (int i = max; i >= min; i--) {
        if (flag[i] > 1) {
            printf("%d %d\n", i, flag[i]);
        }
    }
    
    return 0;
}

