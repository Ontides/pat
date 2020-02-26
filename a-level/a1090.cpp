/*
 1090
 */
#include <cstdio>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int n, s[100010];
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    bool flag = false;
    int curIndexs[100010] = {0}, depth = 0, count = 1;
    bool availIndex[100010] = {false};
    curIndexs[0] = -1;
    do {
        flag = false;
        set<int> tempIndexs;
        for (int i = 0; i < n; i++) {
            if (availIndex[i]) continue;
            for (int j = 0; j < count; j++) {
                if (s[i] == curIndexs[j]) {
                    tempIndexs.insert(i);
                    availIndex[i] = true;
                    flag = true;
                }
            }
        }
        if (flag) {
            count = 0;
            for (set<int>::iterator it = tempIndexs.begin(); it != tempIndexs.end(); it++) {
                curIndexs[count++] = *it;
            }
            depth++;
        }
    } while (flag);
    double price = p * pow(1 + r/100, depth - 1.0);
    printf("%.2f %d", price, count);
    return 0;
}

