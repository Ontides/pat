#include <cstdio>
#include <algorithm>
using namespace std;

struct MoonCake {
    double inventory, totalPrice, averPrice;
} moonCake[1010];

bool cmp(MoonCake a, MoonCake b) {
    return a.averPrice > b.averPrice;
}

int main() {
    int N, D;
    double income = 0.0;
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &moonCake[i].inventory);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lf", &moonCake[i].totalPrice);
        moonCake[i].averPrice = moonCake[i].totalPrice / moonCake[i].inventory;
    }
    sort(moonCake, moonCake + N, cmp);
    for (int i = 0; i < N; i++) {
        if (moonCake[i].inventory < D) {
            D -= moonCake[i].inventory;
            income += moonCake[i].totalPrice;
        } else {
            income += moonCake[i].averPrice * D;
            break;
        }
    }
    printf("%.2f\n", income);
    return 0;
}

