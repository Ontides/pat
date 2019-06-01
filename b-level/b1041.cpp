#include <cstdio>

int main() {
    int n, m, query;
    long long a[1010][3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &query);
        for (int j = 0; j < n; j++) {
            if (a[j][1] == query) {
                printf("%lld %lld\n", a[j][0], a[j][2]);
                break;
            }
        }
    }
    return 0;
}

