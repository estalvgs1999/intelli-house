// Intelli-House
// by David Alvarado & Erick Cordero
#include <distanceSensor.h>
#include <photosensor.h>
#include <pt.h>
#include <motionSensor.h>
//#include <temperatureSensor.h>

struct pt thread1;
struct pt thread2;
struct pt thread3;
struct pt thread4;

Photosensor photosensor(A0,5);
DistanceSensor distance(6,7,10);
MotionSensor motion(8,9);
//Temperature tmp(12,13);

void setup() {
  PT_INIT(&thread1);
  PT_INIT(&thread2);
  PT_INIT(&thread3);
  PT_INIT(&thread4);
}

void loop() {
  // put your main code here, to run repeatedly:
  photosensor.run(&thread1);
  distance.run(&thread2);
  motion.run(&thread3);
  //tmp.run(&thread4);
}
