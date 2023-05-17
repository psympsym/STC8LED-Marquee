/* ---------------------------------- 包含头文件 --------------------------------- */
#include "NixieTube.h"


code const uint8_t DigDisplay_table[] = // 标准字库
{
//   0     1     2     3     4    5     6     7     8     9
    0xFC, 0x60, 0xDA, 0xF2, 0x66,0xB6, 0xBE, 0xE0, 0xFE, 0xF6,
//   u     n    black  -     o     F
    0x7C, 0xEC, 0x00, 0x02, 0x3A, 0x8E,
};

/* 私有宏定义 */
#define DigShow_PORT 	            P1			//数码管段选引脚
#define DigShow_COM 	 	        P2			//数码管位选引脚

/* ---------------------------------- 扩展变量 ---------------------------------- */
uint8 LEDChangeTime = 30; // LED变化时间x10ms

/* ---------------------------------- 私有变量 ---------------------------------- */
uint8 digit_seg_en = 0; // 数码管位选
uint8 speed_second = 0; // 速度第二位
uint8 speed_first = 0; // 速度第一位

/* ----------------------------------- 函数 ---------------------------------- */
void NixieTube()
{
    speed_second = LEDChangeTime / 10;  // 取速度第二位
    speed_first =  LEDChangeTime % 10;  // 取速度第一位
	// 移位操作
    digit_seg_en++;
    if (digit_seg_en > 4)
    {
        digit_seg_en = 1;
    }

    switch (digit_seg_en)
    {
        case 1: // 第一位数码管显示
            DigShow_COM = 0xF7;
            if (TR1 == 1) // 跑马灯开启
            {
                if (direction_flag == 1) // 方向正显示n
                {
                    DigShow_PORT = DigDisplay_table[11];
                }
                else                     // 方向负显示u
                {
                    DigShow_PORT = DigDisplay_table[10];
                }
            }
            else if (TR1 == 0) // 跑马灯暂停 显示o
            {
                DigShow_PORT = DigDisplay_table[14]; 
            }
            break;
        case 2: // 第二位数码管显示
            DigShow_COM = 0xFB;
            if (TR1 == 1) // 跑马灯开启 显示-
            {
                DigShow_PORT = DigDisplay_table[13];
            }
            else if (TR1 == 0) // 跑马灯暂停 显示F
            {
                DigShow_PORT = DigDisplay_table[15];
            }
            break;
        case 3: // 第三位数码管显示
            DigShow_COM = 0xFD;
            if (TR1== 1)
            {
                DigShow_PORT = DigDisplay_table[speed_second];
            }
            else if (TR1 == 0) // 跑马灯暂停 关闭数码管
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        case 4: // 第四位数码管显示
            DigShow_COM = 0xFE;
            if (TR1 == 1)
            {
                DigShow_PORT = DigDisplay_table[speed_first];
            }
            else if (TR1== 0) // 跑马灯暂停 关闭数码管
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        default:
            break;
    }
}