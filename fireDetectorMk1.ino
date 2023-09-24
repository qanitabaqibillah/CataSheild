#include <rgb_lcd.h>

#include <math.h>
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif



const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
float temp = 0;
const int button = 2;       // connect a button
const int buzzer = 6;       // connect a buzzer
void setup()
{
    Serial.begin(9600);
    // pinMode(button, INPUT); //set button as an INPUT device
    pinMode(buzzer, OUTPUT);   //set LED as an OUTPUT device

}
void loop()
{
    int btn = digitalRead(button); //read the status of the button
    digitalWrite(buzzer, btn);
    delay(10);

    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet

    if (temperature >= 15.0) {
    //     // Activate the buzzer when the temperature exceeds 30 degrees Celsius
        digitalWrite(buzzer, HIGH);
    } else {
        // Turn off the buzzer if the temperature is below 30 degrees Celsius
        digitalWrite(buzzer, LOW);
    }

    Serial.print("temperature = ");
    Serial.println(temperature);

    delay(100);
}

