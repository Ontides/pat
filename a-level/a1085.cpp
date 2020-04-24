/**
 1085 Perfect Sequence (25分)
 Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.
 Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

 Input Specification:
 Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (≤10^5) is the number of integers in the sequence, and p (≤10^9) is the parameter. In the second line there are N positive integers, each is no greater than 10^9.
 
 Output Specification:
 For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

 Sample Input:
 10 8
 2 3 20 4 5 1 6 7 8 9

 Sample Output:
 8
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long sequence[100000];
//查找M的位置
int searchMPos(int l, int r, int p, long long m) {
    int mid = (r + l) / 2;
    if (sequence[mid] > m * p) {
        if (l == r) {
            return l-1;//如果l == r的话，说明当前分区不存在满足要求的M位置，返回前一个满足要求的M位置
        } else {
            return searchMPos(l, mid, p, m);
        }
    } else if (sequence[mid] < sequence[l] * p) {
        return searchMPos(mid + 1, r, p, m);
    } else {
        return mid;
    }
}
int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &sequence[i]);
    }
    //从小到大排序
    sort(sequence, sequence+n);
    int result = 1;
    //这里只需遍历到n-result+1即可，后面的情况数列个数肯定小于result
    for (int i = 0; i < n - result + 1; i++) {
        int temp = searchMPos(i, n-1, p, sequence[i]) - i + 1;
        if (temp > result) {
            result = temp;
        }
    }
    printf("%d", result);
    return 0;
}

