/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
#include "BTS7960.h"

BTS7960::BTS7960(uint8_t L_EN, uint8_t R_EN, uint8_t L_PWM, uint8_t R_PWM){
	_R_PWM = R_PWM;
	_L_PWM = L_PWM;
	_L_EN = L_EN;
	_R_EN = R_EN;
	pinMode(_R_PWM, OUTPUT);
	pinMode(_L_PWM, OUTPUT);
	pinMode(_L_EN, OUTPUT);
	pinMode(_R_EN, OUTPUT);
}

void BTS7960::TurnRight(uint8_t pwm){
     analogWrite(_L_PWM, 0);
	 delayMicroseconds(100);
     analogWrite(_R_PWM, pwm);
}

void BTS7960::TurnLeft(uint8_t pwm){
     analogWrite(_R_PWM, 0);
	 delayMicroseconds(100);
     analogWrite(_L_PWM, pwm);
}

void BTS7960::Enable(){
	digitalWrite(_L_EN,1);
	if(_R_EN != 0) digitalWrite(_R_EN, HIGH);  
}

void BTS7960::Disable(){
	digitalWrite(_L_EN,0);
	if(_R_EN != 0) digitalWrite(_R_EN, LOW);
}

void BTS7960::Stop(){
  analogWrite(_L_PWM, LOW);
  analogWrite(_R_PWM, HIGH);
}
