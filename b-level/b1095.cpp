/**
 1095 解码PAT准考证 (25分)
 PAT 准考证号由 4 部分组成：
 第 1 位是级别，即 T 代表顶级；A 代表甲级；B 代表乙级；
 第 2~4 位是考场编号，范围从 101 到 999；
 第 5~10 位是考试日期，格式为年、月、日顺次各占 2 位；
 最后 11~13 位是考生编号，范围从 000 到 999。
 现给定一系列考生的准考证号和他们的成绩，请你按照要求输出各种统计信息。

 输入格式：
 输入首先在一行中给出两个正整数 N（≤10*4）和 M（≤100），分别为考生人数和统计要求的个数。
 接下来 N 行，每行给出一个考生的准考证号和其分数（在区间 [0,100] 内的整数），其间以空格分隔。
 考生信息之后，再给出 M 行，每行给出一个统计要求，格式为：类型 指令，其中
 类型 为 1 表示要求按分数非升序输出某个指定级别的考生的成绩，对应的 指令 则给出代表指定级别的字母；
 类型 为 2 表示要求将某指定考场的考生人数和总分统计输出，对应的 指令 则给出指定考场的编号；
 类型 为 3 表示要求将某指定日期的考生人数分考场统计输出，对应的 指令 则给出指定日期，格式与准考证上日期相同。
 
 输出格式：
 对每项统计要求，首先在一行中输出 Case #: 要求，其中 # 是该项要求的编号，从 1 开始；要求 即复制输入给出的要求。随后输出相应的统计结果：
 类型 为 1 的指令，输出格式与输入的考生信息格式相同，即 准考证号 成绩。对于分数并列的考生，按其准考证号的字典序递增输出（题目保证无重复准考证号）；
 类型 为 2 的指令，按 人数 总分 的格式输出；
 类型 为 3 的指令，输出按人数非递增顺序，格式为 考场编号 总人数。若人数并列则按考场编号递增顺序输出。
 如果查询结果为空，则输出 NA。

 输入样例：
 8 4
 B123180908127 99
 B102180908003 86
 A112180318002 98
 T107150310127 62
 A107180908108 100
 T123180908010 78
 B112160918035 88
 A107180908021 98
 1 A
 2 107
 3 180908
 2 999

 输出样例：
 Case 1: 1 A
 A107180908108 100
 A107180908021 98
 A112180318002 98
 Case 2: 2 107
 3 260
 Case 3: 3 180908
 107 2
 123 2
 102 1
 Case 4: 2 999
 NA
 */
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//考生
struct Examinee {
    string id;
    int score, roomNo, examDate, examineeNo;
    char level;
};
//等级信息
struct Level {
    vector<Examinee> examinee;
};
//考场信息
struct Room {
    int roomNo = -1;
    int examineeCount = 0;
    int totalScore = 0;
};
//考试日期信息
struct ExamDate {
    vector<Room> room;
    int date;
};

//同考试等级里信息排序
bool levelCmp(Examinee a, Examinee b) {
    if (a.score == b.score) {
        return a.id < b.id;
    } else {
        return a.score > b.score;
    }
}
//同日期里信息排序
bool dateCmp(Room a, Room b) {
    if (a.examineeCount == b.examineeCount) {
        return a.roomNo < b.roomNo;
    } else {
        return a.examineeCount > b.examineeCount;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Examinee e[n];//考生信息
    Room r[1000];//各考场信息
    
    vector<ExamDate> examDate;//日期信息
    map <int, ExamDate> dateMap;//日期从数字到上面日期信息的映射
    
    Level level[3];//等级信息
    map <char, Level> levelMap;//等级映射
    levelMap['T'] = level[0];
    levelMap['A'] = level[1];
    levelMap['B'] = level[2];
    
    char temp[14];
    for (int i = 0; i < n; i++) {
        scanf("%s%d", temp, &e[i].score);
        e[i].id = string(temp);
        sscanf(temp, "%c%3d%6d%3d", &e[i].level, &e[i].roomNo, &e[i].examDate, &e[i].examineeNo);
        //添加该等级信息
        levelMap[e[i].level].examinee.push_back(e[i]);
        //添加该房间信息
        r[e[i].roomNo].examineeCount++;
        r[e[i].roomNo].totalScore += e[i].score;
        //添加该日期信息
        if (dateMap.count(e[i].examDate) == 0) {
            //如果该日期第一次出现，则创建日期并push到examDate中
            ExamDate date;
            date.date = e[i].examDate;

            Room room;
            room.roomNo = e[i].roomNo;
            room.examineeCount = 1;
            date.room.push_back(room);

            examDate.push_back(date);
            dateMap[e[i].examDate] = examDate[examDate.size()-1];
        } else {
            int index = -1;
            //查找当前考场在当前日期里的位置
            for (int j = 0; j < dateMap[e[i].examDate].room.size(); j++) {
                if (dateMap[e[i].examDate].room[j].roomNo == e[i].roomNo) {
                    index = j;
                    break;
                }
            }
            if (index == -1) {
                //考场不存在，则在当前日期里添加该考场信息
                Room room;
                room.roomNo = e[i].roomNo;
                room.examineeCount = 1;
                dateMap[e[i].examDate].room.push_back(room);
            } else {
                //考场存在，则直接增加该考场考生数量
                dateMap[e[i].examDate].room[index].examineeCount++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int type;
        char instruction[10];
        scanf("%d%s", &type, instruction);
        printf("Case %d: %d %s\n", i+1, type, instruction);
        if (type == 1) {
            //判断当前级别是否有数据
            int size = (int)levelMap[instruction[0]].examinee.size();
            if (size) {
                //按题目要求排序
                sort(levelMap[instruction[0]].examinee.begin(), levelMap[instruction[0]].examinee.end(), levelCmp);
                //按题目要求输出
                for (int j = 0; j < size; j++) {
                    printf("%s %d\n", levelMap[instruction[0]].examinee[j].id.c_str(), levelMap[instruction[0]].examinee[j].score);
                }
            } else {
                printf("NA\n");
            }
        } else if (type == 2) {
            int query;
            sscanf(instruction, "%d", &query);
            //判断该考场是否有考生
            if (r[query].examineeCount) {
                printf("%d %d\n", r[query].examineeCount, r[query].totalScore);
            } else {
                printf("NA\n");
            }
        } else if (type == 3) {
            int query;
            sscanf(instruction, "%d", &query);
            //按题目要求排序
            sort(dateMap[query].room.begin(), dateMap[query].room.end(), dateCmp);
            //按题目要求输出
            if (dateMap[query].room.size()) {
                for (int j = 0; j < dateMap[query].room.size(); j++) {
                    printf("%d %d\n", dateMap[query].room[j].roomNo, dateMap[query].room[j].examineeCount);
                }
            } else {
                printf("NA\n");
            }
        }
    }
    return 0;
}

