/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

#include "..\Main.h"
#include "..\inc\LEDChange.h"

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
            if (TR0 == 1) // ����ƿ���
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
            else if (TR0 == 0) // �������ͣ ��ʾo
            {
                DigShow_PORT = DigDisplay_table[14]; 
            }
            break;
        case 2: // �ڶ�λ�������ʾ
            DigShow_COM = 0xFB;
            if (TR0 == 1) // ����ƿ��� ��ʾ-
            {
                DigShow_PORT = DigDisplay_table[13];
            }
            else if (TR0 == 0) // �������ͣ ��ʾF
            {
                DigShow_PORT = DigDisplay_table[15];
            }
            break;
        case 3: // ����λ�������ʾ
            DigShow_COM = 0xFD;
            if (TR0 == 1)
            {
                DigShow_PORT = DigDisplay_table[speed_second];
            }
            else if (TR0 == 0) // �������ͣ �ر������
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        case 4: // ����λ�������ʾ
            DigShow_COM = 0xFE;
            if (TR0 == 1)
            {
                DigShow_PORT = DigDisplay_table[speed_first];
            }
            else if (TR0 == 0) // �������ͣ �ر������
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        default:
            break;
    }
}