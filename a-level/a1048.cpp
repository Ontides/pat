/**
1048 Find Coins (25分)
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^​5 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10^​5, the total number of coins) and M (≤10​^3, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the two face values V1 and V​2 (separated by a space) such that V​1+V2=M and V1≤V2. If such a solution is not unique, output the one with the smallest V1. If there is no solution, output No Solution instead.

Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11

Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution
 */
#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];
int flag[1010] = {0};//标记i面额的硬币存在个数
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        flag[a[i]]++;
    }
    sort(a, a+n);
    bool exist = false;
    for (int i = 0; i <= 500; i++) {
        if (flag[i]) {
            flag[i]--;
            if (flag[m-a[i]]) {
                exist = true;
                cout << a[i] << ' ' << m-a[i] << endl;
                break;
            }
        }
    }
    if (!exist) cout << "No Solution" << endl;
    return 0;
}

