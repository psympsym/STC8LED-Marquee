/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

/* ----------------------------------- ���� ----------------------------------- */

/* ��һ�� ��ʼ����Ƭ�� */
/**
 * ���ܣ���ʼ����Ƭ��
 * ������None
 * ���أ�None
 * ˵����
 */
void System_Init()
{
    // ��P0��������Ϊ�ߵ�ƽ���ģʽ
    GPIO_Init(GPIO_P0, Pin_All, GPIO_MODE_WEAK_PULL);

    // ��P1������������Ϊ�������ģʽ
    GPIO_Init(GPIO_P1, Pin_All, GPIO_MODE_OUT_PP);

    // ��P2������������Ϊ�������ģʽ
    GPIO_Init(GPIO_P2, Pin_All, GPIO_MODE_OUT_PP);

    // ��P5��������Ϊ��������ģʽ
    GPIO_Init(GPIO_P5, Pin_Low, GPIO_MODE_IN_FLOATING);

    led_dr1 = 1; // LED��
    led_dr2 = 1; // LED��
    led_dr3 = 1; // LED��
    led_dr4 = 1; // LED��
}

/* �ڶ��� ��ʼ����Χ */
/**
 *
 * ���ܣ���ʼ����Χ�豸
 * ������None
 * ���أ�None
 * ˵����
 */
void Peripheral_Init() // ��ʼ����Χ
{
    AUXR &= 0x7F; // ��ʱ��ʱ��12Tģʽ
    EA = 1; // �����ж�
}
