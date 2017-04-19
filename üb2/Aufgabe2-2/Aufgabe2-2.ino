#include <DueTimer.h>

int led = 7;
int button1 = 5;
int button2 = 3;
int led_state = LOW;
int lastButtonState = HIGH;
int val = 0;
DueTimer timer;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  /*
   * timer.configure liefert bool zrk, braucht Sprungadresse zu
   * Interruptroutine, setzt intern einen Interrupt bei Ablauf des Counters
   */
  if(timer.configure(1, changeLedState)) {
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
  if(button1 = LOW && lastButtonState == HIGH) {
    val = val + 32;
    lastButtonState = LOW;
  } else if(button2 = LOW && lastButtonState == HIGH) {
    val = val - 32;
    lastButtonState = LOW;
  } else {
    lastButtonState = HIGH;
  }
}

