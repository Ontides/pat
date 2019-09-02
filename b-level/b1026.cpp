#include <cstdio>
#include <cmath>

int main() {
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int time = (int)round((c2 - c1) / 100.0);
    int h = floor(time / 3600.0);
    time %= 3600;
    int m = floor(time / 60.0);
    int s = time % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}

