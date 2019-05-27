#include <cstdio>
#include <cstring>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        bool flag = true;
        char temp[110];
        int numOfA[3] = {}, numOfT = 0, count = 0;// numOfA为A的数量的数组，0,1,2分别为P的左侧、P和T中间，T的右侧的A的数量，numOfT为T的数量
        scanf("%s", temp);
        int len = strlen(temp);
        for (int j = 0; j < len; j++) {
            if (temp[j] == 'A') {
                numOfA[count]++;//若输入为A则对应地方的A数量自增1
            } else if (temp[j] == 'P' && count == 0 || temp[j] == 'T' && count == 1) {//若为P或T则切换当前A的计数位置，其中为了限制P、T的数量和位置，增加了对当前计数器位置的限制
                count++;
                if (temp[j] == 'T') {// 为排除T不存在的情况，对T进行计数
                    numOfT++;
                }
            } else {//其他情况均为非法
                flag = false;
                break;
            }
        }
        if (flag && numOfA[0] * numOfA[1] == numOfA[2] && numOfA[1] > 0 && numOfT == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
// PAT APATA AAPATAA ...
// PAAT APATA AAPAATAAAA...
// PAAAT APAATAA...
// PAAAAT...
