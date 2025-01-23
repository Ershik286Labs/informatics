#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, k = 0, remains; // n - вводимое число, k - кол-во нулей, s = n в двоичной, remains - остаток от деления n на 2
    scanf("%d", &n);
    for (int i=0; n>=0; i++){
        remains = n % 2;
        n = n / 2;
        if (remains==0){
            k+=1;
        }
        if (n==0) {
            break;
        }
    }
    printf("%d\n", k);
    return 0;
}