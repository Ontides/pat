#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    long long A[100010];
    long long S1 = 0, S2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    sort(A, A + n);
    for (int i = 0; i < n / 2; i++) {
        S1 += A[i];
    }
    for (int i = n / 2; i < n; i++) {
        S2 += A[i];
    }
    printf("%d %lld", n % 2, S2 - S1);
    return 0;
}

