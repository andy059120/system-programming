#include <stdio.h>

int main() {
    int p = 123;
    int* q = &p;

    printf("%d\n", *(q++));
    printf("%x", q--);
}