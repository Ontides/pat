#include <cstdio>
#include <cstring>

struct record {
    char id[20];
    char signInTime[10];
    char signOutTime[10];
};
void recordCopy(record a, record b) {
    strcpy(a.id, b.id);
    strcpy(a.signInTime, b.signInTime);
    strcpy(a.signOutTime, b.signOutTime);
}
bool earlierCompare(char time1[], char time2[]) {
    int time1H, time1M, time1S, time2H, time2M, time2S;
    sscanf(time1, "%d:%d:%d", &time1H, &time1M, &time1S);
    sscanf(time2, "%d:%d:%d", &time2H, &time2M, &time2S);
    if (time1H == time2H) {
        if (time1M == time2M) {
            return time1S < time2S;
        } else {
            return time1M < time2M;
        }
    } else {
        return time1H < time2H;
    }
}
int main() {
    record studentUnlock, studentLock, tempStudnet;
    int m;
    scanf("%d", &m);
    scanf("%s %s %s", studentUnlock.id, studentUnlock.signInTime, studentUnlock.signOutTime);
    strcpy(studentLock.id, studentUnlock.id);
    strcpy(studentLock.signInTime, studentUnlock.signInTime);
    strcpy(studentLock.signOutTime, studentUnlock.signOutTime);
    for (int i = 1; i < m; i++) {
        scanf("%s %s %s", tempStudnet.id, tempStudnet.signInTime, tempStudnet.signOutTime);
        if (earlierCompare(tempStudnet.signInTime, studentUnlock.signInTime)) {
            strcpy(studentUnlock.id, tempStudnet.id);
            strcpy(studentUnlock.signInTime, tempStudnet.signInTime);
            strcpy(studentUnlock.signOutTime, tempStudnet.signOutTime);
        }
        if (earlierCompare(studentLock.signOutTime, tempStudnet.signOutTime)) {
            recordCopy(studentLock, tempStudnet);
            strcpy(studentLock.id, tempStudnet.id);
            strcpy(studentLock.signInTime, tempStudnet.signInTime);
            strcpy(studentLock.signOutTime, tempStudnet.signOutTime);
        }
    }
    printf("%s %s", studentUnlock.id, studentLock.id);
    return 0;
}

