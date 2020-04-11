/**
 1080 MOOC期终成绩 (25分)
 对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G=(Gmid−term ×40%+G ​final ×60%)，如果 Gmid−term >Gfinal；否则总评 G 就是 Gfinal 。这里 Gmid−term 和 Gfinal分别为学生的期中和期末成绩。
 现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

 输入格式：
 输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。
 接下来有三块输入。第一块包含 P 个在线编程成绩 Gp；第二块包含 M 个期中考试成绩 Gmid−term；第三块包含 N 个期末考试成绩 Gfinal 。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

 输出格式：
 打印出获得合格证书的学生名单。每个学生占一行，格式为：
 学生学号 Gp Gmid−term Gfinal G
 如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

 输入样例：
 6 6 7
 01234 880
 a1903 199
 ydjh2 200
 wehu8 300
 dx86w 220
 missing 400
 ydhfu77 99
 wehu8 55
 ydjh2 98
 dx86w 88
 a1903 86
 01234 39
 ydhfu77 88
 a1903 66
 01234 58
 wehu8 84
 ydjh2 82
 missing 99
 dx86w 81
     
 输出样例：
 missing 400 -1 99 99
 ydjh2 200 98 82 88
 dx86w 220 88 81 84
 wehu8 300 55 84 84
 */
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct student {
    string id;
    int gp = -1;
    int gm = -1;
    int gf = -1;
    int g = -1;
};
int searchStudentById(student stu[], int len, string id) {
    int index = -1;
    for (int i = 0; i < len; i++) {
        if (stu[i].id == id) {
            index = i;
            break;
        }
    }
    return index;
}
bool cmp (student a, student b) {
    if (a.g == b.g) {
        return a.id <= b.id;
    } else {
        return a.g > b.g;
    }
}
int main() {
    int p, m, n;
    scanf("%d%d%d", &p, &m, &n);
    student stu[p];
    int count = 0, tempGrade;
    string tempId;
    map<string, int> idToIndex;//通过id查询学生在数组里的index
    
    for (int i = 1; i <= p; i++) {
        cin >> tempId >> tempGrade;
        //只录入编程作业分不少于200的
        if (tempGrade >= 200) {
            stu[count].id = tempId;
            stu[count].gp = tempGrade;
            count++;
            idToIndex[tempId] = count;//这里的index比实际index多了1
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> tempId >> tempGrade;
        //仅当在编程分合格的名单，才录入期中成绩
        int index = idToIndex[tempId] - 1;
        if (index >= 0) {
            stu[index].gm = tempGrade;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> tempId >> tempGrade;
        int index = idToIndex[tempId] - 1;//获取实际index，如果查找不到，则index为-1
        //仅当在编程分合格的名单，才录入期末成绩
        if (index >= 0) {
            stu[index].gf = tempGrade;
            //计算总评成绩
            stu[index].g = stu[index].gm > stu[index].gf ?
                (int)round(stu[index].gm * .4 + stu[index].gf * .6)
                : stu[index].gf;
        }
    }
    //按题目要求排序
    sort(stu, stu + count, cmp);
    for (int i = 0; i < count; i++) {
        if (stu[i].g < 60) {
            break;
        }
        cout << stu[i].id << " " << stu[i].gp << " " << stu[i].gm << " " << stu[i].gf << " " << stu[i].g << endl;
    }
    return 0;
}

