#include <cstdio>
int count(long long m, int dm) {
    int temp, num = 0, pm = 0;
    while (m > 0) {
        temp = m % 10;
        if (temp == dm) {
            num++;
        }
        m /= 10;
    }
    while (num > 0) {
        pm = pm * 10 + dm;
        num--;
    }
    return pm;
}

int main() {
    long long a, b;
    int da, db, pa, pb;
    scanf("%lld %d %lld %d", &a, &da, &b, &db);
    pa = count(a, da);
    pb = count(b, db);
    printf("%d", pa + pb);
    return 0;
}

