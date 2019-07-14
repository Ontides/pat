#include <cstdio>
#include <cmath>

struct factor {
    int x, count;
} fac[20];
const int maxn = 999;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
//求素数表
void findPrime() {
    for (int i = 2; i < maxn; i++) {
        if (!p[i]) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}
int main() {
    int n, num = 0, originalN;
    findPrime();
    scanf("%d", &n);
    //对1特殊处理
    if (n == 1) {
        printf("1=1");
        return 0;
    }
    //记录初始N值
    originalN = n;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 0; i < pNum && prime[i] <= sqr && n != 1; i++) {
        if (n % prime[i] == 0) {
            fac[num].x = prime[i];
            fac[num].count = 0;
            while (n % prime[i] == 0) {
                fac[num].count++;
                n /= prime[i];
            }
            num++;
        }
    }
    if (n != 1) {
        fac[num].x = n;
        fac[num++].count = 1;
    }
    printf("%d=", originalN);
    for (int i = 0; i < num; i++) {
        if (i) {
            printf("*");
        }
        printf("%d", fac[i].x);
        if (fac[i].count > 1) {
            printf("^%d", fac[i].count);
        }
    }
    return 0;
}

