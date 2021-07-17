#include <ESP32Servo.h>
void empty(){

}
class ServoLock{
    public:
    int servo1_offset=0, servo2_offset=0;
    int servo1_up=120, servo2_up=120;
    int servo1_down=60, servo2_down=60;
    Servo *s1 = new Servo();
    Servo *s2 = new Servo();
    ServoLock(int pin1, int pin2)
    {
        s1->attach(pin1);
        s2->attach(pin2);
    }
    void (*servoUp)() = empty;

    void attachServoUpFeedback(void (*_servoUp)())
    {
        servoUp = _servoUp;
    }
    void lock(){

        s1->write(servo1_up);
        s2->write(servo2_up);
        delay(500);
        servoUp();   
    }
    void unlock(){

        s1->write(servo1_down);
        s2->write(servo2_down);
    }
};