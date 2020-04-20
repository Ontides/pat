/**
 1025 反转链表 (25分)
 给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

 输入格式：
 每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10^5)、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。
 接下来有 N 行，每行格式为：
 Address Data Next
 其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

 输出格式：
 对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

 输入样例：
 00100 6 4
 00000 4 99999
 00100 1 12309
 68237 6 -1
 33218 3 00000
 99999 5 68237
 12309 2 33218

 输出样例：
 00000 4 33218
 33218 3 12309
 12309 2 00100
 00100 1 99999
 99999 5 68237
 68237 6 -1
 */
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct node {
    int id;
    int data;
    int address;
    int nextAddress;
};
//根据id从大到小排
bool cmp(node* a, node* b) {
    return a->id > b->id;
}
int main() {
    int n, k, len = 0, addr;//len为链表长度
    scanf("%d %d %d", &addr, &n, &k);
    //读取节点，放到索引mp里
    map<int, node*> mp;
    for (int i = 0; i < n; i++) {
        node *p = new node;
        scanf("%d %d %d", &p->address, &p->data, &p->nextAddress);
        mp[p->address] = p;
    }
    
    //建立初始链表
    node *L[n];
    for (; mp.count(addr); addr = mp[addr]->nextAddress) {
        L[len] = mp[addr];
        L[len]->id = len;
        len++;
    }
    //反转链表
    int m = len / k;//m为反转的次数
    for (int i = 0; i < m; i++) {
        sort(L+i*k, L+(i+1)*k, cmp);
    }
    //按照新的顺序设置地址
    for (int i = 0; i < len-1; i++) {
        L[i]->nextAddress = L[i+1]->address;
    }
    L[len-1]->nextAddress = -1;
    //打印结果
    for (int i = 0; i < len; i++) {
        if (L[i]->nextAddress == -1) {
            printf("%05d %d %d\n", L[i]->address, L[i]->data, L[i]->nextAddress);
        } else {
            printf("%05d %d %05d\n", L[i]->address, L[i]->data, L[i]->nextAddress);
        }
    }
    return 0;
}

