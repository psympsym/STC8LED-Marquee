/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "NixieTube.h"


code const uint8_t DigDisplay_table[] = // ��׼�ֿ�
{
//   0     1     2     3     4    5     6     7     8     9
    0xFC, 0x60, 0xDA, 0xF2, 0x66,0xB6, 0xBE, 0xE0, 0xFE, 0xF6,
//   u     n    black  -     o     F
    0x7C, 0xEC, 0x00, 0x02, 0x3A, 0x8E,
};

/* ˽�к궨�� */
#define DigShow_PORT 	            P1			//����ܶ�ѡ����
#define DigShow_COM 	 	        P2			//�����λѡ����

/* ---------------------------------- ��չ���� ---------------------------------- */
uint8 LEDChangeTime = 30; // LED�仯ʱ��x10ms

/* ---------------------------------- ˽�б��� ---------------------------------- */
uint8 digit_seg_en = 0; // �����λѡ
uint8 speed_second = 0; // �ٶȵڶ�λ
uint8 speed_first = 0; // �ٶȵ�һλ

/* ----------------------------------- ���� ---------------------------------- */
void NixieTube()
{
    speed_second = LEDChangeTime / 10;  // ȡ�ٶȵڶ�λ
    speed_first =  LEDChangeTime % 10;  // ȡ�ٶȵ�һλ
	// ��λ����
    digit_seg_en++;
    if (digit_seg_en > 4)
    {
        digit_seg_en = 1;
    }

    switch (digit_seg_en)
    {
        case 1: // ��һλ�������ʾ
            DigShow_COM = 0xF7;
            if (TR1 == 1) // ����ƿ���
            {
                if (direction_flag == 1) // ��������ʾn
                {
                    DigShow_PORT = DigDisplay_table[11];
                }
                else                     // ������ʾu
                {
                    DigShow_PORT = DigDisplay_table[10];
                }
            }
            else if (TR1 == 0) // �������ͣ ��ʾo
            {
                DigShow_PORT = DigDisplay_table[14]; 
            }
            break;
        case 2: // �ڶ�λ�������ʾ
            DigShow_COM = 0xFB;
            if (TR1 == 1) // ����ƿ��� ��ʾ-
            {
                DigShow_PORT = DigDisplay_table[13];
            }
            else if (TR1 == 0) // �������ͣ ��ʾF
            {
                DigShow_PORT = DigDisplay_table[15];
            }
            break;
        case 3: // ����λ�������ʾ
            DigShow_COM = 0xFD;
            if (TR1== 1)
            {
                DigShow_PORT = DigDisplay_table[speed_second];
            }
            else if (TR1 == 0) // �������ͣ �ر������
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        case 4: // ����λ�������ʾ
            DigShow_COM = 0xFE;
            if (TR1 == 1)
            {
                DigShow_PORT = DigDisplay_table[speed_first];
            }
            else if (TR1== 0) // �������ͣ �ر������
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        default:
            break;
    }
}