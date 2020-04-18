/**
 1015 德才论 (25分)
 宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
 现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

 输入格式：
 输入第一行给出 3 个正整数，分别为：N（≤10^5），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。
 随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

 输出格式：
 输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

 输入样例：
 14 60 80
 10000001 64 90
 10000002 90 60
 10000011 85 80
 10000003 85 80
 10000004 80 85
 10000005 82 77
 10000006 83 76
 10000007 90 78
 10000008 75 79
 10000009 59 90
 10000010 88 45
 10000012 80 100
 10000013 90 99
 10000014 66 60

 输出样例：
 12
 10000013 90 99
 10000012 80 100
 10000003 85 80
 10000011 85 80
 10000004 80 85
 10000007 90 78
 10000006 83 76
 10000005 82 77
 10000002 90 60
 10000014 66 60
 10000008 75 79
 10000001 64 90
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define classA 0
#define classB 1
#define classC 2
#define classD 3

struct person {
    int id, moralScore, talentScore;
};

bool cmp(person a, person b) {
    if (a.moralScore + a.talentScore == b.moralScore + b.talentScore) {
        if (a.moralScore == b.moralScore) {
            return a.id < b.id;
        } else {
            return a.moralScore > b.moralScore;
        }
    } else {
        return (a.moralScore + a.talentScore) > (b.moralScore + b.talentScore);
    }
}

person classes[4][100000];
int main() {
    int n, l, h, m = 0;
    scanf("%d %d %d", &n, &l, &h);
    int tempId, tempMoralScore, tempTalentScore;//编号，德分，才分
    int classCount[4] = {0};
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tempId, &tempMoralScore, &tempTalentScore);
        if (tempMoralScore < l || tempTalentScore < l) {
            continue;
        }
        int curClass = -1;
        if (tempMoralScore >= h && tempTalentScore >= h) {
            curClass = classA;//当前考生为第一类，德才全尽
        } else if (tempMoralScore >= h) {
            curClass = classB;//当前考生为第二类，德胜才
        } else if (tempMoralScore < h && tempTalentScore < h && tempMoralScore >= tempTalentScore) {
            curClass = classC;//当前考生为第三类，才德兼亡，但尚有德胜才
        } else {
            curClass = classD;//当前考生为第四类
        }
        classes[curClass][classCount[curClass]].id = tempId;
        classes[curClass][classCount[curClass]].moralScore = tempMoralScore;
        classes[curClass][classCount[curClass]].talentScore = tempTalentScore;
        classCount[curClass]++;
    }
    for (int i = 0; i < 4; i++) {
        m += classCount[i];
        sort(classes[i], classes[i] + classCount[i], cmp);
    }
    printf("%d\n", m);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < classCount[i]; j++) {
            printf("%08d %d %d\n", classes[i][j].id, classes[i][j].moralScore, classes[i][j].talentScore);
        }
    }
    return 0;
}
