/* ---------------------------------- 包含头文件 --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

#include "..\Main.h"
#include "..\inc\LEDChange.h"

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
            if (TR0 == 1) // 跑马灯开启
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
            else if (TR0 == 0) // 跑马灯暂停 显示o
            {
                DigShow_PORT = DigDisplay_table[14]; 
            }
            break;
        case 2: // 第二位数码管显示
            DigShow_COM = 0xFB;
            if (TR0 == 1) // 跑马灯开启 显示-
            {
                DigShow_PORT = DigDisplay_table[13];
            }
            else if (TR0 == 0) // 跑马灯暂停 显示F
            {
                DigShow_PORT = DigDisplay_table[15];
            }
            break;
        case 3: // 第三位数码管显示
            DigShow_COM = 0xFD;
            if (TR0 == 1)
            {
                DigShow_PORT = DigDisplay_table[speed_second];
            }
            else if (TR0 == 0) // 跑马灯暂停 关闭数码管
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        case 4: // 第四位数码管显示
            DigShow_COM = 0xFE;
            if (TR0 == 1)
            {
                DigShow_PORT = DigDisplay_table[speed_first];
            }
            else if (TR0 == 0) // 跑马灯暂停 关闭数码管
            {
                DigShow_PORT = DigDisplay_table[12];
            }
            break;
        default:
            break;
    }
}