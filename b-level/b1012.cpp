#include <cstdio>

int main() {
    int n,
        a1 = 0,
        a2 = 0,
        a2Count = 0,// 特别对a2进行计数，可能存在计算结果为0，但是其存在的情况
        a3 = 0,
        a4Sum = 0,
        a4Count = 0,
        a5 = 0,
        temp,
        sign = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        switch (temp % 5) {
            case 0:
                (temp % 2) || (a1 += temp);
                break;
            case 1:
                a2 += (sign * temp);
                sign *= -1;
                a2Count++;
                break;
            case 2:
                a3++;
                break;
            case 3:
                a4Sum += temp;
                a4Count++;
                break;
            case 4:
                if (temp > a5) a5 = temp;
                break;
            default:
                break;
        }
    }
    a1 ? printf("%d", a1) : printf("N");
    a2Count ? printf(" %d", a2) : printf(" N");
    a3 ? printf(" %d", a3) : printf(" N");
    a4Count ? printf(" %.1f", (double)a4Sum/(double)a4Count) : printf(" N");
    a5 ? printf(" %d", a5) : printf(" N");
    return 0;
}

