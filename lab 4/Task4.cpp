#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool checkOverflow(long long int num, int n) { //Проверка на переполнение
    if (abs(num) > (1LL << (n - 1))) { //переполнение 1LL - 1 Long long, << - сдвигаем в лево по биту, перевод в n битную систему
        return true; // Переполнение
    }
    return false; // Переполнения нет
}

string conversionToBinary(long long int num, int n) { //Преобразование числа в двоичный код
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? '0' : '1') + binary;
        num /= 2;
    }
    while (binary.length() < n) {
        binary = "0" + binary;
    }
    return binary;
}

string conversionToAdditionalCode(long long int num, int n, string binary) { //Перевод числа в Дополнительный код
    for (int i = 0; i < n; i++) { //Обратный код
        if (binary[i] == '0') {
            binary[i] = '1';
        }
        else {
            binary[i] = '0';
        }
    }

    int carry = 1; //несёт значение
    for (int i = n - 1; i >= 0; i--) { //Дополнительный код
        if (binary[i] == '1' && carry == 1) {
            binary[i] = '0';
        }
        else if (binary[i] == '0' && carry == 1) {
            binary[i] = '1';
            carry = 0;
        }
    }
    return binary;
}

int main() {
    int n, k = 0;
    long long int num1, num2;//num1 - Первое число: ; num2 - Второе число;n - разрядная сетка;k - счетчик длины по Хеммингу;  
    cin >> num1 >> num2 >> n;

    if (checkOverflow(num1, n)) { //переполнение 1LL - 1 Long long, << - сдвижение влево по биту (по сути умножение на 2)
        cout << "error\n";
        return 0;
    }
    if (checkOverflow(num2, n)) { //переполнение 1LL - 1 Long long, << - сдвижение влево по биту
        cout << "error\n";
        return 0;
    }

    string binary1 = "";
    string binary2 = "";

    // Преобразуем num1 в двоичный код
    long long int num3 = abs(num1);
    binary1 = (conversionToBinary(num3, n));

    // Преобразуем num2 в двоичный код
    long long int num4 = abs(num2);
    binary2 = (conversionToBinary(num4, n));

    // Находим дополнительный код для num1
    if (num1 < 0) {
        binary1 = conversionToAdditionalCode(num1, n, binary1);
    }

    // Находим дополнительный код для num2
    if (num2 < 0) {
        binary2 = conversionToAdditionalCode(num2, n, binary2);
    }

    for (int i = 0; i < n; i++) {
        if (binary1[i] != binary2[i]) {
            k += 1;
        }
    }
    printf("Additional Code 1 number ");
    cout << binary1 << endl;

    printf("Additional Code 2 number ");
    cout << binary2 << endl;

    cout << "Hemming distance " << endl;
    cout << k << endl;

    return 0;
}

//Я молодец я сделал лабу ฅ^•⩊•^ฅ
// 
// 
//     ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄
//     ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀▄
//    ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
//    ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄
//   █▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
//   ▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐   ▄▄
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀