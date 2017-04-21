#include <DueTimer.h>

int led = 7;
int button1 = 5;
int button2 = 3;
int led_state = LOW;
int lastButtonState = HIGH;
int counter = 0;
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
  digitalWrite(led, led_state);
}

void changeLedState() {
  //Interrupt wird sowieso ausgelöst, schau, ob auch Knopf gedrückt ist
  //lastButtonState verhindert wiederholtes interrupten
  if(digitalRead(button1) == LOW && lastButtonState == HIGH) {
    lastButtonState = LOW;
    counter++;
  } else if(digitalRead(button1) == LOW) {
    counter++;
    if(counter == 15) {
      led_state = !led_state;
    }
  } else if(digitalRead(button1) == HIGH){
    lastButtonState = HIGH;
    counter = 0;
  }
}
