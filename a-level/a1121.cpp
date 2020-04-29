/*
1121 Damn Single (25分)
"Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (≤ 10,000) followed by M ID's of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.

Output Specification:
First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.

Sample Input:
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

Sample Output:
5
10000 23333 44444 55555 88888
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int partners[100000] = {-1};
int main(){
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        partners[a] = b;
        partners[b] = a;
    }
    scanf("%d", &m);
    int curID;
    vector<int> alonePerson;
    for (int i = 0; i < m; i++) {
        scanf("%d", &curID);
        if (partners[curID] == -1) {
            alonePerson.push_back(curID);
        } else {
            bool flag = false;//是否已经存在记录当前人员的伴侣
            for (int j = 0; j < alonePerson.size(); j++) {
                if (partners[curID] == alonePerson[j]) {
                    alonePerson.erase(alonePerson.begin()+j);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                alonePerson.push_back(curID);
            }
        }
    }
    sort(alonePerson.begin(), alonePerson.end());
    printf("%d\n", (int)alonePerson.size());
    for (int i = 0; i < alonePerson.size(); i++) {
        if (i) {
            printf(" ");
        }
        printf("%05d", alonePerson[i]);
    }
    return 0;
}


