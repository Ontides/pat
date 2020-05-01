/*
1109 Group Photo (25分)
Formation is very important when taking a group photo. Given the rules of forming K rows with N people as the following:
* The number of people in each row must be N/K (round down to the nearest integer), with all the extra people (if any) standing in the last row;
* All the people in the rear row must be no shorter than anyone standing in the front rows;
* In each row, the tallest one stands at the central position (which is defined to be the position (m/2+1), where m is the total number of people in that row, and the division result must be rounded down to the nearest integer);
* In each row, other people must enter the row in non-increasing order of their heights, alternately taking their positions first to the right and then to the left of the tallest one (For example, given five people with their heights 190, 188, 186, 175, and 170, the final formation would be 175, 188, 190, 186, and 170. Here we assume that you are facing the group so your left-hand side is the right-hand side of the one at the central position.);
* When there are many people having the same height, they must be ordered in alphabetical (increasing) order of their names, and it is guaranteed that there is no duplication of names.
Now given the information of a group of people, you are supposed to write a program to output their formation.

Input Specification:
Each input file contains one test case. For each test case, the first line contains two positive integers N (≤10^4), the total number of people, and K (≤10), the total number of rows. Then N lines follow, each gives the name of a person (no more than 8 English letters without space) and his/her height (an integer in [30, 300]).

Output Specification:
For each case, print the formation -- that is, print the names of people in K lines. The names must be separated by exactly one space, but there must be no extra space at the end of each line. Note: since you are facing the group, people in the rear rows must be printed above the people in the front rows.

Sample Input:
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

Sample Output:
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct person {
    string name;
    int height;
};
//比较函数，先按身高升序，再按名字字母序降序
bool cmp(person a, person b) {
    if (a.height != b.height) {
        return a.height < b.height;
    } else {
        return a.name > b.name;
    }
}
//处理相对于每排middle下标移动步数
int moveStep(int n) {
    return ceil(n / 2.0) * (int)pow(-1, n);
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int personsPerRow = (int)floor((double)n/(double)k);
    person p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].height;
    }
    //对输入数据排序
    sort(p, p+n, cmp);
    for (int i = k-1; i >= 0; i--) {
        int curRowPersonCount = personsPerRow;
        if (i == k-1) {
            curRowPersonCount += n % k;
        }
        string row[curRowPersonCount+1];
        int middle = (int)floor(curRowPersonCount / 2.0) + 1;
        //从最后一排开始安排排列顺序
        for (int j = 0; j < curRowPersonCount; j++) {
            int rowIndex = middle + moveStep(j);
            int pIndex = i * personsPerRow + curRowPersonCount - 1 - j;
            row[rowIndex] = p[pIndex].name;
        }
        //按排好的顺序打印
        for (int j = 1; j <= curRowPersonCount; j++) {
            cout << row[j];
            if (j != curRowPersonCount) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
    return 0;
}