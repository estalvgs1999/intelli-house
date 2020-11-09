//Bibliotecas
#include <Servo.h>
#include <SimpleDHT.h>
#include <pt.h>

// Sensores
#define LDR A0
#define HC_TRIGGER 48
#define HC_ECHO 49
#define PIR 50
#define DHT 53

// Salidas Digitales
#define LED_PATIO 44
#define LED_BANO 45
#define ACDC 46

#define SERVO_GARAGE 5
#define SERVO_PT1 6
#define SERVO_PT2 7

// Hilos
struct pt procesoA;
struct pt procesoB;
struct pt procesoC;
struct pt procesoD;


void setup(){
  PT_INIT(&procesoA);
}


void loop(){
  fotosensor(&procesoA);
}

/**
 * Sensor LDR. 
 * Si el valor de la lectura es menor que el de un valor
 * límite (indica oscuridad) enciende la iluminación. 
 */
void fotosensor(struct pt *pt){
  PT_BEGIN(pt);
  
  static long t = 0;
  int valor;
  const int valorLimite = 200;

  pinMode(LED_PATIO, HIGH);

  while(true){
    digitalWrite(LED_PATIO, LOW);
    
    valor = analogRead(LDR);
    if(valor < valorLimite)
      digitalWrite(LED_PATIO, HIGH);
    
    t = millis();
    PT_WAIT_WHILE(pt,((millis()-t) < 200));

    PT_YIELD(pt);
  }
  PT_END(pt);
}

void sensorDistancia(struct pt *pt){

}

/**
 * Sensor PIR.
 * El sensor genera un señal ALTO si hay movimiento.
 * El led indicador se activa indicando que se ha detectado
 * movimiento.
 */
void sensorMovimiento(struct pt *pt) {
  PT_BEGIN(pt);
  static long  t = 0;
  bool pirState = false;

  pinMode(PIR, INPUT);
  pinMode(LED_BANO, OUTPUT);
  
  while(true){
    pirState = (digitalRead(PIR) == HIGH)? true: false;
    
    if(pirState)
      digitalWrite(LED_BANO, HIGH);
    else
      digitalWrite(LED_BANO, LOW);
    
    t = millis();
    PT_WAIT_WHILE(pt,((millis()-t) < 200));
    
    PT_YIELD(pt);
  }
  PT_END(pt);
}

void sensorTemperatura(struct pt *pt){

}

/***********************/