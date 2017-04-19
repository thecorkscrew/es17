int led = 7;
int button1 = 5;
int button2 = 3;

int ledState = LOW;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  //Prüfe, ob ein Button gedrückt
  if(digitalRead(button1) == LOW || digitalRead(button2) == LOW) {
Serial.println("asd");
    //Invertiere ledState
    ledState = !ledState;
    //Schreibe ledState
    digitalWrite(led, ledState);
    //Warte, dass Button nicht mehr gedrückt
    while(digitalRead(button1) == LOW || digitalRead(button2) == LOW) {
      //Tu nix
    }
  }
}
