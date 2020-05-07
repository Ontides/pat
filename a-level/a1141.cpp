/*
1141 PAT Ranking of Institutions (25分)
After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5), which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:
ID Score School
where ID is a string of 6 characters with the first one representing the test level: B stands for the basic level, A the advanced level and T the top level; Score is an integer in [0, 100]; and School is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that ID is unique for each testee.

Output Specification:
For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:
Rank School TWS Ns
where Rank is the rank (start from 1) of the institution; School is the institution code (all in lower case); ; TWS is the total weighted score which is defined to be the integer part of ScoreB/1.5 + ScoreA + ScoreT*1.5, where ScoreX is the total score of the testees belong to this institution on level X; and Ns is the total number of testees who belong to this institution.
The institutions are ranked according to their TWS. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of Ns. If there is still a tie, they shall be printed in alphabetical order of their codes.

Sample Input:
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

Sample Output:
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

