/**
 1045 快速排序 (25分)
 著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的 N 个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？
 例如给定 $N = 5$, 排列是1、3、2、4、5。则：
 1 的左边没有元素，右边的元素都比它大，所以它可能是主元；
 尽管 3 的左边元素都比它小，但其右边的 2 比它小，所以它不能是主元；
 尽管 2 的右边元素都比它大，但其左边的 3 比它大，所以它不能是主元；
 类似原因，4 和 5 都可能是主元。
 因此，有 3 个元素可能是主元。

 输入格式：
 输入在第 1 行中给出一个正整数 N（≤10^5）； 第 2 行是空格分隔的 N 个不同的正整数，每个数不超过 10^9。

 输出格式：
 在第 1 行中输出有可能是主元的元素个数；在第 2 行中按递增顺序输出这些元素，其间以 1 个空格分隔，行首尾不得有多余空格。

 输入样例：
 5
 1 3 2 4 5

 输出样例：
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

