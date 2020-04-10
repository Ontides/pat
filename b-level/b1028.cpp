/**
 1028 人口普查 (20分)
 某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
 这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

 输入格式：
 输入在第一行给出正整数 N，取值在(0,10^ ​5]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

 输出格式：
 在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

 输入样例：
 5
 John 2001/05/12
 Tom 1814/09/06
 Ann 2121/01/30
 James 1814/09/05
 Steve 1967/11/20

 输出样例：
 3 Tom John
 */
#include <cstdio>
#include <algorithm>
using namespace std;
struct person {
    char name[6];
    int year, month, day;
};
bool cmp(person a, person b) {
    if (a.year == b.year) {
        if (a.month == b.month) {
            return a.day < b.day;
        } else {
            return a.month < b.month;
        }
    } else {
        return a.year < b.year;
    }
}
bool birthValidation(person p) {
    if (p.year > 2014 || p.year < 1814) {
        return false;
    } else if (p.year == 2014) {
        return p.month < 9 || (p.month == 9 && p.day <= 6);
    } else if (p.year == 1814) {
        return p.month > 9 || (p.month == 9 && p.day >= 6);
    } else {
        return true;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    person p[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", p[i].name, &p[i].year, &p[i].month, &p[i].day);
    }
    //按生日小到大（年长到年轻）排序
    sort(p, p+n, cmp);
    //统计有效生日个数，打印
    int validBirtCount = 0;
    for (int i = 0; i < n; i++) {
        if (birthValidation(p[i])) {
            validBirtCount++;
        }
    }
    printf("%d", validBirtCount);
    //找到最年长的，打印
    for (int i = 0; i < n; i++) {
        if (birthValidation(p[i])) {
            printf(" %s", p[i].name);
            break;
        }
    }
    //找到最年轻的，打印
    for (int i = n-1; i >= 0; i--) {
        if (birthValidation(p[i])) {
            printf(" %s", p[i].name);
            break;
        }
    }
    return 0;
}

