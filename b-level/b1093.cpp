#include <cstdio>
#include <cstring>

int main() {
    int lenA, lenB;
    bool map[127] = {};
    char a[1000010], b[1000010];
    fgets(a, 1000010, stdin);
    fgets(b, 1000010, stdin);
    lenA = strlen(a) - 1;
    lenB = strlen(b) - 1;
    for (int i = 0; i < lenA; i++) {
        if (!map[(int)a[i]]) {
            map[(int)a[i]] = true;
            printf("%c", a[i]);
        }
    }
    for (int i = 0; i < lenB; i++) {
        if (!map[(int)b[i]]) {
            map[(int)b[i]] = true;
            printf("%c", b[i]);
        }
    }
    return 0;
}

