#include <cstdio>
#include <cmath>

struct player {
    int id;
    double distance;
};
double getDistance(int x, int y) {
    return pow(x*x + y*y, 0.5);
}
int main() {
    int n, x, y;
    player winer, loser, temp;
    scanf("%d", &n);
    scanf("%d%d%d", &winer.id, &x, &y);
    loser.id = winer.id;
    winer.distance = getDistance(x, y);
    loser.distance = winer.distance;
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &temp.id, &x, &y);
        temp.distance = getDistance(x, y);
        if (temp.distance > loser.distance) {
            loser.distance = temp.distance;
            loser.id = temp.id;
        } else if (temp.distance < winer.distance) {
            winer.distance = temp.distance;
            winer.id = temp.id;
        }
    }
    printf("%04d %04d", winer.id, loser.id);
    return 0;
}

