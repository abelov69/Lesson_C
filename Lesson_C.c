/* 
   Автор: Белов Андрей
   Дата: 21.01.2022
   Выполнение домашних заданий по подготовительному курсу "Основы языка С"
*/
#define qLes 10 // Количество уроков, за которые выполнены задания
#define maxVolt 10000 // Максимально допустимое значение напряжения для ввода
#define maxR 1000000 // Максимально допустимое значение сопротивления для ввода
#define minVal 0 // Минимально допустимое значение для ввода (задание 2)
#define maxVal 100 // Максимально допустимое значение для ввода (задание 2)
#define numVal 10 // Количество чисел, которые необходимо ввести пользователю (задание 3)
#define maxLine 15 // Максимальное количество строк для ввода (задание 4)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calc2Equal (int a, int b, int c, float *x1, float *x2); // Прототип функции вычисления квадратного уравнения
int evenTest( int *mas, int qmas); // Прототип функции проверки четности элементов массива
int int2binstr (int value, char *str); // Прототип функции перевода числа в бинарный вид

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
    case 1: { // Урок 1 - расчет резистивного делителя ==========================================================================
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

    case 2: { // Урок 2 - проверка попадания введенного значения в диапазон =====================================================
        double userNum; // Число, введенное пользователем
        do {
            printf("Введите значение из диапазона [%d..%d]: ", minVal, maxVal);
            scanf("%s",strVal);
            userNum = atof(strVal);
            if(userNum < minVal || userNum > maxVal) printf("Введено неккоретное значение.\n");
        } while(userNum < minVal || userNum > maxVal);
        printf("Bingo!!");
    } break; // Конец блока 2го урока
    case 3: { // Урок 3
        double avgNum = 0; // среднее арифметическое значение
        double usrNum;  // число, введенное пользователем
        unsigned int cNum; // счетчик введенных значений
        printf("Введите %d числовых значений. Неккоректные значения будут приняты как ноль.\n", numVal);
        for(cNum = 0; cNum < numVal; cNum++) {
            printf("Введите значение %d числа: ", cNum);
            scanf("%s", strVal);
            usrNum = atof(strVal);
            avgNum += usrNum; // пока считаем сумму
            printf("Введенное вами число %f. Среднее арифметическое на текущий момент %f\n", usrNum, avgNum / (cNum + 1));
        }
    } break; // Конец блока 3го урока

    case 4: { // Урок 4 - нарисовать символом ^ равнобедренный треугольник на указанном пользователем количестве строк ==========
              // Равнобедренный треугольник - у которого две стороны имеют одинаковую длину и отличаются от основания
              // Очевидно, что такой можно нарисовать только на нечетном количестве строк
        unsigned int usrNum; // число строк, введенное пользователем
        unsigned int maxX; // количество столбцов для рисования
        printf("Введите нечетное целое число в диапазоне [3..%d]: ", maxLine);
        do {
            scanf("%s", strVal);
            usrNum = atoi(strVal);            
            if(usrNum < 3 || usrNum > maxLine || (usrNum % 2 == 0)) printf("Введено неккоректное значение.\n");
        } while(usrNum < 3 || usrNum > maxLine || (usrNum % 2 == 0));
        maxX = usrNum / 2 + 1;
        //printf("Число строк %d, число столбцов %d\n", usrNum, maxX);
        for(int y = 0; y < usrNum; y++) {
            for(int x = 0; x < maxX; x++) {
                if(y < maxX) {
                    if(x >= (maxX - 1 - y)) printf("^"); else printf(" ");
                } else {
                    if(x > (y - maxX)) printf("^"); else printf(" ");
                }                
            }
            printf("\n");
        }
    } break; // Конец блока 4го урока

    case 5: { // Задание 5 - указатели. Необходимо вычислить квадратное уравнение. ==============================================
        int a, b, c; // Коэффициенты
        int result; // Полученное количество корней 
        float x1, x2; // Корни уравнения
        printf("Ввод коэффициентов квадратного уравнения.\nВведите целое число a не равное 0: ");
        do {
            scanf("%s", strVal);
            a = atoi(strVal);
            if(a == 0) printf("Введено неккоректное значение.\n");
        } while (a == 0);
        printf("Введите целое число b: ");
        scanf("%s", strVal);
        b = atoi(strVal);
        printf("Введите целое число c: ");
        scanf("%s", strVal);
        c = atoi(strVal);
        printf("Введено квадратное уравнение %d*x^2 + %d*x + %d = 0\n", a, b, c);
        result = calc2Equal(a, b, c, &x1, &x2);
        if(result == -1) printf("Уравнение не имеет корней.\n");
        if(result == 0) printf("Уравнение имеет один корень: %f\n", x1);
        if(result == 1) printf("Уравнение имеет два корня: %f и %f\n", x1, x2); 
    } break; // конец 5го задания

    case 6: { // Задание 6 - Массивы ============================================================================================
        int qmas = 0; // Размер будущего массива
        int *mas = NULL; // массив целых чисел
        int i; // счетчик массива
        printf("Введите размер массива целых чисел: ");
        scanf("%s", strVal);
        qmas = atoi(strVal);
        if(qmas == 0) { 
            printf("Вы ввели нулевой размер массива.\n"); 
            break;
        }
        mas = (int *) malloc(qmas);
        if(mas == NULL) {
            printf("Не удалось выделить память для массива\n");
            break;
        }
        printf("Необходимо ввести %d целых чисел для заполнения массива\n", qmas);
        printf("Все неккоректно введенные значения будут приравнены 0\n");
        for (i = 0; i < qmas; i++) { // Заполняем массив целыми числами
            printf("Введите %d число: ", i + 1);
            scanf("%s", strVal);
            mas[i] = atoi(strVal);
        }
        printf("Введенный размер массива %d. Введенный массив: \n", qmas);
        for (i = 0; i < qmas; i++) {
            printf("%d ", mas[i]);
        }
        printf("\n");

        if(evenTest(mas, qmas) == 0) {
            printf("Во введенных значениях отсутствуют нечетные числа\n");
        } else {
            printf("Обработанный массив: ");
            for (i = 0; i < qmas; i++) {
                printf("%d ", mas[i]);
            }
            printf("\n");            
        }
        free(mas);
    } break; // конец 6го задания

    case 7: { // Задание 7 - приведение типа данных
        int qmas = 0; // Размер будущего массива
        unsigned int *mas = NULL; // массив целых чисел
        int i; // счетчик массива
        printf("Введите размер массива целых чисел: ");
        scanf("%s", strVal);
        qmas = atoi(strVal);
        if(qmas == 0) { 
            printf("Вы ввели нулевой размер массива.\n"); 
            break;
        }
        mas = (unsigned int *) malloc(qmas);
        if(mas == NULL) {
            printf("Не удалось выделить память для массива\n");
            break;
        }
        printf("Необходимо ввести %d целых положительных чисел для заполнения массива\n", qmas);
        printf("Все неккоректно введенные значения будут приравнены 0\n");
        for (i = 0; i < qmas; i++) { // Заполняем массив целыми числами
            printf("Введите %d число: ", i + 1);
            scanf("%s", strVal);
            mas[i] = atoi(strVal);
            if(mas[i] < 0) mas[i] = mas[i] * -1; // если введено отрицательное число, преобразуем в положительное
        }
        printf("Введенный размер массива %d.\nВведенный массив (int  ) в HEX: ", qmas);
        for (i = 0; i < qmas; i++) {
            printf("%d(%#x-%d) ", (unsigned int) mas[i], (unsigned int) mas[i], sizeof((unsigned int) mas[i]));
        }
        printf("\n");
        printf("Введенный массив (short) в HEX: ");
        for (i = 0; i < qmas; i++) {
            printf("%d(%#x-%d) ", (unsigned short) mas[i], (unsigned short) mas[i], sizeof((unsigned short) mas[i]));
        }
        printf("\n");
    } break; // конец 7го задания   
    
    case 8: { // Задание 8 - строки. Написать функцию, возвращающую полученное число в бинарном виде (строкой)
        int usrNum; // число, введенное пользователем
        char binStr[32]; // представления целого числа (int) в бинарном виде
        printf("Введите целое число: ");
        scanf("%s", strVal);
        usrNum = atoi(strVal);
        if(!int2binstr(usrNum, binStr)) {
            printf("Ваше число в бинарном виде: ");
            for (int i = 31; i > -1; i--) // вывод символов строки
            {
                printf("%d", binStr[i]);
            }
            printf("\n");
        }
    } break; // конец 8го задания

    case 9: { // Задание 9 - структуры.

    } break; // конец 9го задания

    case 10: { // Задание 10 - выделение памяти

    } break; // конец 10го задания

    default:
        break;
    }
    

    return 0;
}

/**
 * @brief Функция вычисления квадратного уравнения
 * 
 * @param a первый параметр
 * @param b второй параметр
 * @param c третий параметр
 * @param x1 первый корень квадратного уравнения
 * @param x2 второй корень квадратного уравнения
 * @return int возвращает -1, если уравнение не имеет корней, 0 - если есть один корень, 1 - если два корня
 */
int calc2Equal (int a, int b, int c, float *x1, float *x2) {
    if (a == 0) return -1; // параметр a не может быть равен 0
    float D = b*b - 4 * a * c; // получили дескриминант
    if(D < 0) return -1; // если дескриминант < 0, то корней нет
    if(D == 0) {
        *x1 = -b / (2 * a);
        return 0;
    }
    if(D > 0) {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return 1;
    }
    return -1;
}

/**
 * @brief Функция, проверяющая массив на наличие нечетных чисел. Удваивает их, если они есть.
 * 
 * @param mas Указатель на передаваемый массив целых чисел
 * @param qmas Размер массива
 * @return int Возвращает 0 - если нет нечетных чисел, 1 - если есть
 */
int evenTest( int *mas, int qmas) {
    int result = 0;
    for(int i = 0; i < qmas; i++) {
        if(mas[i] % 2 != 0) {
            mas[i] = mas[i] * 2;
            result = 1;
        }
    }
    return result;
}

/**
 * @brief Перевод полученного целого десятичного числа в бинарный вид (в виде строки)
 * 
 * @param value переданное целое число для перевода
 * @param str указатель на строку (char *) для результата
 * @return int возвращаем 0 - если получилось перевести, иначе - -1
 */
int int2binstr (int value, char *str) {
    int mask = 1; // маска для битового представления
    for (int i = 0; i < 32; i++) { // Бежим по символам в строке (для типа int - 32)
        str[i] = (value & mask) ? 1 : 0;
        mask = mask * 2;
    }    
    return 0;
}