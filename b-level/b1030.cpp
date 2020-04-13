/**
 1030 完美数列 (25分)
 给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。
 现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

 输入格式：
 输入第一行给出两个正整数 N 和 p，其中 N（≤10^5）是输入的正整数的个数，p（≤10^9）是给定的参数。第二行给出 N 个正整数，每个数不超过 10^9。
 
 输出格式：
 在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

 输入样例：
 10 8
 2 3 20 4 5 1 6 7 8 9
     
 输出样例：
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

