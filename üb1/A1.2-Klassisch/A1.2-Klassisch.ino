int led = 7;
int button1 = 5;
int button2 = 3;

int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  //Internal Pullup
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  //Prüfe, ob ein Button gedrückt
  if(digitalRead(button1) == LOW || digitalRead(button2) == LOW) {
    //Invertiere ledState
    if(ledState == HIGH ? LOW : HIGH)
    //Warte, dass Button nicht mehr gedrückt
    while(digitalRead(button1) == LOW || digitalRead(button2) == LOW) {
      //Tu nix
    }
  }
}
