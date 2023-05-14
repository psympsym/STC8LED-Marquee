#include ".\inc\STC8Ax_REG.h"
#include ".\inc\Definition.h"

#include ".\inc\Init.h"
#include ".\inc\KeyServices.h"
#include ".\inc\Timing.h"

/* 扩展变量 -------------------------------------------------------*/
code const uint8_t DigDisplay_table[] = // 标准字库
{
//  0     1     2     3     4    5     6     7     8     9
    0xFC, 0x60, 0xDA, 0xF2, 0x66,0xB6, 0xBE, 0xE0, 0xFE, 0xF6,
//  u     n    black  -     o     F
    0x7C, 0xEC, 0x00, 0x02, 0x3A, 0x8E,
};

/*=================================================================*/
void main()
{
    System_Init();     // IO口初始化
    Peripheral_Init(); // 开启总中断
    Time0_Config();    // 跑马灯开始计时
    Time1_Config();    // 按键扫描， 数码管扫描
    while (1)
    {
        KeyServices();
    }
}