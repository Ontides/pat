/**
 1075 链表元素分类 (25分)
 给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素的前面，而 [0, K] 区间内的元素都排在大于 K 的元素前面。但每一类内部元素的顺序是不能改变的。例如：给定链表为 18→7→-4→0→5→-6→10→11→-2，K 为 10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。

 输入格式：
 每个输入包含一个测试用例。每个测试用例第 1 行给出：第 1 个结点的地址；结点总个数，即正整数N (≤10^5 )；以及正整数K (≤10^3)。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。
 接下来有 N 行，每行格式为：
 Address Data Next
 其中 Address 是结点地址；Data 是该结点保存的数据，为 [−10^​5,10^5] 区间内的整数；Next 是下一结点的地址。题目保证给出的链表不为空。

 输出格式：
 对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

 输入样例：
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
 
 输出样例：
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

