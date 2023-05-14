/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

/* ---------------------------------- ˽�к궨�� --------------------------------- */
#define KEY_TIME 20

/* ---------------------------------- ��չ���� ---------------------------------- */
uint8 Keysign = 0; // ������־

/* ---------------------------------- ˽�б��� ---------------------------------- */
uint8 keysign1 = 0; // ����״̬��ʼ��
uint8 keysign2 = 0;
uint8 keysign3 = 0;
uint8 keysign4 = 0;

uint8 keyt1 = 0; // ����ȥ����ʱ
uint8 keyt2 = 0;
uint8 keyt3 = 0;
uint8 keyt4 = 0;

/* ----------------------------------- ���� ----------------------------------- */
/**
 * @brief ����ɨ��
 * @param none
 * @note �ı�Keysign��ֵ
*/
void KeyScan()
{
    if (key_sr1 == 1) // k1û������
    {
        keysign1 = 0; // ����1��־
        keyt1 = 0;
    }
    else if (keysign1 == 0) // k1�������ұ�־Ϊ0
    {
        keyt1++;
        if (keyt1 >= KEY_TIME) // ����ȥ��
        {
            keyt1 = 0;
            keysign1 = 1; // �����־�Է��ٴν���
            Keysign = 1;
        }
    }

    if (key_sr2 == 1) // k2û������
    {
        keysign2 = 0; // ����2��־
        keyt2 = 0;
    }
    else if (keysign2 == 0)
    {
        keyt2++;
        if (keyt2 >= KEY_TIME) // ����ȥ��
        {
            keyt2 = 0;
            keysign2 = 1; // �����־�Է��ٴν���
            Keysign = 2;
        }
    }

    if (key_sr3 == 1) // k3û������
    {
        keysign3 = 0; // ����3��־
        keyt3 = 0;
    }
    else if (keysign3 == 0)
    {
        keyt3++;
        if (keyt3 >= KEY_TIME) // ����ȥ��
        {
            keyt3 = 0;
            keysign3 = 1; // �����־�Է��ٴν���
            Keysign = 3;
        }
    }

    if (key_sr4 == 1) // k4û������
    {
        keysign4 = 0; // ����4��־
        keyt4 = 0;
    }
    else if (keysign4 == 0)
    {
        keyt4++;
        if (keyt4 >= KEY_TIME) // ����ȥ��
        {
            keyt4 = 0;
            keysign4 = 1; // �����־�Է��ٴν���
            Keysign = 4;
        }
    }
}
