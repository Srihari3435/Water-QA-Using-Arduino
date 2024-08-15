#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

namespace pin {
  const byte tds_sensor = A1;
  const byte one_wire_bus = 7; // Dallas Temperature Sensor
}

namespace device {
  float aref = 4.3;
}

namespace sensor {
  float ec = 0;
  unsigned int tds = 0;
  float waterTemp = 0;
  float ecCalibration = 1;
}

OneWire oneWire(pin::one_wire_bus);
DallasTemperature  sensors(&oneWire);

void setup() {
  Serial.begin(9600); // Dubugging on hardware Serial 0
  delay(100);
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.display();
  sensors.begin();
}

void loop() {
  readTdsQuick();
  delay(1000);
}

void readTdsQuick() {
sensors.requestTemperatures();
  sensor::waterTemp = sensors.getTempCByIndex(0);
  float rawEc = analogRead(pin::tds_sensor) * device::aref / 1024.0; // read the analog value and convert to voltage
  float temperatureCoefficient = 1.0 + 0.02 * (sensor::waterTemp - 25.0); // temperature compensation formula
  sensor::ec = (rawEc / temperatureCoefficient) * sensor::ecCalibration; // temperature and calibration compensation
  // Corrected TDS calculation based on EC value
  sensor::tds = (sensor::ec * 1000) / 2; // Simple conversion from EC to TDS, adjusted the coefficient based on our sensor characteristics
  Serial.print(F("TDS:")); Serial.println(sensor::tds);
  Serial.print(F("EC:")); Serial.println(sensor::ec, 2);
  Serial.print(F("Temperature:")); Serial.println(sensor::waterTemp, 2);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("TDS   EC     Temp");
  display.setCursor(0, 10);
  display.print(sensor::tds);
  display.setCursor(35, 10);
  display.print(sensor::ec, 2);
  display.setCursor(70, 10);
  display.print(sensor::waterTemp, 2);
  display.display();
  
 
}