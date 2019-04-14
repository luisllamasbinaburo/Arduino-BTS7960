# BTS7960Library
Arduino library to control the BTS7960 Dual H-Bridge, that can drive DC-Motor up to 43A

## Usage
Then create an instance of the BTS7960 with four pins constructor
```
BTS7960 motor1(L_EN, R_EN, L_PWM, R_PWM);
```

Or three pins constructor, in case you use the same pin for both left and right enable pins.
```
BTS7960 motor1(EN, L_PWM, R_PWM);
```

## Methods

|Method | Params  | Description
| :----- | :---------- | :------
|**Enable** |   none | Enable the motor driver
|**Disable** |  none | Disable the motor driver (free rotation)
|**Stop** |     none  | Full stop (brake)
|**TurnLeft** | int8_t pwm  | Rotate forward at PWM speed
|**TurnRight** | int8_t pwm  | Rotate backward at PWM speed
