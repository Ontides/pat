#include <cstdio>

int main() {
    int n, aDrink, bDrink, record[4], correctAns;
    aDrink = bDrink = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &record[0], &record[1], &record[2], &record[3]);
        correctAns = record[0] + record[2];
        if (record[1] != record[3]) {
            if (record[1] == correctAns) {
                bDrink++;
            } else if (record[3] == correctAns) {
                aDrink++;
            }
        }
    }
    printf("%d %d", aDrink, bDrink);
    return 0;
}

