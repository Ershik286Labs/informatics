#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;

string convertingAnIntegerPartToBinary(int n1, string binary) {
    if (n1 == 0) {
        binary = "0";
    }
    int i = 0;
    while (n1 > 0) { //перевод в двоичную СС целой части
        i++;
        int number = n1 % 2;
        n1 = n1 / 2;
        string numbers = to_string(number);
        binary = numbers + binary;
    }
    return binary;
}

string convertingAnfractPartToBinary(int mantissa, double fract1, string fractsBin) {
    for (int i = 0; i < mantissa; i++) {//Переводим дробную часть в 2СС
        int new_number = fract1 * 2;
        fract1 = fract1 * 2 - new_number;
        fractsBin += (new_number == 1) ? "1" : "0"; // Добавляем "1" или "0"
    }
    return fractsBin;
}

int main() {
    setlocale(LC_ALL, "rus");
    int grid, mantissa, moving = 0, E;
    string theExhibitor{ "" };
    string floatingPoint{ "0" };
    string fractsBin{ "" };
    string binary{ "" };
    string point{ "." };
    string n{ "" };
    string n_s{ "" };
    string fracts{ "" };
    cin >> n >> grid >> mantissa;

    size_t pos = n.find('.');

    if (pos != string::npos) {
        n_s = n.substr(0, pos); // Целая часть
        fracts = n.substr(pos + 1); // Дробная часть
    }
    else {
        n_s = n; // Если точка не найдена, то вся строка - целая часть
    }
    fracts = "0." + fracts;

    int nInt = stoi(n_s); //целая часть в int

    if (n_s[0] == '-') { //определяем знаковый разряд
        floatingPoint[0] = '1';
    }
    else {
        floatingPoint[0] = '0';
    }
    stringstream ss;
    ss << fracts;
    double fract;
    ss >> fract; //перевод из строки в double

    double fract1 = abs(fract);

    int n1 = abs(nInt);
    int n2 = n1; //переменная для перевода в 2СС

    binary = convertingAnIntegerPartToBinary(n2, binary); //переводим целую часть

    //Переводим дробную часть в 2СС
    double fract2 = fract;
    fractsBin = convertingAnfractPartToBinary(mantissa, fract2, fractsBin); //Перевод дробной части в 2 СС

    //находим экспоненту
    int exponent = grid - mantissa - 1;
    E = 0; //стандартное смещение

    int k = binary.length();
    string binarys{ "" };
    if (n1 == 0) {
        moving = 0;
        while (fract2 < 0.1) {
            fract2 = fract2 * 2;
            moving++;
        }
    }
    if (n1 > 0) {
        moving = k;
    }

    E = E + moving; //нашли экспоненту в 10СС
    if ((n1 + E) > (pow(2, exponent) - 1)) { //проверяем влазит ли в экспоненту
        for (int i = 0; i < grid - mantissa - 1; i++) {//выводим бесконечность, если число со смещением не влазит в экспоненту
            floatingPoint = floatingPoint + "1"; //экспонента
        }
        for (int i = 0; i < mantissa; i++) {
            floatingPoint = floatingPoint + "0"; //мантисса
        }
        cout << floatingPoint << " - Бесконечность в 2СС в формате с плавающей точкой" << endl;
        return 0;
    }

    while (E > 0) { //перевод в двоичную СС целой части
        int number = E % 2;
        E = E / 2;
        string numbers = to_string(number);
        theExhibitor = numbers + theExhibitor; // Добавляем в начало
    }
    int k5 = theExhibitor.length();
    while (k5 < (grid - 1 - mantissa)) { //дополняем нулями экспоненту при необходимости
        theExhibitor = "0" + theExhibitor;
        k5++;
    }

    string fractsBin1 = "0." + fractsBin;

    //Находим мантиссу
    string mantiss_string{ "" }; //надо ограничить определенным кол-вом символов

    int k1 = mantissa - binary.length();

    fractsBin1 = fractsBin.substr(0, k1);//обрезаем дробную двоичную строку по требованию разрядности
    mantiss_string = binary + fractsBin1;

    //Находим итоговое число с плавующей точкой
    floatingPoint = floatingPoint + "." + mantiss_string + "." + theExhibitor;
    cout << floatingPoint << endl;
    return 0;
}
//     ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄
//     ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀▄
//    ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄
//    ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄
//   █▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌
//   ▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐   ▄▄
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀
//  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀
