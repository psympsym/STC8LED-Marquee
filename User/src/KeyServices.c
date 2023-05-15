/* ---------------------------------- 包含头文件 --------------------------------- */
#include "..\inc\STC8Ax_REG.h"
#include "..\inc\Definition.h"

#include "..\inc\KeyScan.h"
#include "..\inc\LEDChange.h"
#include "..\inc\NixieTube.h"

/* 私有变量 */

void KeyServices()
{
    switch (Keysign)
    {
    case 1:
        if (TR0 == 1) // 跑马灯开启
        {
            direction_flag = !direction_flag; // 改变LED方向
        }
        else if (TR0 == 0) // 跑马灯关闭，不执行任何操作
        {
            ;
        }
        Keysign = 0; // 标志置0
        break;
    case 2:
        if (TR0 == 1) // 跑马灯开启
        {
            if (LEDChangeTime >= 40) // 如果大于下限速度加快
                LEDChangeTime -= 10;
        }
        else if (TR0 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 3:
        if (TR0 == 1) // 跑马灯开启
        {
            if (LEDChangeTime <= 80) // 如果小于上限速度减慢
                LEDChangeTime += 10;
        }
        else if (TR0 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 4:
        TR0 = !TR0; // 开关跑马灯
		P0 = 0xFF; // 关掉跑马灯
        Keysign = 0;
        break;
    default:
        Keysign = 0;
        break;
    }
}