/* 包含头文件 */
#include "Main.h"

/*=================================================================*/
void main()
{
    System_Init();     // IO口初始化
    Peripheral_Init(); // 开启总中断
    Time0_Config();    // 跑马灯开始计时
    Time1_Config();    // 按键扫描， 数码管扫描
    while (1)
    {
		KeyScan();
		KeyServices();
    }
}