/**
 1035 插入与归并 (25分)
 根据维基百科的定义：
 插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
 归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。
 现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

 输入格式：
 输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

 输出格式：
 首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。

 输入样例 1：
 10
 3 1 2 8 7 5 9 4 6 0
 1 2 3 7 8 5 9 4 6 0
 输出样例 1：
 Insertion Sort
 1 2 3 5 7 8 9 4 6 0

 输入样例 2：
 10
 3 1 2 8 7 5 9 4 0 6
 1 3 2 8 5 7 4 9 0 6
 输出样例 2：
 Merge Sort
 1 2 3 8 4 5 7 9 0 6
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
//判断两个数组是否相等
bool arrayEqual(int a[], int b[], int len) {
    bool result = true;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            result = false;
            break;
        }
    }
    return result;
}
//打印数组
void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int record[n], intermediate[n], recordBackup[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &record[i]);
        recordBackup[i] = record[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &intermediate[i]);
    }
    //判断是否为插入排序
    bool isInsertionSort = false;
    for (int i = 1; i < n; i++) {
        int t = record[i];
        int j = i-1;
        for (; j >= 0 && record[j] > t; j--) {
            record[j+1] = record[j];
        }
        record[j+1] = t;
        if (isInsertionSort) {
            printf("Insertion Sort\n");
            printArray(record, n);
            break;
        }
        if (arrayEqual(record, intermediate, n)) {
            isInsertionSort = true;
        }
    }
    if (!isInsertionSort) {
        //如果是归并排序
        bool isEqual = false;
        for (int step = 1; !isEqual; step *= 2) {
            //先判断是否相等再计算下一次迭代的结果，如果相等则退出循环，打印结果
            isEqual = arrayEqual(recordBackup, intermediate, n);
            for (int left = 0; left < n; left += step) {
                int right = (int)fmin(left + step, n);
                sort(recordBackup + left, recordBackup + right);
            }
        }
        printf("Merge Sort\n");
        printArray(recordBackup, n);
    }
    return 0;
}

