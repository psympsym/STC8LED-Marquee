/* ---------------------------------- 包含头文件 --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

/* ---------------------------------- 私有宏定义 --------------------------------- */
#define KEY_TIME 20

/* ---------------------------------- 扩展变量 ---------------------------------- */
uint8 Keysign = 0; // 按键标志

/* ---------------------------------- 私有变量 ---------------------------------- */
uint8 keysign1 = 0; // 按键状态初始化
uint8 keysign2 = 0;
uint8 keysign3 = 0;
uint8 keysign4 = 0;

uint8 keyt1 = 0; // 按键去抖计时
uint8 keyt2 = 0;
uint8 keyt3 = 0;
uint8 keyt4 = 0;

/* ----------------------------------- 函数 ----------------------------------- */
/**
 * @brief 按键扫描
 * @param none
 * @note 改变Keysign的值
*/
void KeyScan()
{
    if (key_sr1 == 1) // k1没被按下
    {
        keysign1 = 0; // 按键1标志
        keyt1 = 0;
    }
    else if (keysign1 == 0) // k1被按下且标志为0
    {
        keyt1++;
        if (keyt1 >= KEY_TIME) // 按键去抖
        {
            keyt1 = 0;
            keysign1 = 1; // 清除标志以防再次进入
            Keysign = 1;
        }
    }

    if (key_sr2 == 1) // k2没被按下
    {
        keysign2 = 0; // 按键2标志
        keyt2 = 0;
    }
    else if (keysign2 == 0)
    {
        keyt2++;
        if (keyt2 >= KEY_TIME) // 按键去抖
        {
            keyt2 = 0;
            keysign2 = 1; // 清除标志以防再次进入
            Keysign = 2;
        }
    }

    if (key_sr3 == 1) // k3没被按下
    {
        keysign3 = 0; // 按键3标志
        keyt3 = 0;
    }
    else if (keysign3 == 0)
    {
        keyt3++;
        if (keyt3 >= KEY_TIME) // 按键去抖
        {
            keyt3 = 0;
            keysign3 = 1; // 清除标志以防再次进入
            Keysign = 3;
        }
    }

    if (key_sr4 == 1) // k4没被按下
    {
        keysign4 = 0; // 按键4标志
        keyt4 = 0;
    }
    else if (keysign4 == 0)
    {
        keyt4++;
        if (keyt4 >= KEY_TIME) // 按键去抖
        {
            keyt4 = 0;
            keysign4 = 1; // 清除标志以防再次进入
            Keysign = 4;
        }
    }
}
