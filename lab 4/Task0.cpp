#include <iostream>
#include <cmath>
#include <cstring>

int main() {
    unsigned long long int num, n;
    std::cin >> num >> n;

    if (num < 0) {
        printf("error ");
        return 0;
    }

    if (num >= pow(2, n)) { // Проверяем, помещается ли число в заданную разрядность
        printf("error");
        return 0;
    }

    char binary_s[64] = {0}; // Достаточно для 64-разрядных чисел
    int i = 0;

    while (num > 0) { // Преобразование в двоичную систему
        binary_s[i] = (num % 2) + '0';
        num /= 2;
        i++;
    }

    for (int j = i; j < n; j++) { // Дополнение нулями до нужной разрядности
        binary_s[j] = '0';
    }

    int len = n;
    for (int j = 0; j < len / 2; j++) { // Переворачиваем строку
        char temp = binary_s[j];
        binary_s[j] = binary_s[len - j - 1];
        binary_s[len - j - 1] = temp;
    }

    // Вывод результата
    printf("%s", binary_s);

    return 0;
}