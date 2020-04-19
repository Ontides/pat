/**
 1133 Splitting A Linked List (25分)
 Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18→7→-4→0→5→-6→10→11→-2 and K being 10, you must output -4→-6→-2→7→0→5→10→18→11.

 Input Specification:
 Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10^​​ ) which is the total number of nodes, and a positive K(≤10^3). The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.
 Then N lines follow, each describes a node in the format:
 Address Data Next
 where Address is the position of the node, Data is an integer in [−10^5,10^5], and Next is the position of the next node. It is guaranteed that the list is not empty.

 Output Specification:
 For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.

 Sample Input:
 00100 9 10
 23333 10 27777
 00000 0 99999
 00100 18 12309
 68237 -6 23333
 33218 -4 00000
 48652 -2 -1
 99999 5 68237
 27777 11 48652
 12309 7 33218

 Sample Output:
 33218 -4 68237
 68237 -6 48652
 48652 -2 12309
 12309 7 00000
 00000 0 99999
 99999 5 23333
 23333 10 00100
 00100 18 27777
 27777 11 -1
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

