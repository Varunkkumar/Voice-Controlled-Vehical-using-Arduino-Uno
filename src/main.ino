#define TRIG_PIN 7  // Ultrasonic sensor trigger pin
#define ECHO_PIN 8  // Ultrasonic sensor echo pin

String voice = "";  // Stores voice commands

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  for (int i = 3; i <= 6; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  while (Serial.available() > 0) {
    delay(10);
    char c = Serial.read();
    if (c == '#') {
      break;
    }
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);

    if (voice.equals("forward")) {
      if (detectObstacle() > 20) {  // Move only if no obstacle within 20 cm
        moveRobot(LOW, HIGH, LOW, HIGH);
      } else {
        stopRobot();
      }
    } else if (voice.equals("back")) {
      moveRobot(HIGH, LOW, HIGH, LOW);
    } else if (voice.equals("right")) {
      moveRobot(LOW, HIGH, HIGH, LOW);
    } else if (voice.equals("left")) {
      moveRobot(HIGH, LOW, LOW, HIGH);
    } else {
      stopRobot();
    }

    voice = "";  // Reset command
  }
}

// Function to move the robot
void moveRobot(int m1, int m2, int m3, int m4) {
  digitalWrite(3, m1);
  digitalWrite(4, m2);
  digitalWrite(5, m3);
  digitalWrite(6, m4);
  delay(500);
}

// Function to stop the robot
void stopRobot() {
  moveRobot(LOW, LOW, LOW, LOW);
}

// Function to detect obstacles
float detectObstacle() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration * 0.0343) / 2;  // Convert time to distance (cm)
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
