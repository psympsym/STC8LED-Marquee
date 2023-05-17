#ifndef _Init_h_
#define _Init_h_

/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "STC8Ax_REG.h"
#include "Definition.h"

/* ˽�����Ͷ��� */
sbit led_dr1 = P0 ^ 4;		/*!< LED1 ���Ŷ��� */
sbit led_dr2 = P0 ^ 5;		/*!< LED2 ���Ŷ��� */
sbit led_dr3 = P0 ^ 6;		/*!< LED3 ���Ŷ��� */
sbit led_dr4 = P0 ^ 7;		/*!< LED4 ���Ŷ��� */

void System_Init();
void Peripheral_Init();


#endif
