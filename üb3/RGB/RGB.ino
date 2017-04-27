//setRGB(0.0, 1.0, 0.2)

String cmd;
char vgl[] = "setRGB(0.0, 1.1, 2.2)";
int i = 0;
float arg1 = 0, arg2 = 0, arg3 = 0;
bool change = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    cmd = Serial.readString();
    Serial.print(cmd);
    if(cmd.substring(0, 6) == "setRGB") {
      if(cmd.charAt(6) == '(') {
        if((arg1 = cmd.substring(7, 10).toFloat()) <= 1.0 && arg1 >= 0.0
            && (arg2 = cmd.substring(12, 15).toFloat()) <= 1.0 && arg2 >= 0.0
            && (arg3 = cmd.substring(17, 20).toFloat()) <= 1.0 && arg3 >= 0.0) {
          Serial.print("Arg1: ");
          Serial.println(arg1, 1);
          Serial.print("Arg2: ");
          Serial.println(arg2, 1);
          Serial.print("Arg3: ");
          Serial.println(arg3, 1);
          if(cmd.substring(10, 12) == ", " && cmd.substring(15, 17) == ", " && cmd.charAt(20) == ')' && cmd.length() == 22) {   //22, weil \0, bzw newline
            setRGB(arg1, arg2, arg3);
          } else {
            Serial.println("Syntaxfehler, bitte Parametertrennung, -anzahl und -laenge pruefen!");
          }
        } else {
          Serial.print("Fehler bei den Parametern, ");
          if(arg1 > 1.0 || arg2 > 1.0 || arg3 > 1.0) {
            Serial.println("maximaler Wert ist 1.0!");
          } else if(arg1 > 1.0 || arg2 > 1.0 || arg3 > 1.0) {
            Serial.println("minimaler Wert ist 0.0!");
          }
        }
      } else {
        Serial.println("Oeffnende Klammer vergessen!");
      }
    } else {
      Serial.println("Der Funktionsname muss setRGB sein!");
    }
  }

  
}

void setRGB(float RED_val, float GREEN_val, float BLUE_val) {
  Serial.println("EINGABE AKZEPTIERT!");
}

