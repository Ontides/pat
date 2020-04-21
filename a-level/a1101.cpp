/**
 1101 Quick Sort (25分)
 There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?
 For example, given N=5 and the numbers 1, 3, 2, 4, and 5. We have:
 1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
 3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
 2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
 and for the similar reason, 4 and 5 could also be the pivot.
 Hence in total there are 3 pivot candidates.

 Input Specification:
 Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5). Then the next line contains N distinct positive integers no larger than 10^9. The numbers in a line are separated by spaces.

 Output Specification:
 For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

 Sample Input:
 5
 1 3 2 4 5
     
 Sample Output:
 3
 1 4 5
 */
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int arr[n], min[n], max[n];
    for (int i = 0; i < n; i++) {
        //读取元素
        scanf("%d", &arr[i]);
        //设置max数组，里面每项为从第一个元素到当前元素的最大值
        if (!i) {
            max[i] = arr[i];
        } else {
            max[i] = arr[i] > max[i-1] ? arr[i] : max[i-1];
        }
    }
    //设置min数组，里面每项为从最后一个元素到当前元素的最小值
    min[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        min[i] = arr[i] < min[i+1] ? arr[i] : min[i+1];
    }
    
    int count = 0;//可能的主元数量
    vector<int> pivot;//主元元素
    for (int i = 0; i < n; i++) {
        if (arr[i] >= max[i] && arr[i] <= min[i]) {
            count++;
            pivot.push_back(arr[i]);
        }
    }
    //按题目要求打印
    printf("%d\n", count);
    for (int i = 0; i < pivot.size(); i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", pivot[i]);
    }
    //如果不存在主元，需要打印一个空行
    if (!count) {
        printf("\n");
    }
    return 0;
}

