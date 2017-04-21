#include <DueTimer.h>

int led = 7;
int button1 = 5;
int button2 = 3;
int led_state = LOW;
int lastButtonState = HIGH;
int val = 0;
int minimum = 0;
int maximum = 256;
int step = (maximum-minimum)/8;   //8 Schritte
int counter1 = 0;
int counter2 = 0;
DueTimer timer;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  /*
   * timer.configure liefert bool zrk, braucht Sprungadresse zu
   * Interruptroutine, setzt intern einen Interrupt bei Ablauf des Counters
   */
  if(timer.configure(1000, changeLedState)) {
    timer.start();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, val);
}

void changeLedState() {
  //Interrupt wird sowieso ausgelöst, schau, ob auch Knopf gedrückt ist
  //lastButtonState verhindert wiederholtes interrupten
  if(digitalRead(button1) == LOW && lastButtonState == HIGH) {
    lastButtonState = LOW;
    counter1++;
  } else if(digitalRead(button1) == LOW && lastButtonState == LOW) {
    counter1++;
      if(counter1 == 10) {
          val = val + step;
        if(val >= maximum-1) {
          val = minimum;
        }
    }
  } else if(digitalRead(button2) == LOW && lastButtonState == HIGH) {
    lastButtonState = LOW;
    counter2++;
  } else if(digitalRead(button2) == LOW && lastButtonState == LOW) {
    counter2++;
    if(counter2 == 10) {
        val = val - step;
        if(val <= minimum) {
          val = maximum-1;
        } else if(val <= step-1) {
          val = 0;
        }
    }
  } else if(digitalRead(button1) == HIGH && digitalRead(button2) == HIGH){
    lastButtonState = HIGH;
    counter1 = 0;
    counter2 = 0;
  }
}

