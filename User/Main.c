/* ����ͷ�ļ� */
#include "Main.h"

/*=================================================================*/
void main()
{
    System_Init();     // IO�ڳ�ʼ��
    Peripheral_Init(); // �������ж�
    Time0_Config();    // ����ƿ�ʼ��ʱ
    Time1_Config();    // ����ɨ�裬 �����ɨ��
    while (1)
    {
		KeyScan();
		KeyServices();
    }
}