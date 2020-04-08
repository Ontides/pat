/**
 1068 万绿丛中一点红 (20分)
 对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

 输入格式：
 输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的颜色值，范围在 [0,2^​24​​ ) 内。所有同行数字间用空格或 TAB 分开。

 输出格式：
 在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Unique；如果这样的点不存在，则输出 Not Exist。

 输入样例 1：
 8 6 200
 0      0       0        0        0          0           0        0
 65280      65280    65280    16711479 65280    65280    65280    65280
 16711479 65280    65280    65280    16711680 65280    65280    65280
 65280      65280    65280    65280    65280    65280    165280   165280
 65280      65280       16777015 65280    65280    165280   65480    165280
 16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215

 输出样例 1：
 (5, 3): 16711680

 输入样例 2：
 4 5 2
 0 0 0 0
 0 0 3 0
 0 0 0 0
 0 5 0 0
 0 0 0 0

 输出样例 2：
 Not Unique
     
 输入样例 3：
 3 3 5
 1 2 3
 3 4 5
 5 6 7

 输出样例 3：
 Not Exist
 */
#include <cstdio>
#include <cmath>

int main(){
    int m, n, tol, resultCount = 0, resultX = -1, resultY = -1;
    scanf("%d%d%d", &m, &n, &tol);
    int screen[n][m];
    bool flag[n][m];//标记是否是周围一圈颜色最突出的那个
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &screen[i][j]);
            flag[i][j] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //判断是颜色突出的那个
            if (flag[i][j]) {
                for (int k = fmax(i-1, 0); k <= i+1 && k < n; k++) {
                    for (int l = fmax(j-1, 0); l <= j+1 && l < m; l++) {
                        if (i == k && j == l) {
                            continue;
                        }
                        if (fabs(screen[k][l] - screen[i][j]) <= tol) {
                            flag[i][j] = false;
                            flag[k][l] = false;//减枝
                        }
                    }
                }
            }
            if (flag[i][j]) {
                bool unique = true;
                //查看是否唯一
                for (int k = 0; k < n && unique; k++) {
                    for (int l = 0; l < m; l++) {
                        if (screen[i][j] == screen[k][l] && !(k == i && l == j)) {
                            unique = false;
                            break;
                        }
                    }
                }
                if (unique) {
                    resultX = j;
                    resultY = i;
                    resultCount++;
                }
            }
        }
    }
    if (resultCount == 0) {
        printf("Not Exist\n");
    } else if (resultCount > 1) {
        printf("Not Unique\n");
    } else {
        printf("(%d, %d): %d\n", resultX+1, resultY+1, screen[resultY][resultX]);
    }
    return 0;
}

