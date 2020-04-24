/**
 1001 A+B Format (20分)
 Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

 Input Specification:
 Each input file contains one test case. Each case contains a pair of integers a and b where −10^6≤a,b≤10^6. The numbers are separated by a space.

 Output Specification:
 For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

 Sample Input:
 -1000000 9

 Sample Output:
 -999,991
 */
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = a+b;
    if (!sum) {
        printf("0");
    } else {
        vector<int> segment;
        while (sum) {
            segment.push_back(sum % 1000);
            sum /= 1000;
        }
        printf("%d", segment[segment.size()-1]);
        for (int i = (int)(segment.size()-2); i >= 0; i--) {
            printf(",%03d", (int)fabs(segment[i]));
        }
    }
    return 0;
}

