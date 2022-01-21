/* 
   Автор: Белов Андрей
   Дата: 21.01.2022
   Выполнение домашних заданий по подготовительному курсу "Основы языка С"
*/
#define qLes 4 // Количество уроков, за которые выполнены задания
#define maxVolt 10000 // Максимально допустимое значение напряжения для ввода
#define maxR 1000000 // Максимально допустимое значение сопротивления для ввода
#define minVal 0 // Минимально допустимое значение для ввода (задание 2)
#define maxVal 100 // Максимально допустимое значение для ввода (задание 2)

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int iqLes = qLes;  // Количество уроков за которые выполнены задания в int формате
    unsigned int numLes = 0;    // Введенное пользователем значение в формате int
    char strVal[10];  // Введенное пользователем значение в формате строки
    while(numLes < 1 || numLes > iqLes) {
        printf("Задание по какому уроку хотите выполнить [1..%d]: ", iqLes);
        scanf("%s", strVal);
        numLes = atoi(strVal);
        if(numLes > 0 && numLes <= iqLes) break;
        printf("Введено некорректное значение.\n");
    }
    printf("Выбран урок %d\n", numLes);
    switch (numLes)
    {
    case 1: { // Урок 1 - расчет резистивного делителя
        double Ui; // Значение входного напряжения
        double R1; // Значение 1го сопротивления
        double R2; // Значение 2го сопротивления
        double I;  // Значение тока в цепи

        do {
            printf("Введите значение входного напряжения Ui (0..%d] В: ", maxVolt);
            scanf("%s",strVal);
            Ui = atof(strVal);
            if(Ui <= 0 || Ui > maxVolt) printf("Введено неккоретное значение.\n");
        } while(Ui <= 0 || Ui > maxVolt);
        do {
            printf("Введите значение сопротивления R1 (0..%d] Ом: ", maxR);
            scanf("%s",strVal);
            R1 = atof(strVal);
            if(R1 <= 0 || R1 > maxR) printf("Введено неккоретное значение.\n");
        } while(R1 <= 0 || R1 > maxR);
        do {
            printf("Введите значение сопротивления R2 (0..%d] Ом: ", maxR);
            scanf("%s",strVal);
            R2 = atof(strVal);
            if(R2 <= 0 || R2 > maxR) printf("Введено неккоретное значение.\n");
        } while(R2 <= 0 || R2 > maxR);
        I = Ui / (R1 + R2);
        printf("Расчетный ток в цепи %f А\n", I);
        printf("Расчетное напряжение на сопротивлении R1 %f В\n", I * R1);
        printf("Расчетная выделяемая мощность на сопротивлении R1 %f Вт\n", I * (I * R1));
        printf("Расчетное напряжение на сопротивлении R2 %f В\n", I * R2);
        printf("Расчетная выделяемая мощность на сопротивлении R2 %f Вт\n", I * (I * R2));
        
    } break; // Конец блока 1го урока
    case 2: { // Урок 2 - проверка попадания введенного значения в диапазон
        double userNum;
        do {
            printf("Введите значение из диапазона [%d..%d]: ", minVal, maxVal);
            scanf("%s",strVal);
            userNum = atof(strVal);
            if(userNum < minVal || userNum > maxVal) printf("Введено неккоретное значение.\n");
        } while(userNum < minVal || userNum > maxVal);
        printf("Bingo!!");
    } break; // Конец блока 2го урока
    case 3: { // Урок 3

    } break; // Конец блока 3го урока
    case 4: { // Урок 4

    } break; // Конец блока 4го урока

    default:
        break;
    }
    

    return 0;
}