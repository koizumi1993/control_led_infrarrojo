#include <IRremote.h>
int RECV_PIN = 11;             //pin que recibe la señal
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);               //inicializamos el puerto serial a 9600
  pinMode(7, OUTPUT);          //declaramos pines de salida para los LEDs
   pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
 
  irrecv.enableIRIn();                     // Comienza a recibir los datos
}
 
void loop()
{
  results.value=0;
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);             // imprime el valor en codigo hexadecimal
     irrecv.resume();                                      // Se preparar para recibir  el siguiente valor
 
}
 while(results.value ==0xE0E020DF)    //comparamos el valor recibido con un valor seleccionado
 {
 digitalWrite(7, HIGH);                     //si es verdadero pondra en estado alto el pin 7
 delay(100);                                //espera 100ms antes de tomar el siguiente dato
 
  if (irrecv.decode(&results))
 {
    Serial.println(results.value, HEX);
     irrecv.resume(); 
 
}
}
 digitalWrite(7, LOW);             //Al momento que se deja de cumplir la condicion pasa a estado bajo
 
 while(results.value == 0xE0E0A05F)   //comparamos otro valor
 {
digitalWrite(6, HIGH);
 delay(100);
 
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
     irrecv.resume();
 
}
}
 digitalWrite(6, LOW);
 
  while(results.value == 0xE0E0609F)      //condicion para encender el tercer LED
 {
   digitalWrite(5, HIGH);
 delay(100);
 
  if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
     irrecv.resume();
 
}
}
 digitalWrite(5, LOW);
 
 }
