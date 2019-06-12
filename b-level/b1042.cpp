#include <cstdio>
#include <cstring>

int main() {
    char str[1010], resultIndex = 0;
    int count[26] = {};
    fgets(str, 1010, stdin);
    int len = strlen(str);
    for (int i = 0; i < len-1; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            count[str[i] - 'A']++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            count[str[i] - 'a']++;
        }
    }
    for (int i = 1; i < 26; i++) {
        if (count[i] > count[resultIndex]) {
            resultIndex = i;
        }
    }
    printf("%c %d", resultIndex + 'a', count[resultIndex]);
    return 0;
}

