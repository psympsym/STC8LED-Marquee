/* ---------------------------------- 包含头文件 --------------------------------- */
#include "KeyServices.h"

void KeyServices()
{
    switch (Keysign)
    {
    case 1:
        if (TR1 == 1) // 跑马灯开启
        {
            direction_flag = !direction_flag; // 改变LED方向
        }
        else if (TR1 == 0) // 跑马灯关闭，不执行任何操作
        {
            ;
        }
        Keysign = 0; // 标志置0
        break;
    case 2:
        if (TR1 == 1) // 跑马灯开启
        {
            if (LEDChangeTime >= 40) // 如果大于下限速度加快
                LEDChangeTime -= 10;
        }
        else if (TR1 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 3:
        if (TR1 == 1) // 跑马灯开启
        {
            if (LEDChangeTime <= 80) // 如果小于上限速度减慢
                LEDChangeTime += 10;
        }
        else if (TR1 == 0)
        {
            ;
        }
        Keysign = 0;
        break;
    case 4:
        TR1= !TR1; // 开关跑马灯
		P0 = 0xFF; // 关掉跑马灯
        Keysign = 0;
        break;
    default:
        Keysign = 0;
        break;
    }
}