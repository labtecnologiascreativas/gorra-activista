 /*
  **---- Gorra Activista ----**
       (una gorra copada)
  
  El sensor emite un pulso ultrasónico que luego es recibido y leído por el mismo, 
  de esa manera podemos calcular la distancia de un objeto.
  
*/

// las "constantes" no cambian, su usan aquí para
// definir los numeros de pin:
const int echoPin = 9;
const int trigPin = 10;

void setup() {
  // inicializamos la comunicación del puerto Serial:
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

void loop() {
  // establecemos las variables para la duracion del pulso y la distancia resultante
  // en centímetros:
  long duration,cm;

  // el pulso HIGH es disparado por 5 microsegundos
  // antes enviamos un pulso LOW para asegurarnos un pulso HIGH claro
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // El echoPin es usado para leer la señal de vuelta: un pulso HIGH cuya duración
  // es el tiempo que le lleva alcanzar un objeto y volver
  duration = pulseIn(echoPin, HIGH);

  // convertimos el tiempo a distancia (microsegundos a centímetros)
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(1000);
  
  // Establecemos un condicional: si la distancia es menor a 16cm, los leds se encienden
  if(cm < 16){
    digitalWrite(11, HIGH);   // Enciende el led
  }
  // Si es mayor a 16cm, lo apaga
  else {
    digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
          
    }
  
}

long microsecondsToCentimeters(long microseconds) {
  // La velocidad del sonido es 349 m/s, o 29 microsugundos/centímetro
  // El pulso viaja ida y vuelta, por lo tanto para obtener la distancia 
  // al objeto, debemos tomar la mitad de la distancia recorrida
  return microseconds / 29 / 2;
}
