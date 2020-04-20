/**
 1074 Reversing Linked List (25分)
 Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

 Input Specification:
 Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10^5) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
 Then N lines follow, each describes a node in the format:
 Address Data Next
 where Address is the position of the node, Data is an integer, and Next is the position of the next node.

 Output Specification:
 For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

 Sample Input:
 00100 6 4
 00000 4 99999
 00100 1 12309
 68237 6 -1
 33218 3 00000
 99999 5 68237
 12309 2 33218
     
 Sample Output:
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

