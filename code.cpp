char data = 0;

const int btn1 = 4;   // Button 1
const int btn2 = 2;   // Button 2
const int relay1 = 10;  // Lamp Relay
const int relay2 = 8;   // Motor Relay

bool lampState = false;
bool motorState = false;

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  digitalWrite(relay1, LOW);  // Lamp OFF initially
  digitalWrite(relay2, LOW);  // Motor OFF initially

  Serial.begin(9600);     // Serial for Bluetooth (HC-05) 
}

void loop() {
  // Read button 1 to toggle Lamp
  if (digitalRead(btn1) == LOW) {
    delay(200);  // debounce
    lampState = !lampState;
    digitalWrite(relay1, lampState);
    while (digitalRead(btn1) == LOW); // wait for button release
  }

  // Read button 2 to toggle Motor
  if (digitalRead(btn2) == LOW) {
    delay(200); // debounce
    motorState = !motorState;
    digitalWrite(relay2, motorState);
    while (digitalRead(btn2) == LOW); // wait for button release
  }

  // Bluetooth control
  if (Serial.available()>0) {
    data = Serial.read();

    if (data == '1') {
      digitalWrite(relay1, HIGH); // Lamp ON
      lampState = true;
    }
    if (data == '0') {
      digitalWrite(relay1, LOW);  // Lamp OFF
      lampState = false;
    }

    if (data == '2') {
      digitalWrite(relay2, HIGH); // Motor ON
      motorState = true;
    }
    if (data == '3') {
      digitalWrite(relay2, LOW);  // Motor OFF
      motorState = false;
    }
  }
}
