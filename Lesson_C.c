#define qLes 4; // ���������� ������ �� ������� ��������� �������

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int iqLes = qLes;  // ���������� ������ �� ������� ��������� ������� � int �������
    unsigned int numLes = 0;    // ��������� ������������� �������� � ������� int
    char strVal[2];  // ��������� ������������� �������� � ������� ������
    while(1) {
        printf("������� �� ������ ����� ������ ��������� [1..%d]:", iqLes);
        scanf("%s", strVal);
        numLes = atoi(strVal);
        printf("��������� �������� %d\n", numLes);
        if(numLes > 0 && numLes <= iqLes) break;
        printf("������� ������������ ��������.\n");
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