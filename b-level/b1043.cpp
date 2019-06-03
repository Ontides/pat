#include <cstdio>
#include <cstring>

int main() {
    char str[10010];
    int count[6] = {}, totalCount;
    char map[6] = {'P', 'A', 'T', 'e', 's', 't'};
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case 'P':
                count[0]++;
                break;
            case 'A':
                count[1]++;
                break;
            case 'T':
                count[2]++;
                break;
            case 'e':
                count[3]++;
                break;
            case 's':
                count[4]++;
                break;
            case 't':
                count[5]++;
                break;
            default:
                break;
        }
    }
    totalCount = count[0] + count[1] + count[2] + count[3] + count[4] + count[5];
    int cur = 0;
    for (int i = 0; i < totalCount; i++) {
        while (!count[cur]) {
            if (cur == 5) {
                cur = 0;
            } else {
                cur++;
            }
        }
        printf("%c", map[cur]);
        count[cur]--;
        if (cur == 5) {
            cur = 0;
        } else {
            cur++;
        }
    }
    return 0;
}

