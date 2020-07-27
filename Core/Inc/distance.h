#include "stm32f4xx_hal.h"
#include "tim.h"
#include "stm32f4xx_hal_gpio.h"
//#include "encoder.h"

#define RADIUS (6.8)

class distance
{
public:
    void calculate1(void);
    void calculate2(void);
    void calculate3(void);
    float get_vx()
    {
        return finaldistance[0][0];
    }
    float get_vy()
    {
        return finaldistance[1][0];
    }
    float get_vw()
    {
        return finaldistance[2][0];
    }

private:
    float a[3][4] = {
        /*inverse of coupling matrix*/
        {0.25, 0.25, -0.25, -0.25}, /*  initializers for row indexed by 0 */
        {0.25, -0.25, -0.25, 0.25}, /*  initializers for row indexed by 1 */
        {0.25, 0.25, 0.25, 0.25}    /*  initializers for row indexed by 2 */
    };
    float w[4][1] = {
        {0},
        {0},
        {0},
        {0}};
    float c[3][1] = {
        {0},
        {0},
        {0}};
    float finaldistance[3][1] = {
        {0},
        {0},
        {0}};
};
void calculate1_data(void);
void calculate2_data(void);
void calculate3_data(void);
void calculate4_data(void);
float getfinaldata_vx(void);
float getfinaldata_vy(void);
float getfinaldata_vw(void);