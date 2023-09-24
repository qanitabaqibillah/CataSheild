

const int messagePin = A3;
const int messagePin2 = A1;
const int buzzerPin = 8.;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(messagePin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Read the analog value from the message pin
  int messageValue = analogRead(messagePin);
  int messageValue2 = analogRead(messagePin2);

  // Set a threshold value for triggering the buzzer
  int threshold = 1000; // Adjust this threshold as needed

  if ((messageValue - messageValue2) > threshold) {
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  }

  // Optional: Print the analog value to the serial monitor for debugging
  Serial.print("Analog Value: ");
  Serial.println(messageValue - messageValue2);

  // Add a delay to control the update rate
  delay(100); // Adjust the delay as needed

}
