#include "Joystick.h"
#include "Arduino.h"

Joystick::Joystick(int RxPin, int RyPin, int BtnPin)
{
    _RxPin = RxPin;
    _RyPin = RyPin;
    _BtnPin = BtnPin;
    _neutralRead = 512; //default, variable
    pinMode(_RxPin, INPUT);
    pinMode(_RyPin, INPUT);
    pinMode(_BtnPin, INPUT);
}

Joystick::Joystick(int RxPin, int RyPin, int BtnPin, int neutralRead)
{
    _RxPin = RxPin;
    _RyPin = RyPin;
    _BtnPin = BtnPin;
    _neutralRead = neutralRead;
    pinMode(_RxPin, INPUT);
    pinMode(_RyPin, INPUT);
    pinMode(_BtnPin, INPUT);
}

Joystick::jData Joystick::ReadVals()
{
    jData vals;
    vals.xVal = normalizeVal(analogRead(_RxPin));
    vals.yVal = normalizeVal(analogRead(_RyPin));
    vals.btnPressed = digitalRead(_BtnPin);
    if(flipY)
    {
        vals.yVal *= -1;
    }
    return vals;
}

float Joystick::normalizeVal(float value)
{
    int topBound = 1023 - _neutralRead;
    if(value == _neutralRead)
    {
        return 0.0;
    }
    if(value > _neutralRead)
    {
        return (value - _neutralRead) / topBound;
    }
    else
    {
        return (value - _neutralRead) / _neutralRead;
    }
}
