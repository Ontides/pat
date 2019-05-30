#include <cstdio>
#include <cmath>

int main() {
    int n, input1, input2;
    double temp, result = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &input1, &input2);
        temp = pow(pow(input1, 2.0) + pow(input2, 2.0), 0.5);
        if (temp > result) {
            result = temp;
        }
    }
    printf("%.2f", result);
    return 0;
}

