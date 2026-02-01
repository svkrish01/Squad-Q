/*
Devs: SquadQ
Objective: code to actuate motors
*/

#include <Arduino_RouterBridge.h>
#include <Arduino_LED_Matrix.h>
#include "animation.h"
Arduino_LED_Matrix matrix;


int enable_right = 5;
int enable_left = 10;

int m_l_1 = 9;
int m_l_2 = 8;
int m_r_3 = 7;
int m_r_4 = 6;

void left_control(int speed, int direction) {
  switch(direction) {
    case -1:
      digitalWrite(m_l_1, LOW);
      digitalWrite(m_l_2, HIGH);
      analogWrite(enable_left, speed);
      break;
    case 0:
      digitalWrite(m_l_1, LOW);
      digitalWrite(m_l_2, LOW);
      analogWrite(enable_left, 0);
      break;
    case 1:
      digitalWrite(m_l_1, HIGH);
      digitalWrite(m_l_2, LOW);
      analogWrite(enable_left, speed);  
      break;
    default:
      Monitor.print("Recieved unknown direction: ");
      Monitor.println(direction);
      break;
  }
};

void right_control(int speed, int direction) {
  switch(direction) {
    case -1:
      digitalWrite(m_r_3, LOW);
      digitalWrite(m_r_4, HIGH);
      analogWrite(enable_right, speed);
      break;
    case 0:
      digitalWrite(m_r_3, LOW);
      digitalWrite(m_r_4, LOW);
      analogWrite(enable_right, 0);
      break;
    case 1:
      digitalWrite(m_r_3, HIGH);
      digitalWrite(m_r_4, LOW);
      analogWrite(enable_right, speed);
      break;
    default:
      Monitor.print("Recieved unknown direction: ");
      Monitor.println(direction);
      break;
  }
};

void right_animation(){
  matrix.loadSequence(Right);
  matrix.playSequence();
  delay(1000);
  matrix.loadFrame(Static);
}

void left_animation(){
  matrix.loadSequence(Left);
  matrix.playSequence();
  delay(1000);
  matrix.loadFrame(Static);
}

void front_animation(){
  matrix.loadSequence(Front);
  matrix.playSequence();
  delay(1000);
  matrix.loadFrame(Static);
}

void back_animation(){
  matrix.loadSequence(Back);
  matrix.playSequence();
  delay(1000);
  matrix.loadFrame(Static);
}

void control_motors(int command, int speed) {
  switch(command) {
    // stop
    case 0:
      left_control(speed, 0);
      right_control(speed, 0);
      break;
    // forward
    case 1:
      left_control(speed, 1);
      right_control(speed, 1);
      front_animation();
      break;
    // backward
    case 2:
      left_control(speed, -1);
      right_control(speed, -1);
      back_animation();
      break;
    // left
    case 3:
      left_control(speed, 1);
      right_control(0, 0);
      left_animation();
      break;
    // right
    case 4:
      left_control(0, 0);
      right_control(speed, 1);
      right_animation();
      break;
    default:
      Monitor.print("Recieved unknown command: ");
      Monitor.println(command);
      break;
  }
};


void setup() {
  pinMode(m_l_1, OUTPUT);
  pinMode(m_l_2, OUTPUT);
  pinMode(m_r_3, OUTPUT);
  pinMode(m_r_4, OUTPUT);

  matrix.begin();
  matrix.clear();
  matrix.loadFrame(Static);
  
  Bridge.begin();
  Bridge.provide("control_motors", control_motors);
}

void loop() {}


