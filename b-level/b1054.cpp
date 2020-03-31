/**
 1054 求平均值 (20分)
 本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

 输入格式：
 输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

 输出格式：
 对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。如果平均值无法计算，则用 Undefined 替换 Y。如果 K 为 1，则输出 The average of 1 number is Y。

 输入样例 1：
 7
 5 -3.2 aaa 9999 2.3.4 7.123 2.35

 输出样例 1：
 ERROR: aaa is not a legal number
 ERROR: 9999 is not a legal number
 ERROR: 2.3.4 is not a legal number
 ERROR: 7.123 is not a legal number
 The average of 3 numbers is 1.38
     
 输入样例 2：
 2
 aaa -9999

 输出样例 2：
 ERROR: aaa is not a legal number
 ERROR: -9999 is not a legal number
 The average of 0 numbers is Undefined
 */
#include <cstdio>
#include <cstring>

//判断数字合法性
bool judgment(char input[], double &output) {
    bool result = true;
    int len = (int)strlen(input);
    //排除只有一个负号的情况
    if (len == 1 && input[0] == '-') {
        result = false;
    }
    //排除含有除了.和数字以及非第一位有负号的情况
    for (int i = 0, dotIndex = -1; i < len; i++) {
        if (!(input[i] =='.' || (input[i] >= '0' && input[i] <= '9') || (input[i] == '-' && i == 0))) {
            result = false;
            break;
        }
        //判断是否出现两次小数点
        if (input[i] == '.') {
            if (dotIndex > -1) {
                result = false;
                break;
            } else {
                dotIndex = i;
            }
        } else if (dotIndex > -1 && i > dotIndex+2) {
            //判断是否小数位数是否大于两位
            result = false;
            break;
        }
    }
    if (result) {
        sscanf(input, "%lf", &output);
        if (output < -1000.0 || output > 1000.0) {
            result = false;
        }
    }
    return result;
}
int main(){
    int n, k = 0;
    double sum = 0.0, temp;
    char input[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        if (!judgment(input, temp)) {
            printf("ERROR: %s is not a legal number\n", input);
        } else {
            sum += temp;
            k++;
        }
    }
    if (k > 1) {
        printf("The average of %d numbers is %.2f\n", k, sum / k);
    } else if (k == 1) {
        printf("The average of 1 number is %.2f\n", sum / k);
    } else {
        printf("The average of 0 numbers is Undefined\n");
    }
    return 0;
}


