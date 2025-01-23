#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x2, k, m;
    char x_s[100] = "", x[100]="", s[100] = "", fracts[100] = "", number_s[100] = "", point[10]=".", s1[100]="";
    double x1, fract_x, sum_fract = 0.0;
    char new_fract_s[100]="";
    printf("Введите число ");
    scanf("%s", x); 
    printf("Введите начальную СС ");
    scanf("%d", &k);
    printf("Введите новую СС ");
    scanf("%d", &m);
    int sum = 0;
    // 1. Создаем копию строки x для strtok
    char x_copy[100];
    strcpy(x_copy, x);
    // 2. Используем strtok для разделения строки на части
    char* token = strtok(x_copy, point); 

    // 3. Выводим результат
    if (token != NULL) {
        strcpy(x_s, token);
    } 

    // 4. Получаем дробную часть
    token = strtok(NULL, point); 
    if (token != NULL) {
        strcpy(fracts, token);
    } 
    int k2=strlen(fracts);

    int fractx=atoi(fracts);//переводим дробную строку в инт
    x2=atoi(x_s);//переводим целую часть в int

    for (int i = 0; x2 > 0; i = i + 1) {//перевод целой части в 10СС
        int remains = x2 % 10;
        double power = pow(k, i);
        sum = sum + power * remains;
        x2 = x2 / 10;
    }

    double sum_fract_double = 0.0; //перевод дробной части в 10СС
    for (int i = -1 * k2; fractx > 0; i++) {
        int remains_fract = fractx % 10;
        double power_fract = pow(k, i);
        sum_fract_double += remains_fract * power_fract; 
        fractx = fractx / 10;
    }
    
    int new_number=0;
    while (sum>0){//Переводим целую часть в новую СС
        new_number=sum%m;
        sprintf(number_s,"%d", new_number);
        strcat(s, number_s);
        sum=sum/m;
    }
    
    int len = strlen(s);//Переворачиваем строку целой части
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

    new_number=0;
    while (k2>0){//Переводим дробную часть
        int new_number=sum_fract_double*m;
        sum_fract_double=sum_fract_double*m-new_number;
        sprintf(new_fract_s, "%d", new_number);
        strcat(s1, new_fract_s);
        k2=k2-1;
    }
    if (strlen(s1)!=0){
      strcat(s, ".");
      strcat(s, s1);
    }
    printf("%s", s);
    return 0;
}