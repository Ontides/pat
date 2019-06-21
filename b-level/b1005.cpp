#include <cstdio>

int main() {
    int n, input[101];
    bool record[101] = {false};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        record[input[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!record[input[i]]) continue;
        while (input[i] != 1) {
            if (input[i] % 2) {
                input[i] = (input[i] * 3 + 1) / 2;
            } else {
                input[i] = input[i] / 2;
            }
            if (input[i] <= 100 && record[input[i]]) {
                record[input[i]] = false;
            }
        }
    }
    int printBuffer = 0;
    for (int i = 100; i > 0; i--) {
        if (record[i]) {
            if (printBuffer) {
                printf("%d ", printBuffer);
            }
            printBuffer = i;
        }
    }
    printf("%d\n", printBuffer);
    return 0;
}

