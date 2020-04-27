/**
 1117 Eddington Number (25分)
 British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", E -- that is, the maximum integer E such that it is for E days that one rides more than E miles. Eddington's own E was 87.
 Now given everyday's distances that one rides for N days, you are supposed to find the corresponding E (≤N).

 Input Specification:
 Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5), the days of continuous riding. Then N non-negative integers are given in the next line, being the riding distances of everyday.

 Output Specification:
 For each case, print in a line the Eddington number for these N days.

 Sample Input:
 10
 6 7 6 9 3 10 8 2 7 8
 
 Sample Output:
 6
 */
#include <cstdio>
#define MAX 100001
int a[MAX], b[MAX];
int main(){
    int n, max = 0, min = MAX, e = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    //b[i]为超过i英里的天数
    for (int i = 1; i <= n; i++) {
        for (int j = min; j < a[i] && j < MAX; j++) {
            b[j]++;
        }
    }
    for (int i = min; i <= max; i++) {
        if (b[i] < i) {
            e = i-1;
            break;
        }
    }
    printf("%d", e);
    return 0;
}

