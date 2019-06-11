#include <cstdio>

int getFriendNum(int num) {
    int friendNum = 0;
    while (num) {
        friendNum += num % 10;
        num /= 10;
    }
    return friendNum;
}

int main() {
    // 题目中所有数字小于10000，因此最大的朋友数是9+9+9+9=36
    int n, temp, friendNumCount = 0, friendNums[37] = {}, resultNum[37] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        friendNums[getFriendNum(temp)]++;
    }
    for (int i = 1; i <= 36; i++) {
        if (friendNums[i] > 0) {
            resultNum[friendNumCount++] = i;
        }
    }
    printf("%d\n", friendNumCount);
    for (int i = 0; i < friendNumCount - 1; i++) {
        printf("%d ", resultNum[i]);
    }
    printf("%d", resultNum[friendNumCount-1]);
    return 0;
}

