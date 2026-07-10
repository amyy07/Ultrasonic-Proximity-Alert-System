#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create LCD object (change 0x27 to 0x3F if necessary)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig = 6;      // Trigger pin
const int echo = 7;      // Echo pin
const int buzzer = 8;    // Buzzer pin

long totaltime;
long distance;

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  // LCD setup
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic");
  lcd.setCursor(0, 1);
  lcd.print("Distance Meter");
  delay(2000);

  lcd.clear();
}

void loop() {

  // Trigger ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure distance
  totaltime = pulseIn(echo, HIGH);
  distance = totaltime * 0.034 / 2;

  // Print to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Update LCD
  // First line: Distance
lcd.setCursor(0, 0);
lcd.print("Distance:");
lcd.print("     ");        // Clear old text
lcd.setCursor(9, 0);
lcd.print(distance);
lcd.print("cm");

// Second line: Warnings
lcd.setCursor(0, 1);

if (distance > 100) {
  lcd.print("Status: SAFE   ");
}
else if (distance > 50) {
  lcd.print("Status: WARNING   ");
}
else if (distance > 20) {
  lcd.print("Status: CLOSE!  ");
}
else if (distance > 0) {
  lcd.print("Status: STOP!  ");
}
else {
  lcd.print("No Reading     ");
}

  // Buzzer logic
  if (distance <= 100 && distance > 0) {

    // Faster beeps as object gets closer
    int interval = map(distance, 5, 100, 50, 1000);
    interval = constrain(interval, 50, 1000);

    // Higher pitch as object gets closer
    int pitch = map(distance, 100, 5, 500, 2500);
    pitch = constrain(pitch, 500, 2500);

    tone(buzzer, pitch);
    delay(50);
    noTone(buzzer);
    delay(interval);

  } else {

    noTone(buzzer);
    delay(200);
  }
}