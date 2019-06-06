#include <cstdio>
#include <cstring>

int main() {
    char input[100010];
    int sum = 0, len, zeroCount = 0, oneCount = 0;
    fgets(input, 100010, stdin);
    len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            sum += input[i] - 'a' + 1;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            sum += input[i] - 'A' + 1;
        }
    }
    while (sum) {
        int temp = sum & 1;
        if (temp) {
            oneCount++;
        } else {
            zeroCount++;
        }
        sum = sum >> 1;
    }
    printf("%d %d", zeroCount, oneCount);
    return 0;
}

