/*
1120 Friend Numbers (20分)
Two integers are called "friend numbers" if they share the same sum of their digits, and the sum is their "friend ID". For example, 123 and 51 are friend numbers since 1+2+3 = 5+1 = 6, and 6 is their friend ID. Given some numbers, you are supposed to count the number of different friend ID's among them.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N. Then N positive integers are given in the next line, separated by spaces. All the numbers are less than 10^4.

Output Specification:
For each case, print in the first line the number of different frind ID's among the given integers. Then in the second line, output the friend ID's in increasing order. The numbers must be separated by exactly one space and there must be no extra space at the end of the line.

Sample Input:
8
123 899 51 998 27 33 36 12

Sample Output:
4
3 6 9 26
*/
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


