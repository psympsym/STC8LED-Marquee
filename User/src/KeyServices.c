/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "KeyServices.h"

void KeyServices()
{
    switch (Keysign)
    {
    case 1:
        if (TR1 == 1) // ����ƿ���
        {
            direction_flag = !direction_flag; // �ı�LED����
        }
        else if (TR1 == 0) // ����ƹرգ���ִ���κβ���
        {
            ;
        }
        Keysign = 0; // ��־��0
        break;
    case 2:
        if (TR1 == 1) // ����ƿ���
        {
            if (LEDChangeTime >= 40) // ������������ٶȼӿ�
                LEDChangeTime -= 10;
        }
        else if (TR1 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 3:
        if (TR1 == 1) // ����ƿ���
        {
            if (LEDChangeTime <= 80) // ���С�������ٶȼ���
                LEDChangeTime += 10;
        }
        else if (TR1 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 4:
        TR1= !TR1; // ���������
		P0 = 0xFF; // �ص������
        Keysign = 0;
        break;
    default:
        Keysign = 0;
        break;
    }
}