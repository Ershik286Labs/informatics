#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void bubbleSort(vector<double>& v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void calculation(vector<double>& v, int size, string number, string& itog) {
    if (v.size() == 1) {
        itog = number + " " + itog;
        return;
    }

    double min_dif = -1; // Инициализируем минимальную разность
    int split_index = -1; // Индекс разделения

    bubbleSort(v, v.size()); // Сортировка по возрастанию

    double sum = 0;
    for (double val : v) sum += val; // Сумма всех элементов

    double left_sum = 0;
    for (int i = 1; i < size; ++i) { // Перебираем все возможные точки разделения
        left_sum += v[i - 1];
        double right_sum = sum - left_sum;
        double past_dif = abs(left_sum - right_sum);
        if (min_dif == -1 || past_dif < min_dif) {
            min_dif = past_dif;
            split_index = i;
        }
    }

    vector<double> left_massive(v.begin(), v.begin() + split_index); //от начала дин. массива до индекса разделения
    vector<double> right_massive(v.begin() + split_index, v.end()); //от индекса разделения до конца

    calculation(left_massive, left_massive.size(), number + "1", itog);
    calculation(right_massive, right_massive.size(), number + "0", itog);
}

int main() {
    int n;
    cin >> n;
    string itog{ "" };

    vector<double> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    calculation(v, v.size(), "", itog); // Передаем правильный размер
    cout << itog << endl;
    return 0;
}