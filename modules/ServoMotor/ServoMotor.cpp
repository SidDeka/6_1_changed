#include "mbed.h"
#include "arm_book_lib.h"
#include "ServoMotor.h"
#include "code.h"
#include "matrix_keypad.h"


#define DUTY_MIN 0.025 // 0 degree at start min
#define DUTY_MAX 0.075 //90 degree rotation max. 
#define PERIOD 0.02
#define TIME_INCREMENT_MS 5000 // 5 second delay




PwmOut servo(PF_9);


void servo_init()
{
    servo.period(PERIOD); // 20ms period
    servo.write(DUTY_MIN);
}


void servo_update(char arr[])
{
    if(new_code_correct(arr) == true)
    {
    servo.write(DUTY_MAX);
    delay(TIME_INCREMENT_MS);
    servo.write(DUTY_MIN);
    }      

}
