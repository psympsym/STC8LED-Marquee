/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

/* ---------------------------------- ��չ���� ---------------------------------- */
uint8 direction_flag = 1; // �����־

/* ---------------------------------- ˽�б��� ---------------------------------- */
uint8 LED_PORT = 0; // LEDλѡ

/* ----------------------------------- ���� ---------------------------------- */

/**
 * @brief LED�������������
 * @param none
 * @note 
*/
void LEDChange()
{
    if (direction_flag) // ѡ����
    {
        LED_PORT++;
    }
    else
    {
        LED_PORT--;
    }

    if (LED_PORT > 4)
    {
        LED_PORT = 1;
    }
    else if (LED_PORT < 1)
    {
        LED_PORT = 4;
    }

    switch (LED_PORT) // LEDλѡ
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