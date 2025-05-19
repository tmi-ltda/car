#pragma once

#include <car_config.h>
#include "../lib/DCMotor/src/DCMotor.hpp"
#include <stdint.h>
#include <Arduino.h>

class Car {
  private:
    DCMotor _left_motor, _right_motor;
    uint16_t _speed;
  
  public:
    Car(const car_config_t& config)
      : _left_motor(config.left_pin1, config.left_pin2), _right_motor(config.right_pin1, config.right_pin2), _speed(4095) {}
    
    void forward() {
      _left_motor.forward();
      _right_motor.forward();
    }

    void backward() {
      _left_motor.backward();
      _right_motor.backward();
    }

    void left() {
      _left_motor.stop();
      _right_motor.forward();
    }

    void right() {
      _left_motor.forward();
      _right_motor.stop();
    }

    void stop() {
      _left_motor.stop();
      _right_motor.stop();
    }

    void setMaxPower(float power) {
      _left_motor.setMaxPower(power);
      _right_motor.setMaxPower(power);
    }
};