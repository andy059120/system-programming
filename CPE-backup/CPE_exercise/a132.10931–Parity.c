#include <stdio.h>
/*
1.大致看懂題目
2.確認輸入
3.開始算
*/
void main()
{
    while(1){
        int num;
        scanf("%d", &num);
        if(num==0) break;
        int count = 1;
        int arr[100] = {0};
        int i = 0;
        while(num!=1){
            if(num%2 == 1){
                count++;
            }
            arr[i] = num%2;
            num = num/2;
            i++;
        }
        i--;
        printf("The parity of 1");
        for(; i >= 0; i--) printf("%d",arr[i]);
        printf(" is %d (mod 2).\n", count);
    }
}
