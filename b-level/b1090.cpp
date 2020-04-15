/**
 1090 危险品装箱 (25分)
 集装箱运输货物时，我们必须特别小心，不能把不相容的货物装在一只箱子里。比如氧化剂绝对不能跟易燃液体同箱，否则很容易造成爆炸。
 本题给定一张不相容物品的清单，需要你检查每一张集装箱货品清单，判断它们是否能装在同一只箱子里。

 输入格式：
 输入第一行给出两个正整数：N (≤10^4) 是成对的不相容物品的对数；M (≤100) 是集装箱货品清单的单数。
 随后数据分两大块给出。第一块有 N 行，每行给出一对不相容的物品。第二块有 M 行，每行给出一箱货物的清单，格式如下：
 K G[1] G[2] ... G[K]
 其中 K (≤1000) 是物品件数，G[i] 是物品的编号。简单起见，每件物品用一个 5 位数的编号代表。两个数字之间用空格分隔。

 输出格式：
 对每箱货物清单，判断是否可以安全运输。如果没有不相容物品，则在一行中输出 Yes，否则输出 No。

 输入样例：
 6 3
 20001 20002
 20003 20004
 20005 20006
 20003 20001
 20005 20004
 20004 20006
 4 00001 20004 00002 20003
 5 98823 20002 20003 20006 10010
 3 12345 67890 23333

 输出样例：
 No
 Yes
 Yes
 */
#include <cstdio>
#include <iostream>
using namespace std;
struct cargo {
    //每个货物对应危险货物清单
    int dangerousCouple[1000] = {0};
    int count = 0;
};
cargo cargos[100000];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        cargos[id1].dangerousCouple[cargos[id1].count++] = id2;
        cargos[id2].dangerousCouple[cargos[id2].count++] = id1;
    }
    for (int i = 0; i < m; i++) {
        int k, id;
        scanf("%d", &k);
        bool flag[100000] = {false};
        bool dangerous = false;//当前清单是否危险
        for (int j = 0; j < k; j++) {
            scanf("%d", &id);
            flag[id] = true;//标记当前物品
            for (int k = 0; k < cargos[id].count; k++) {
                //遍历当前物品的不相容物品，如果之前出现过，则标记为危险
                if (flag[cargos[id].dangerousCouple[k]]) {
                    dangerous = true;
                    break;
                }
            }
            if (dangerous && j != k-1) {
                char useless[9999];
                cin.getline(useless, 9999);//如果已经存在不相容物品，则后面的输入直接省略以减少计算
                break;
            }
        }
        if (dangerous) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}

