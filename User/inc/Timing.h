#ifndef _Timing_h_
#define _Timing_h_

/* ---------------------------------- 包含头文件 --------------------------------- */
#include "LEDChange.h"
#include "NixieTube.h"
#include "KeyScan.h"

void Time0_Config(); 			//定时器0初始化配置
void Time1_Config();			//定时器1初始化配置 
void Delay_ms(uint16_t nms);		//延时函数

#endif