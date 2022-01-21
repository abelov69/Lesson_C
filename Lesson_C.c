#define qLes 4; //  оличество уроков за которые выполнены задани€

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int iqLes = qLes;  //  оличество уроков за которые выполнены задани€ в int формате
    unsigned int numLes = 0;    // ¬веденное пользователем значение в формате int
    char strVal[2];  // ¬веденное пользователем значение в формате строки
    while(1) {
        printf("«адание по какому уроку хотите выполнить [1..%d]:", iqLes);
        scanf("%s", strVal);
        numLes = atoi(strVal);
        printf("¬веденное значение %d\n", numLes);
        if(numLes > 0 && numLes <= iqLes) break;
        printf("¬ведено некорректное значение.\n");
    }
    switch (numLes)
    {
    case 1:
        /* code */
        break;
    case 2:

        break;
    
    default:
        break;
    }
    

    return 0;
}