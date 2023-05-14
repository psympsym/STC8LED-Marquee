/* ---------------------------------- 包含头文件 --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

/* ---------------------------------- 扩展变量 ---------------------------------- */
uint8 direction_flag = 1; // 方向标志

/* ---------------------------------- 私有变量 ---------------------------------- */
uint8 LED_PORT = 0; // LED位选

/* ----------------------------------- 函数 ---------------------------------- */

/**
 * @brief LED跑马灯驱动程序
 * @param none
 * @note 
*/
void LEDChange()
{
    if (direction_flag) // 选择方向
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

    switch (LED_PORT) // LED位选
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