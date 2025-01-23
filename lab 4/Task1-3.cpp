#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    long long int num, n;
    cin >> num >> n;
    string one = "1";
    string binary1 = "";

    if (abs(num) > (pow(2, n - 1))) { //переполнение
        cout << "error\n";
        return 0;
    }

    string binary = "";
    string binary3 = "";

    long long int num1 = abs(num); // Используем модуль для получения абсолютной величины

    while (num1 > 0) {
        binary = (num1 % 2 == 0 ? '0' : '1') + binary;
        num1 /= 2;
    }

    // Дополнение нулями до нужной разрядности
    while (binary.length() < n) {
        binary = "0" + binary;
    }

    if (num < 0) {
        binary1 = binary;
        while (binary1.length() < n - 1) {
            binary1 = "0" + binary1;
        }
        binary1 = one + binary1;
        printf("task 1 forward code ");
        std::cout << binary1 << endl;

        binary3 = binary;
        for (int i = 0; i < n; i++) {
            if (binary3[i] == '0') {
                binary3[i] = '1';
            }
            else {
                binary3[i] = '0';
            }
        }

        string binary2 = binary3;
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (binary2[i] == '1' && carry == 1) {
                binary2[i] = '0';
            }
            else if (binary2[i] == '0' && carry == 1) {
                binary2[i] = '1';
                carry = 0;
            }
        }
        printf("task 2 Additional code ");
        cout << binary2 << endl;

        printf("task 3 reverce code ");
        cout << binary3 << endl;
        return 0;
    }

    printf("task 1 forward code ");
    cout << binary << endl;

    printf("task 2 Additional code ");
    cout << binary << endl;

    printf("task 3 reverce code ");
    cout << binary << endl;

    return 0;
}