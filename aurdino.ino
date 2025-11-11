#include <Wire.h>

#define LED_PIN 13       // المنفذ المتصل به הـ LED
#define SLAVE_ADDRESS 0x08 // العنوان الخاص بالأردوينو (يمكن اختيار أي رقم)

void setup() {
  pinMode(LED_PIN, OUTPUT);   // تعريف منفذ الـ LED كمخرج
  digitalWrite(LED_PIN, LOW); // إطفاء الـ LED في البداية

  // بدء الاتصال كـ "تابع" (Slave) بالعنوان المحدد
  Wire.begin(SLAVE_ADDRESS); 

  // تسجيل الدالة (function) التي سيتم استدعاؤها عند استقبال بيانات
  Wire.onReceive(receiveEvent); 
}

void loop() {
  // لا نحتاج كتابة شيء هنا، لأن العمل يتم عبر الـ "مقاطعة" (interrupt)
  delay(100);
}

// هذه الدالة تُستدعى تلقائياً عند وصول بيانات من الـ Master
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    char command = Wire.read(); // قراءة الأمر المستلم (كحرف)

    // التحقق من الأمر
    if (command == '1') {
      digitalWrite(LED_PIN, HIGH); // تشغيل الـ LED
    } else if (command == '0') {
      digitalWrite(LED_PIN, LOW); // إطفاء الـ LED
    }
  }
}
