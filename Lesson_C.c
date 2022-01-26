/* 
   �����: ����� ������
   ����: 21.01.2022
   ���������� �������� ������� �� ����������������� ����� "������ ����� �"
*/
#define qLes 10 // ���������� ������, �� ������� ��������� �������
#define maxVolt 10000 // ����������� ���������� �������� ���������� ��� �����
#define maxR 1000000 // ����������� ���������� �������� ������������� ��� �����
#define minVal 0 // ���������� ���������� �������� ��� ����� (������� 2)
#define maxVal 100 // ����������� ���������� �������� ��� ����� (������� 2)
#define numVal 10 // ���������� �����, ������� ���������� ������ ������������ (������� 3)
#define maxLine 15 // ������������ ���������� ����� ��� ����� (������� 4)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calc2Equal (int a, int b, int c, float *x1, float *x2); // �������� ������� ���������� ����������� ���������
int evenTest( int *mas, int qmas); // �������� ������� �������� �������� ��������� �������
int int2binstr (int value, char *str); // �������� ������� �������� ����� � �������� ���

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
    case 1: { // ���� 1 - ������ ������������ �������� ==========================================================================
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

    case 2: { // ���� 2 - �������� ��������� ���������� �������� � �������� =====================================================
        double userNum; // �����, ��������� �������������
        do {
            printf("������� �������� �� ��������� [%d..%d]: ", minVal, maxVal);
            scanf("%s",strVal);
            userNum = atof(strVal);
            if(userNum < minVal || userNum > maxVal) printf("������� ����������� ��������.\n");
        } while(userNum < minVal || userNum > maxVal);
        printf("Bingo!!");
    } break; // ����� ����� 2�� �����
    case 3: { // ���� 3
        double avgNum = 0; // ������� �������������� ��������
        double usrNum;  // �����, ��������� �������������
        unsigned int cNum; // ������� ��������� ��������
        printf("������� %d �������� ��������. ������������ �������� ����� ������� ��� ����.\n", numVal);
        for(cNum = 0; cNum < numVal; cNum++) {
            printf("������� �������� %d �����: ", cNum);
            scanf("%s", strVal);
            usrNum = atof(strVal);
            avgNum += usrNum; // ���� ������� �����
            printf("��������� ���� ����� %f. ������� �������������� �� ������� ������ %f\n", usrNum, avgNum / (cNum + 1));
        }
    } break; // ����� ����� 3�� �����

    case 4: { // ���� 4 - ���������� �������� ^ �������������� ����������� �� ��������� ������������� ���������� ����� ==========
              // �������������� ����������� - � �������� ��� ������� ����� ���������� ����� � ���������� �� ���������
              // ��������, ��� ����� ����� ���������� ������ �� �������� ���������� �����
        unsigned int usrNum; // ����� �����, ��������� �������������
        unsigned int maxX; // ���������� �������� ��� ���������
        printf("������� �������� ����� ����� � ��������� [3..%d]: ", maxLine);
        do {
            scanf("%s", strVal);
            usrNum = atoi(strVal);            
            if(usrNum < 3 || usrNum > maxLine || (usrNum % 2 == 0)) printf("������� ������������ ��������.\n");
        } while(usrNum < 3 || usrNum > maxLine || (usrNum % 2 == 0));
        maxX = usrNum / 2 + 1;
        //printf("����� ����� %d, ����� �������� %d\n", usrNum, maxX);
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
    } break; // ����� ����� 4�� �����

    case 5: { // ������� 5 - ���������. ���������� ��������� ���������� ���������. ==============================================
        int a, b, c; // ������������
        int result; // ���������� ���������� ������ 
        float x1, x2; // ����� ���������
        printf("���� ������������� ����������� ���������.\n������� ����� ����� a �� ������ 0: ");
        do {
            scanf("%s", strVal);
            a = atoi(strVal);
            if(a == 0) printf("������� ������������ ��������.\n");
        } while (a == 0);
        printf("������� ����� ����� b: ");
        scanf("%s", strVal);
        b = atoi(strVal);
        printf("������� ����� ����� c: ");
        scanf("%s", strVal);
        c = atoi(strVal);
        printf("������� ���������� ��������� %d*x^2 + %d*x + %d = 0\n", a, b, c);
        result = calc2Equal(a, b, c, &x1, &x2);
        if(result == -1) printf("��������� �� ����� ������.\n");
        if(result == 0) printf("��������� ����� ���� ������: %f\n", x1);
        if(result == 1) printf("��������� ����� ��� �����: %f � %f\n", x1, x2); 
    } break; // ����� 5�� �������

    case 6: { // ������� 6 - ������� ============================================================================================
        int qmas = 0; // ������ �������� �������
        int *mas = NULL; // ������ ����� �����
        int i; // ������� �������
        printf("������� ������ ������� ����� �����: ");
        scanf("%s", strVal);
        qmas = atoi(strVal);
        if(qmas == 0) { 
            printf("�� ����� ������� ������ �������.\n"); 
            break;
        }
        mas = (int *) malloc(qmas);
        if(mas == NULL) {
            printf("�� ������� �������� ������ ��� �������\n");
            break;
        }
        printf("���������� ������ %d ����� ����� ��� ���������� �������\n", qmas);
        printf("��� ����������� ��������� �������� ����� ���������� 0\n");
        for (i = 0; i < qmas; i++) { // ��������� ������ ������ �������
            printf("������� %d �����: ", i + 1);
            scanf("%s", strVal);
            mas[i] = atoi(strVal);
        }
        printf("��������� ������ ������� %d. ��������� ������: \n", qmas);
        for (i = 0; i < qmas; i++) {
            printf("%d ", mas[i]);
        }
        printf("\n");

        if(evenTest(mas, qmas) == 0) {
            printf("�� ��������� ��������� ����������� �������� �����\n");
        } else {
            printf("������������ ������: ");
            for (i = 0; i < qmas; i++) {
                printf("%d ", mas[i]);
            }
            printf("\n");            
        }
        free(mas);
    } break; // ����� 6�� �������

    case 7: { // ������� 7 - ���������� ���� ������
        int qmas = 0; // ������ �������� �������
        unsigned int *mas = NULL; // ������ ����� �����
        int i; // ������� �������
        printf("������� ������ ������� ����� �����: ");
        scanf("%s", strVal);
        qmas = atoi(strVal);
        if(qmas == 0) { 
            printf("�� ����� ������� ������ �������.\n"); 
            break;
        }
        mas = (unsigned int *) malloc(qmas);
        if(mas == NULL) {
            printf("�� ������� �������� ������ ��� �������\n");
            break;
        }
        printf("���������� ������ %d ����� ������������� ����� ��� ���������� �������\n", qmas);
        printf("��� ����������� ��������� �������� ����� ���������� 0\n");
        for (i = 0; i < qmas; i++) { // ��������� ������ ������ �������
            printf("������� %d �����: ", i + 1);
            scanf("%s", strVal);
            mas[i] = atoi(strVal);
            if(mas[i] < 0) mas[i] = mas[i] * -1; // ���� ������� ������������� �����, ����������� � �������������
        }
        printf("��������� ������ ������� %d.\n��������� ������ (int  ) � HEX: ", qmas);
        for (i = 0; i < qmas; i++) {
            printf("%d(%#x-%d) ", (unsigned int) mas[i], (unsigned int) mas[i], sizeof((unsigned int) mas[i]));
        }
        printf("\n");
        printf("��������� ������ (short) � HEX: ");
        for (i = 0; i < qmas; i++) {
            printf("%d(%#x-%d) ", (unsigned short) mas[i], (unsigned short) mas[i], sizeof((unsigned short) mas[i]));
        }
        printf("\n");
    } break; // ����� 7�� �������   
    
    case 8: { // ������� 8 - ������. �������� �������, ������������ ���������� ����� � �������� ���� (�������)
        int usrNum; // �����, ��������� �������������
        char binStr[32]; // ������������� ������ ����� (int) � �������� ����
        printf("������� ����� �����: ");
        scanf("%s", strVal);
        usrNum = atoi(strVal);
        if(!int2binstr(usrNum, binStr)) {
            printf("���� ����� � �������� ����: ");
            for (int i = 31; i > -1; i--) // ����� �������� ������
            {
                printf("%d", binStr[i]);
            }
            printf("\n");
        }
    } break; // ����� 8�� �������

    case 9: { // ������� 9 - ���������.

    } break; // ����� 9�� �������

    case 10: { // ������� 10 - ��������� ������

    } break; // ����� 10�� �������

    default:
        break;
    }
    

    return 0;
}

/**
 * @brief ������� ���������� ����������� ���������
 * 
 * @param a ������ ��������
 * @param b ������ ��������
 * @param c ������ ��������
 * @param x1 ������ ������ ����������� ���������
 * @param x2 ������ ������ ����������� ���������
 * @return int ���������� -1, ���� ��������� �� ����� ������, 0 - ���� ���� ���� ������, 1 - ���� ��� �����
 */
int calc2Equal (int a, int b, int c, float *x1, float *x2) {
    if (a == 0) return -1; // �������� a �� ����� ���� ����� 0
    float D = b*b - 4 * a * c; // �������� ������������
    if(D < 0) return -1; // ���� ������������ < 0, �� ������ ���
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
 * @brief �������, ����������� ������ �� ������� �������� �����. ��������� ��, ���� ��� ����.
 * 
 * @param mas ��������� �� ������������ ������ ����� �����
 * @param qmas ������ �������
 * @return int ���������� 0 - ���� ��� �������� �����, 1 - ���� ����
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
 * @brief ������� ����������� ������ ����������� ����� � �������� ��� (� ���� ������)
 * 
 * @param value ���������� ����� ����� ��� ��������
 * @param str ��������� �� ������ (char *) ��� ����������
 * @return int ���������� 0 - ���� ���������� ���������, ����� - -1
 */
int int2binstr (int value, char *str) {
    int mask = 1; // ����� ��� �������� �������������
    for (int i = 0; i < 32; i++) { // ����� �� �������� � ������ (��� ���� int - 32)
        str[i] = (value & mask) ? 1 : 0;
        mask = mask * 2;
    }    
    return 0;
}