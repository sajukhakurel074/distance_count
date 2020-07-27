#include "distance.h"
#include "math.h"
#include "actuator.h"
#include "encoder.h"

distance dis;
void distance::calculate1(void)
{
    calculate_data(0);
    calculate_data(1);
    calculate_data(2);
    calculate_data(3);
    w[0][0] = get_data(0) * 1.414;
    w[1][0] = get_data(1) * 1.414;
    w[2][0] = get_data(2) * 1.414;
    w[3][0] = get_data(3) * 1.414;
}
void distance::calculate2(void)
{
    for (int i = 0; i < 3; i++)
    {
        float sum = 0;
        for (int k = 0; k < 4; k++)
        {
            sum = sum + a[i][k] * w[k][0];
            c[i][0] = sum * RADIUS;
        }
    }
}

void distance::calculate3(void)
{
    finaldistance[0][0] = finaldistance[0][0] + ((c[0][0] * SAMPLE_TIME) / 100000.0);
    finaldistance[1][0] = finaldistance[1][0] + ((c[1][0] * SAMPLE_TIME) / 100000.0);
    finaldistance[2][0] = finaldistance[2][0] + ((c[2][0] * SAMPLE_TIME) / 100000.0);
    //printf("time= %ld", time);
    //printf("\n finaldistance= %f", finaldistance[i][0]);
}
void calculate1_data(void)
{
    dis.calculate1();
}
void calculate2_data(void)
{
    dis.calculate2();
}
void calculate3_data(void)
{
    dis.calculate3();
}
float getfinaldata_vx(void)
{
    return dis.get_vx();
}
float getfinaldata_vy(void)
{
    return dis.get_vy();
}
float getfinaldata_vw(void)
{
    return dis.get_vw();
}
