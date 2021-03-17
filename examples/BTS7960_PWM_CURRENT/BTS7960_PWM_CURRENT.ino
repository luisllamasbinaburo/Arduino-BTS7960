/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

// PINOUT
 
#include "BTS7960.h"

const uint8_t EN_L = 33;
const uint8_t EN_R = 25;
const uint8_t L_PWM = 26;
const uint8_t R_PWM = 15;
const uint8_t R_IS = 34;
const uint8_t L_IS = 35;

BTS7960 motorController(EN_L, EN_R, L_PWM, R_PWM, L_IS, R_IS);

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  motorController.Enable();

  for(int speed = 0 ; speed < 255; speed+=10)
  {
    Serial.println(motorController.CurrentSenseLeft());
	motorController.TurnLeft(speed);
  Serial.println(motorController.CurrentSenseLeft());
	delay(100);
  
  }  

  delay(1000);

  motorController.Stop();
  
  for(int speed = 255 ; speed > 0; speed-=10)
  {
    Serial.println(motorController.CurrentSenseLeft());
	motorController.TurnLeft(speed);
  Serial.println(motorController.CurrentSenseLeft());
	delay(100);
  }  
  motorController.Stop();

  motorController.Disable();
  
  delay(1000);
}
