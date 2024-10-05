#include <stdio.h>
#include <assert.h>

#define ARRAYSIZE 100

//bubble sort in C
//測資10
//13 65 7 91 20 4 79 8 16 45

main()
{
    int totalNumber;
    int n[ARRAYSIZE];
    int s[ARRAYSIZE];
    int t[ARRAYSIZE];
    int u[ARRAYSIZE];

    printf("enter the total number");
    scanf("%d", &totalNumber);
    assert(totalNumber >= 1 && totalNumber < ARRAYSIZE);

    for (int i = 0; i < totalNumber; i++) {
        scanf("%d", &(n[i]));
    }
    for (int i = 0; i < totalNumber; i++) {
        s[i] = n[i];
        t[i] = n[i];
        u[i] = n[i];
    }

    //大排到小，由後往前排
    for (int i = totalNumber - 2; i >= 0; i--) {//從array的倒數第二個值往前
        for (int j = 0; j <= i; j++) {//從array的第0個值開始
            if (n[j] > n[j + 1]) {//若前值比後值大則交換(把大的往後丟)
                int temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }
    //小排到大，由後往前排
    for (int i = totalNumber - 2; i >= 0; i--) {//從array的倒數第二個值往前
        for (int j = 0; j <= i; j++) {//從array的第0個值開始
            if (s[j] < s[j + 1]) {//若前值比後值小則交換(把小的往後丟)
                int temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    //大排到小，由前往後排
    for (int i = 1; i <= totalNumber - 1; i++) {//從array的第二個值往後
        for (int j = totalNumber - 1; j >= i; j--) {//從array的最後一個值開始
            if (t[j] > t[j - 1]) {//若後值比前值大則交換(把大的往前丟)
                int temp = t[j];
                t[j] = t[j - 1];
                t[j - 1] = temp;
            }
        }
    }
    //小排到大，由前往後排
    for (int i = 1; i <= totalNumber - 1; i++) {//從array的第二個值往後
        for (int j = totalNumber - 1; j >= i; j--) {//從array的最後一個值開始
            if (u[j] < u[j - 1]) {//若後值比前值小則交換(把小的往前丟)
                int temp = u[j];
                u[j] = u[j - 1];
                u[j - 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < totalNumber; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
    for (int i = 0; i < totalNumber; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    for (int i = 0; i < totalNumber; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
    for (int i = 0; i < totalNumber; i++) {
        printf("%d ", u[i]);
    }
}
