#include "actuator.h"
#include "main.h"
#include "distance.h"

extern motor motor[4];
float velocity = 10;

int32_t time = HAL_GetTick();
void play(void)
{
    if ((HAL_GetTick() - time) >= SAMPLE_TIME)
    {
        time = HAL_GetTick();
        //motor[0].set_omega(-5);
        //motor[1].set_omega(5);
        //motor[2].set_omega(-5);
        //motor[3].set_omega(5);

        calculate1_data();
        calculate2_data();
        calculate3_data();

        float vx = getfinaldata_vx();
        float vy = getfinaldata_vy();
        float vw = getfinaldata_vw() * 57.3 * 3.3;

        printf("Vx: %0.4f, Vy: %0.4f, Vw: %0.4f\n", vx, vy, vw);
    }
}
