#ifndef _Init_h_
#define _Init_h_

/* ---------------------------------- 包含头文件 --------------------------------- */
#include "STC8Ax_REG.h"
#include "Definition.h"

/* 私有类型定义 */
sbit led_dr1 = P0 ^ 4;		/*!< LED1 引脚定义 */
sbit led_dr2 = P0 ^ 5;		/*!< LED2 引脚定义 */
sbit led_dr3 = P0 ^ 6;		/*!< LED3 引脚定义 */
sbit led_dr4 = P0 ^ 7;		/*!< LED4 引脚定义 */

void System_Init();
void Peripheral_Init();


#endif
