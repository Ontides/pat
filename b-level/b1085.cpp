/**
 1085 PAT单位排行 (25分)
 每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

 输入格式：
 输入第一行给出一个正整数 N（≤10^​5），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：
 准考证号 得分 学校
 其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是 [0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

 输出格式：
 首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：
 排名 学校 加权总分 考生人数
 其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的整数部分；考生人数是该属于单位的考生的总人数。
 学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

 输入样例：
 10
 A57908 85 Au
 B57908 54 LanX
 A37487 60 au
 T28374 67 CMU
 T32486 24 hypu
 A66734 92 cmu
 B76378 71 AU
 A47780 45 lanx
 A72809 100 pku
 A03274 45 hypu

 输出样例：
 5
 1 cmu 192 2
 1 au 192 3
 3 pku 100 1
 4 hypu 81 2
 4 lanx 81 2
 */
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct school {
    string name;
    int score = 0,
        aScore = 0,
        bScore = 0,
        tScore = 0,
        examineeCount = 0,
        rank = -1;
};
void setScore(char type, int score, school &s) {
    switch (type) {
        case 'B':
            s.bScore += score;
            break;
        case 'A':
            s.aScore += score;
            break;
        case 'T':
            s.tScore += score;
            break;
        default:
            break;
    }
}
bool cmp(school a, school b) {
    if (a.score == b.score) {
        if (a.examineeCount == b.examineeCount) {
            return a.name < b.name;
        } else {
            return a.examineeCount < b.examineeCount;
        }
    } else {
        return a.score > b.score;
    }
}
int main() {
    int n, schoolCount = 0;
    cin >> n;
    getchar();//吸收换行符
    school s[n+1];
    map<string, int> schoolNameMap;//从学校名字到学校在数组s里的index的散列
    for (int i = 0; i < n; i++) {
        char type = getchar();
        int curScore;
        string curId, schoolName;
        cin >> curId >> curScore >> schoolName;
        //把学校名转化为小写
        transform(schoolName.begin(), schoolName.end(), schoolName.begin(), ::tolower);
        if (schoolNameMap[schoolName]) {
            s[schoolNameMap[schoolName]].examineeCount++;
            setScore(type, curScore, s[schoolNameMap[schoolName]]);
        } else {
            schoolCount++;
            s[schoolCount].examineeCount++;
            s[schoolCount].name = schoolName;
            setScore(type, curScore, s[schoolCount]);
            schoolNameMap[schoolName] = schoolCount;
        }
        getchar();
    }
    //计算总分
    for (int i = 1; i <= schoolCount; i++) {
        s[i].score = (int)floor(s[i].aScore + s[i].bScore / 1.5 + s[i].tScore * 1.5);
    }
    //按题目要求排序
    sort(s+1, s+schoolCount+1, cmp);
    cout << schoolCount << endl;
    //计算排名并输出相关信息
    for (int i = 1; i <= schoolCount; i++) {
        if (s[i].score == s[i-1].score && i != 1) {
            s[i].rank = s[i-1].rank;
        } else {
            s[i].rank = i;
        }
        cout << s[i].rank << " " << s[i].name << " " << s[i].score << " " << s[i].examineeCount << endl;
    }
    return 0;
}

