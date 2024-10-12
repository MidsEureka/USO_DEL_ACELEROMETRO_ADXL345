/*USO DEL ACELEROMETRO ADXL345
 * 
 * Explicación: Este código lee continuamente los valores de aceleración en los ejes X, Y y Z de nuestro acelerometro ADXL345. 
 * Este los muestra en el monitor serial con un retraso de tiempo de 1 segundo entre cada lectura. Si nuestro acelerometro no está 
 * conectado correctamente, se notifica a través de mensajes en el monitor serial y el código se detiene.
 * 
 * Conexiones:
 * SDA del acelerometro = Pin analogico del Arduino A4
 * SCL del acelerometro = Pin analogico del Arduino A5
 * VCC del acelerometro = 5V del Arduino
 * GND del acelerometro = GND del Arduino
 * 
 * CODIGO HECHO POR: EurekaMinds
 * 
 * SUSCRIBETE AL CANAL PARA MÁS TUTORIALES COMO ESTE
 */


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified acelerometro = Adafruit_ADXL345_Unified();  // Ejecutamos el ADXL345

void setup() {
  Serial.begin(9600); // Iniciamos el monitor serial a 9600 baurios

  if(!acelerometro.begin()) {  // Ponemos una condición para verificar si hay una conexión del sensor a la placa
    Serial.println("No se logró comunicar con el acelerometro ADXL345");  // imprimir en el monitor serial
    Serial.println("Revisa tus conexiones");  // imprimir en el monitor serial
    while(true);  // Esperamos que el sensor se conecte correctamente a la placa
  }
}

void loop() {
  sensors_event_t event;
  acelerometro.getEvent(&event);

  Serial.print("EJE X= "); Serial.print(event.acceleration.x); Serial.print(" ");  // imprimimos los valores de X en el monitor serial
  Serial.print("EJE Y= "); Serial.print(event.acceleration.y); Serial.print(" ");  // imprimimos los valores de X en el monitor serial
  Serial.print("EJE Z= "); Serial.print(event.acceleration.z); Serial.println(" ");  // imprimimos los valores de X en el monitor serial
  delay(1000);  // tiempo de espera de un segundo para la siguiente lectura del Acelerometro
}
