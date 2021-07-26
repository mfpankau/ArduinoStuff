#ifndef Joystick_h
#define Joystick_h
#include "Arduino.h"

class Joystick
{
    public:
        struct jVals{
            float xVal;
            float yVal;
        };
        Joystick(int RxPin, int RyPin);
        Joystick(int RxPin, int RyPin, int neutralRead);
        jVals ReadVals();
        bool flipY = false;
    private:
        int _RxPin;
        int _RyPin;
        int _neutralRead;
        float normalizeVal(float value);
};

#endif
