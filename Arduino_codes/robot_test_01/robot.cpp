#include "robot.h"

Robot::Robot(unsigned int lft, unsigned int rit) {
  lft_pin = lft;
  rit_pin = rit;
}

void Robot::setup() {
  motor_lft.initDCMotor(lft_pin);
  motor_rit.initDCMotor(rit_pin);

  motor_lft.setSpeed(lft_sp);
  motor_rit.setSpeed(rit_sp);

  Stop(); // Stationary Mode
}

void Robot::Forward() {
  motor_lft.run(FORWARD);
  motor_rit.run(FORWARD);
}

void Robot::Backward() {
  motor_lft.run(BACKWARD);
  motor_rit.run(BACKWARD);
}

void Robot::Right() {
  motor_lft.run(FORWARD);
  motor_rit.run(RELEASE);
}
///
void Robot::EnhancedRight(){
  motor_lft.run(FORWARD);
  motor_rit.run(BACKWARD);
}

void Robot::EnhancedLeft(){
      motor_lft.run(BACKWARD);
      motor_rit.run(FORWARD);
}

///
void Robot::Left() {
  motor_lft.run(RELEASE);
  motor_rit.run(FORWARD);
}

void Robot::Stop() {
  motor_lft.run(RELEASE);
  motor_rit.run(RELEASE);
}

