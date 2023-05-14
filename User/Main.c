#include ".\inc\STC8Ax_REG.h"
#include ".\inc\Definition.h"

#include ".\inc\Init.h"
#include ".\inc\KeyServices.h"
#include ".\inc\Timing.h"

/* ��չ���� -------------------------------------------------------*/
code const uint8_t DigDisplay_table[] = // ��׼�ֿ�
{
//  0     1     2     3     4    5     6     7     8     9
    0xFC, 0x60, 0xDA, 0xF2, 0x66,0xB6, 0xBE, 0xE0, 0xFE, 0xF6,
//  u     n    black  -     o     F
    0x7C, 0xEC, 0x00, 0x02, 0x3A, 0x8E,
};

/*=================================================================*/
void main()
{
    System_Init();     // IO�ڳ�ʼ��
    Peripheral_Init(); // �������ж�
    Time0_Config();    // ����ƿ�ʼ��ʱ
    Time1_Config();    // ����ɨ�裬 �����ɨ��
    while (1)
    {
        KeyServices();
    }
}