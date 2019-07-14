#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp (int a, int b) {
    return a > b;
}

// 将一个数字转化为升序或降序的数字
int numSort(int t, bool dec) {
    int temp = t, arr[4] = {}, result = 0;
    for (int i = 3; i >= 0; i--) {
        arr[i] = temp % 10;
        temp /= 10;
    }
    if (dec) {
        sort(arr, arr+4);
    } else {
        sort(arr, arr+4, cmp);
    }
    for (int i = 3; i >= 0; i--) {
        result = result * 10 + arr[i];
    }
    return result;
}

// 判断是否为2222这种类型的数字
bool congruent(int t) {
    bool flag = true;
    int num = t % 10;
    for (int i = 0; i < 4; i++) {
        if (t % 10 != num) {
            flag = false;
            break;
        }
        t /= 10;
    }
    return flag;
}

int main() {
    int n, minuend, subtrahend;
    scanf("%d", &n);
    // 首先判断6174和四位相同的数字这两种情况
    if (n == 6174) {
        printf("7641 - 1467 = 6174\n");
    } else if (congruent(n)) {
        printf("%04d - %04d = 0000\n", n, n);
    } else {
        while (n != 6174) {
            minuend = numSort(n, true);
            subtrahend = numSort(n, false);
            n = minuend - subtrahend;
            printf("%04d - %04d = %04d\n", minuend, subtrahend, n);
        }
    }
    return 0;
}
// 题同B1019
