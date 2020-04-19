/**
 */
#include <cstdio>
#include <map>
using namespace std;
struct node {
    int data;
    int address;
    int nextAddress;
    node* next = NULL;
};
using namespace std;
int main() {
    node *head = new node;//链表头结点
    int n, k;
    scanf("%d %d %d", &head->nextAddress, &n, &k);
    //读取节点，放到索引mp里
    map<int, node*> mp;
    for (int i = 0; i < n; i++) {
        node *p = new node;
        scanf("%d %d %d", &p->address, &p->data, &p->nextAddress);
        mp[p->address] = p;
    }
    
    node *pre = head;//前一个节点
    //建立链表
    for (int i = 0; i < n; i++) {
        pre->next = mp[pre->nextAddress];
        //这里必须判断一下pre->next是否存在，要不然会有段错误，题目实际输入不一定是长度为n的链表
        if (pre->next) {
            pre = pre->next;
        } else {
            break;
        }
    }
    
    pre = head;
    node *ltkList = new node;//大于等于0小于等于k的链表
    node *curLtkNode = ltkList;
    node *gtkList = new node;//大于k的链表
    node *curGtkNode = gtkList;
    while (pre != NULL && pre->next != NULL) {
        //如果下一个节点为非负数，当前节点的下一节点改为下下结点
        if (pre->next->data > k) {
            curGtkNode->next = pre->next;
            curGtkNode = curGtkNode->next;
            pre->next = pre->next->next;
            
            curGtkNode->next = NULL;
        } else if (pre->next->data >= 0) {
            curLtkNode->next = pre->next;
            curLtkNode = curLtkNode->next;
            pre->next = pre->next->next;
            
            curLtkNode->next = NULL;
        } else {
            pre = pre->next;
        }
    }
    if (gtkList->next != NULL) {
        curLtkNode->next = gtkList->next;
    }
    pre->next = ltkList->next;
    
    node *L = head->next;
    while (L != NULL) {
        if (L->next != NULL) {
            L->nextAddress = L->next->address;
            printf("%05d %d %05d\n", L->address ,L->data, L->nextAddress);
        } else {
            L->nextAddress = -1;
            printf("%05d %d %d\n", L->address ,L->data, L->nextAddress);
        }
        L = L->next;
    }
    return 0;
}

