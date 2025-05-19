#pragma once

#include <car_config.h>
#include <DCMotor.hpp>
#include <stdint.h>
#include <Arduino.h>

class Car {
  private:
    DCMotor _leftMotor, _rightMotor;
    uint16_t _speed;
  
  public:
    Car(const car_config_t& config)
      : _leftMotor(config.left_pin1, config.left_pin2), _rightMotor(config.right_pin1, config.right_pin2), _speed(4095) {}
    
    void forward() {
      _leftMotor.forward();
      _rightMotor.forward();
    }

    void backward() {
      _leftMotor.backward();
      _rightMotor.backward();
    }

    void left() {
      _leftMotor.stop();
      _rightMotor.forward();
    }

    void right() {
      _leftMotor.forward();
      _rightMotor.stop();
    }

    void stop() {
      _leftMotor.stop();
      _rightMotor.stop();
    }
};