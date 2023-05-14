/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

#include "..\inc\KeyScan.h"
#include "..\inc\LEDChange.h"
#include "..\inc\NixieTube.h"

/* ˽�б��� */

void KeyServices()
{
    switch (Keysign)
    {
    case 1:
        if (TR0 == 1) // ����ƿ���
        {
            direction_flag = !direction_flag; // �ı�LED����
        }
        else if (TR0 == 0) // ����ƹرգ���ִ���κβ���
        {
            ;
        }
        Keysign = 0;
        break;
    case 2:
        if (TR0 == 1)
        {
            if (LEDChangeTime >= 40)
                LEDChangeTime -= 10;
        }
        else if (TR0 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 3:
        if (TR0 == 1)
        {
            if (LEDChangeTime <= 80)
                LEDChangeTime += 10;
        }
        else if (TR0 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 4:
        TR0 = !TR0;
        Keysign = 0;
        break;
    default:
        Keysign = 0;
        break;
    }
}