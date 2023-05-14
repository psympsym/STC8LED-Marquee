/* ---------------------------------- 包含头文件 --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

/* ----------------------------------- 函数 ----------------------------------- */

/* 第一区 初始化单片机 */
/**
 * 功能：初始化单片机
 * 参数：None
 * 返回：None
 * 说明：
 */
void System_Init()
{
    // 将P0引脚配置为高电平输出模式
    GPIO_Init(GPIO_P0, Pin_All, GPIO_MODE_WEAK_PULL);

    // 将P1所有引脚配置为推挽输出模式
    GPIO_Init(GPIO_P1, Pin_All, GPIO_MODE_OUT_PP);

    // 将P2所有引脚配置为推挽输出模式
    GPIO_Init(GPIO_P2, Pin_All, GPIO_MODE_OUT_PP);

    // 将P5引脚配置为浮空输入模式
    GPIO_Init(GPIO_P5, Pin_Low, GPIO_MODE_IN_FLOATING);

    led_dr1 = 1; // LED灭
    led_dr2 = 1; // LED灭
    led_dr3 = 1; // LED灭
    led_dr4 = 1; // LED灭
}

/* 第二区 初始化外围 */
/**
 *
 * 功能：初始化外围设备
 * 参数：None
 * 返回：None
 * 说明：
 */
void Peripheral_Init() // 初始化外围
{
    AUXR &= 0x7F; // 定时器时钟12T模式
    EA = 1; // 开总中断
}
