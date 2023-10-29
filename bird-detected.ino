const int pinBuzzer = 12;       // Pin buzzer dihubungkan ke pin 12 pada Arduino
const int pinMotor = 7;         // Pin motor DC dihubungkan ke pin 7 pada Arduino


void setup() {
  Serial.begin(9600);           // Buka komunikasi serial dengan baud rate 9600
  pinMode(pinMotor, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  digitalWrite(pinMotor, HIGH);

  if (Serial.available() > 0) {
    String received = Serial.readStringUntil('\n');
    if (received.equals("BIRD_DETECTED")) {
      // Bird detected inside the polygon
      buzzer();
      motor();
    } else {
      // Bird not detected inside the polygon
      stopActions();
    }
  }
}

void buzzer() {
  digitalWrite(pinBuzzer, HIGH);    // Buzzer on with delay
  delay(200);                       // Delay 200 milliseconds
  digitalWrite(pinBuzzer, LOW);     // Buzzer off with delay
  delay(200);                       // Delay 200 milliseconds
  digitalWrite(pinBuzzer, HIGH);    // Buzzer on with delay
  delay(200);                       // Delay 200 milliseconds
  digitalWrite(pinBuzzer, LOW);     // Buzzer off with delay
  delay(1000);                      // Wait for a second
}

void motor() {
  digitalWrite(pinMotor, HIGH);     // Turn the Motor on 
  delay(1000);                      // Wait for a second
  digitalWrite(pinMotor, LOW);      // Turn the Motor off
  delay(1000);                      // Wait for a second
}

void stopActions() {
  // Stop the buzzer and motor
  digitalWrite(pinMotor, LOW);
}
