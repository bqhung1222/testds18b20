#include <OneWire.h>
#include <DallasTemperature.h>

// Pin nối với chân DQ của DS18B20
#define ONE_WIRE_BUS 27

// Thiết lập giao tiếp OneWire với Arduino
OneWire oneWire(ONE_WIRE_BUS);

// Thiết lập đối tượng cảm biến nhiệt độ
DallasTemperature sensors(&oneWire);

void setup() {
  // Bắt đầu giao tiếp nối tiếp
  Serial.begin(115200);
  // Bắt đầu cảm biến nhiệt độ
  sensors.begin();
}

void loop() {
  // Yêu cầu cảm biến đọc nhiệt độ
  sensors.requestTemperatures();
  // Đọc nhiệt độ từ cảm biến
  float temperatureC = sensors.getTempCByIndex(0);
  
  // Kiểm tra nếu không đọc được dữ liệu
  if (temperatureC == DEVICE_DISCONNECTED_C) {
    Serial.println("Could not read temperature data");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" °C");
  }
  

  delay(1000);
}
