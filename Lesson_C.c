/* 
   �����: ����� ������
   ����: 21.01.2022
   ���������� �������� ������� �� ����������������� ����� "������ ����� �"
*/
#define qLes 4 // ���������� ������, �� ������� ��������� �������
#define maxVolt 10000 // ����������� ���������� �������� ���������� ��� �����
#define maxR 1000000 // ����������� ���������� �������� ������������� ��� �����
#define minVal 0 // ���������� ���������� �������� ��� ����� (������� 2)
#define maxVal 100 // ����������� ���������� �������� ��� ����� (������� 2)

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int iqLes = qLes;  // ���������� ������ �� ������� ��������� ������� � int �������
    unsigned int numLes = 0;    // ��������� ������������� �������� � ������� int
    char strVal[10];  // ��������� ������������� �������� � ������� ������
    while(numLes < 1 || numLes > iqLes) {
        printf("������� �� ������ ����� ������ ��������� [1..%d]: ", iqLes);
        scanf("%s", strVal);
        numLes = atoi(strVal);
        if(numLes > 0 && numLes <= iqLes) break;
        printf("������� ������������ ��������.\n");
    }
    printf("������ ���� %d\n", numLes);
    switch (numLes)
    {
    case 1: { // ���� 1 - ������ ������������ ��������
        double Ui; // �������� �������� ����������
        double R1; // �������� 1�� �������������
        double R2; // �������� 2�� �������������
        double I;  // �������� ���� � ����

        do {
            printf("������� �������� �������� ���������� Ui (0..%d] �: ", maxVolt);
            scanf("%s",strVal);
            Ui = atof(strVal);
            if(Ui <= 0 || Ui > maxVolt) printf("������� ����������� ��������.\n");
        } while(Ui <= 0 || Ui > maxVolt);
        do {
            printf("������� �������� ������������� R1 (0..%d] ��: ", maxR);
            scanf("%s",strVal);
            R1 = atof(strVal);
            if(R1 <= 0 || R1 > maxR) printf("������� ����������� ��������.\n");
        } while(R1 <= 0 || R1 > maxR);
        do {
            printf("������� �������� ������������� R2 (0..%d] ��: ", maxR);
            scanf("%s",strVal);
            R2 = atof(strVal);
            if(R2 <= 0 || R2 > maxR) printf("������� ����������� ��������.\n");
        } while(R2 <= 0 || R2 > maxR);
        I = Ui / (R1 + R2);
        printf("��������� ��� � ���� %f �\n", I);
        printf("��������� ���������� �� ������������� R1 %f �\n", I * R1);
        printf("��������� ���������� �������� �� ������������� R1 %f ��\n", I * (I * R1));
        printf("��������� ���������� �� ������������� R2 %f �\n", I * R2);
        printf("��������� ���������� �������� �� ������������� R2 %f ��\n", I * (I * R2));
        
    } break; // ����� ����� 1�� �����
    case 2: { // ���� 2 - �������� ��������� ���������� �������� � ��������
        double userNum;
        do {
            printf("������� �������� �� ��������� [%d..%d]: ", minVal, maxVal);
            scanf("%s",strVal);
            userNum = atof(strVal);
            if(userNum < minVal || userNum > maxVal) printf("������� ����������� ��������.\n");
        } while(userNum < minVal || userNum > maxVal);
        printf("Bingo!!");
    } break; // ����� ����� 2�� �����
    case 3: { // ���� 3

    } break; // ����� ����� 3�� �����
    case 4: { // ���� 4

    } break; // ����� ����� 4�� �����

    default:
        break;
    }
    

    return 0;
}