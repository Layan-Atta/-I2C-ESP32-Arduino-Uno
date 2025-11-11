#include <Wire.h>

#define SLAVE_ADDRESS 0x08 // نفس العنوان الذي حددناه للأردوينو
#define SDA_PIN 21         // منفذ SDA في ESP32
#define SCL_PIN 22         // منفذ SCL في ESP32

void setup() {
  // بدء الاتصال كـ "رئيسي" (Master)
  // (نحدد المنافذ المستخدمة في ESP32)
  Wire.begin(SDA_PIN, SCL_PIN); 
  
  Serial.begin(115200); // بدء الاتصال التسلسلي لمشاهدة المخرجات (اختياري)
}

void loop() {
  // إرسال الأمر '1' لتشغيل הـ LED
  Wire.beginTransmission(SLAVE_ADDRESS); // بدء الإرسال إلى الأردوينو
  Wire.write('1');                       // إرسال حرف '1'
  Wire.endTransmission();                // إنهاء الإرسال
  Serial.println("Sent command: 1 (LED ON)");
  
  delay(2000); // الانتظار ثانيتين

  // إرسال الأمر '0' لإطفاء הـ LED
  Wire.beginTransmission(SLAVE_ADDRESS); // بدء الإرسال
  Wire.write('0');                       // إرسال حرف '0'
  Wire.endTransmission();                // إنهاء الإرسال
  Serial.println("Sent command: 0 (LED OFF)");

  delay(2000); // الانتظار ثانيتين
}