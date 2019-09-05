/*
 1092
 */
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    char beadsShop[1010], beadsEva[1010];
    scanf("%s%s", beadsShop, beadsEva);
    int beadsShopLen = (int)strlen(beadsShop), beadsEvaLen = (int)strlen(beadsEva);
    map<char, int> evaWant, shopOwn;
    for (int i = 0; i < beadsEvaLen; i++) {
        evaWant[beadsEva[i]]++;
    }
    int lackCount = (int)strlen(beadsEva), wastedCount = 0;
    for (int i = 0; i < beadsShopLen; i++) {
        if (evaWant[beadsShop[i]] > 0) {
            lackCount--;
            evaWant[beadsShop[i]]--;
        } else {
            wastedCount++;
        }
    }
    if (!lackCount) {
        printf("Yes %d", wastedCount);
    } else {
        printf("No %d", lackCount);
    }
    return 0;
}

