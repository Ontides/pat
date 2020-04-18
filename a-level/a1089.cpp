/**
 1089 Insert or Merge (25分)
 According to Wikipedia:
 Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
 Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.
 Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

 Input Specification:
 Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

 Output Specification:
 For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

 Sample Input 1:
 10
 3 1 2 8 7 5 9 4 6 0
 1 2 3 7 8 5 9 4 6 0
 Sample Output 1:
 Insertion Sort
 1 2 3 5 7 8 9 4 6 0

 Sample Input 2:
 10
 3 1 2 8 7 5 9 4 0 6
 1 3 2 8 5 7 4 9 0 6
 Sample Output 2:
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

