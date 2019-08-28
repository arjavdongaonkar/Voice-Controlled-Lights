#include "robot.h"
#include <NewPing.h>
#include <Servo.h>
#include "SerialExtractor.h"

SerialExtractor ser;


const unsigned int TRIGGER_PIN = A0;
const unsigned int ECHO_PIN = A1;
const unsigned int MAX_DISTANCE = 200;
const int PING_CMD = -1;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const unsigned int SERVO_PIN = 10;
unsigned int angle = 90;
Servo servo;

Robot robot(3, 4);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ser.SetCallBack(onCommandRecieved);
  ser.SetDelimeter(":");
  ser.SetEndIndicator('#');

  while (!Serial.available()) {}
  while (! (Serial.read() != '#') ) {}

  robot.setup();
  servo.attach(SERVO_PIN);
  servo.write(angle);


}

void loop() {
  ser.Run();
}


void onCommandRecieved(int a[], int sz)
{
  auto runPlatform = [] (int choice)->void{
    switch (choice) {
      case 1:
        robot.Forward();
        break;
      case 2:
        robot.Backward();
        break;
      case 3:
        robot.Left();
        break;
      case 4:
        robot.Right();
        break;
      case 5:
        robot.Stop();
        break;
      default:
        break;
    }
  };
  if (a[0] == PING_CMD) {
    Serial.println(sonar.ping_cm());
  } else {
    runPlatform(a[0]);
    if (a[1] != -1)  servo.write(a[1]);
  }
}

