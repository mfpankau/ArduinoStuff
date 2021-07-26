#ifndef Joystick_h
#define Joystick_h
#include "Arduino.h"

class Joystick
{
    public:
        struct jData{
            float xVal;
            float yVal;
            bool btnPressed;
        };
        Joystick(int RxPin, int RyPin, int BtnPin);
        Joystick(int RxPin, int RyPin, int BtnPin, int neutralRead);
        jData ReadVals();
        bool flipY = false;
    private:
        int _RxPin;
        int _RyPin;
        int _BtnPin;
        int _neutralRead;
        float normalizeVal(float value);
};

#endif
