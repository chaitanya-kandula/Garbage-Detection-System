# 🗑️ Smart Garbage Detection System using Arduino

This project demonstrates a basic **smart bin** that detects garbage levels using an **ultrasonic sensor**. When the bin is nearly full, it turns on an LED (or buzzer) and prints the level on the Serial Monitor. Useful for IoT-based waste management or automation in public places.

---

## 📌 Features

- Detects if garbage has reached a specific height (e.g., < 10 cm from the sensor)
- Turns on an LED (or buzzer) when the bin is full
- Displays real-time distance readings on the Serial Monitor
- Built with minimal components and easy to simulate on ThinkerCAD

---

## 🧰 Components Used

- Arduino UNO
- Ultrasonic Sensor (HC-SR04 or single-pin simulated version)
- 1 × LED (or buzzer)
- Resistor (220Ω for LED)
- Breadboard
- Jumper Wires
- (Optional) LCD display for visual distance output

---

## 🧾 Arduino Code

```cpp
#define sensorPin 9
#define ledPin 6  // Use a buzzer instead of LED if needed

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration;
  float distance;

  // Trigger ultrasonic pulse
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);

  // Switch to input to read echo
  pinMode(sensorPin, INPUT);
  duration = pulseIn(sensorPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Garbage Level: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    digitalWrite(ledPin, HIGH);  // Bin is full
  } else {
    digitalWrite(ledPin, LOW);   // Bin not full
  }

  delay(1000);
}

📂 Folder Structure
garbage-detection/
├── garbage_detection.ino  # Arduino source code
├── screenshot.png         # Circuit image (optional)
└── README.md              # This documentation file

👨‍💻 Author
Chaitanya Kandula
🔗 GitHub: https://github.com/chaitanya-kandula
🔗 LinkedIn: https://www.linkedin.com/in/chaitanya-kandula1201
📧 Email: chaitanyakandula2005@gmail.com

🧠 Built With
Arduino IDE
ThinkerCAD Circuits
GitHub
