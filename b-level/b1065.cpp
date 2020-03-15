/**
 1065 单身狗 (25分)
 “单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

 输入格式：
 输入第一行给出一个正整数 N（≤ 50 000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。

 输出格式：
 首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。

 输入样例：
 3
 11111 22222
 33333 44444
 55555 66666
 7
 55555 44444 10000 88888 22222 11111 23333

 输出样例：
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

