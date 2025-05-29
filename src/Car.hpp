#pragma once

#include <DCMotor.hpp>
#include <stdint.h>
#include <Arduino.h>

typedef struct {
  uint8_t left_pin1, left_pin2, right_pin1, right_pin2;
} car_config_t;

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

    void differentialLeft() {
      _left_motor.halfForward();
      _right_motor.forward();
    }

    void differentialRight() {
      _left_motor.forward();
      _right_motor.halfForward();
    }

    void axialLeft() {
      _left_motor.backward();
      _right_motor.forward();
    }

    void axialRight() {
      _left_motor.forward();
      _right_motor.backward();
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