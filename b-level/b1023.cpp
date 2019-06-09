#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int numCount[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numCount[i]);
    }
    // 如果含有0，则先找到一个大于0的最小数字输出
    if (numCount[0] > 0) {
        for (int i = 1; i < 10; i++) {
            if (numCount[i] > 0) {
                printf("%d", i);
                numCount[i]--;
                break;
            }
        }
    }
    // 然后再按照从小到大输出所有数字
    for (int i = 0; i < 10; i++) {
        while (numCount[i] > 0) {
            printf("%d", i);
            numCount[i]--;
        }
    }
    return 0;
}

