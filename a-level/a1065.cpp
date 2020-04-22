/**
 1065 A+B and C (64bit) (20分)
 Given three integers A, B and C in [−2^63, 2^63], you are supposed to tell whether A+B>C.
 
 Input Specification:
 The first line of the input gives the positive number of test cases, T (≤10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

 Output Specification:
 For each test case, output in one line Case #X: true if A+B>C, or Case #X: false otherwise, where X is the case number (starting from 1).

 Sample Input:
 3
 1 2 3
 2 3 4
 9223372036854775807 -9223372036854775808 0

 Sample Output:
 Case #1: false
 Case #2: true
 Case #3: false
 */
#include <cstdio>
int main() {
    int t;
    long long a, b, c;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        bool result = false;
        if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0)) {
            //如果a,b异号，直接相加比较
            result = a + b > c;
        } else if ((a > 0 && c > 0) || (a < 0 && c < 0)) {
            //如果a,b,c同号,a与c-b比较
            result = a > c - b;
        } else {
            //如果a,b同号，c异号(或0)，则直接比较a和c大小即可
            result = a > c;
        }
        printf("Case #%d: %s\n", i+1, result ? "true" : "false");
    }
    return 0;
}

