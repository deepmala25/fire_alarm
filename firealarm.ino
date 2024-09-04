// Define pins
const int tempPin = A1;      // Pin for LM35 temperature sensor
const int gasPin = A0;       // Pin for gas sensor
const int piezo = 7;         // Pin for piezo buzzer

void setup() {
  // Initialize pins
  pinMode(tempPin, INPUT);
  pinMode(gasPin, INPUT);
  pinMode(piezo, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read temperature sensor
  int tempReading = analogRead(tempPin);
  float vout1 = (tempReading / 1023.0) * 5.0;  // Convert reading to voltage
  float temp = (vout1 - 0.5) * 100.0;          // Convert voltage to temperature in °C

  // Read gas sensor
  int gassensor = analogRead(gasPin);

  // Control buzzer based on gas sensor reading
  if (gassensor >= 100) {
    digitalWrite(piezo, HIGH); // Activate buzzer
  } else {
    digitalWrite(piezo, LOW);  // Deactivate buzzer
  }

  // Print sensor readings to Serial Monitor
  Serial.print("Temperature (°C): ");
  Serial.print(temp);
  Serial.print("\t");

  Serial.print("Gas Sensor Reading: ");
  Serial.println(gassensor);

  // Wait for a short period before the next reading
  delay(1000);
}
