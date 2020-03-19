/**
 1060 爱丁顿数 (25分)
 英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。
 现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 E（≤N）。

 输入格式：
 输入第一行给出一个正整数 N (≤10^ ​5​​ )，即连续骑车的天数；第二行给出 N 个非负整数，代表每天的骑车距离。

 输出格式：
 在一行中给出 N 天的爱丁顿数。

 输入样例：
 10
 6 7 6 9 3 10 8 2 7 8

 输出样例：
 6
 */
#include <cstdio>
#define MAX 100000
int a[MAX], b[MAX+1];
int main(){
    int n, max = 0, min = MAX, e = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = min - 1; j < a[i] && j <= MAX; j++) {
            b[j]++;
        }
    }
    
    for (int i = min - 1; i <= max; i++) {
        if (b[i] < i) {
            e = i-1;
            break;
        }
    }
    printf("%d", e);
    return 0;
}


