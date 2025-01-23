#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, number, remains;//n - разряд, m-число
    long long int m;
    int i=0;
    scanf("%lld", &m);
    scanf("%d", &n);
    for (int i=0; m>=0; i++) {//Перевод в двоичную
        remains = m % 2;//remains - остаток от деления
        m = m / 2;
        if (i==n){
            printf("%d", remains);
            break;
        }
    }
    return 0;
}