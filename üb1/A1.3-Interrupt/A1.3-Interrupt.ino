/**
 * Nachteil bei 1.2: wenn gerade eine Routine ausgeführt wird wird der Tastendruck ignoriert
 */

int led = 7;
int button1 = 5;
int button2 = 3;

int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button1), switchLedState, FALLING);
  pinMode(button2, INPUT);
  attachInterrupt(digitalPinToInterrupt(button2), switchLedState, FALLING);
}

void loop() {
  digitalWrite(led, ledState);
}

void switchLedState() {
  ledState = !ledState;
}

