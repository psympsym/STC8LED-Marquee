/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

/* ---------------------------------- ��չ���� ---------------------------------- */
uint8 direction_flag = 1; // �����־

/* ---------------------------------- ˽�б��� ---------------------------------- */
uint8 count = 0; // LEDλѡ

/* ----------------------------------- ���� ---------------------------------- */

/**
 * @brief LED�������������
 * @param none
 * @note 
*/
void LEDChange()
{
    // ��ʼ��LED
    // led_dr1 = 1;
    // led_dr2 = 1;
    // led_dr3 = 1;
    // led_dr4 = 1;

    if (direction_flag) // ѡ����
    {
        count++;
    }
    else
    {
        count--;
    }

    if (count > 4)
    {
        count = 1;
    }
    else if (count < 1)
    {
        count = 4;
    }

    switch (count) // LEDλѡ
    {
    case 1:
        P0 = 0x7F;
        //led_dr1 = 0;
        break;
    case 2:
        P0 = 0xBF;
        //led_dr2 = 0;
        break;
    case 3:
        P0 = 0xDF;
        //led_dr3 = 0;
        break;
    case 4:
        P0 = 0xEF;
        //led_dr4 = 0;
        break;
    default:
        break;
    }
}