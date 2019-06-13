#include <cstdio>
#include <cstring>

int main() {
    char input[100010];
    int TNum = 0, ATNum = 0;
    long long count = 0;
    scanf("%s", input);
    int len = strlen(input);
    for (int i = len-1; i >= 0; i--) {
        switch (input[i]) {
            case 'P':
                count += ATNum;
                break;
            case 'A':
                ATNum += TNum;
                break;
            case 'T':
                TNum++;
                break;
            default:
                break;
        }
    }
    printf("%lld", count % 1000000007);
    return 0;
}

