int led = 7;
int button1 = 5;
int button2 = 3;

int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, ledState = HIGH);
  delay(500);
  digitalWrite(led, ledState = LOW);
  delay(2000);
}
