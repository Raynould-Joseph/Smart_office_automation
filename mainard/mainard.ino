const int pingPin = 15; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 14; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(0,OUTPUT);// wait for a second
  digitalWrite(LED_BUILTIN,HIGH);
}

String incomingdata = "";

void loop()
{
  // for motion detection
  
  long duration, inches;   
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);      
  // if motion is detected within 5 Inches from the sensor:
  if(inches < 4)
  {
    Serial.println("start");
    digitalWrite(0, HIGH);
  }
  else
  {
    Serial.println(inches);
  }
  
  // response from AI module to turn ON and OFF lights
  incomingdata = Serial.readString();
  if(incomingdata=="ON")
  {
    digitalWrite(0,HIGH);
  }
  if(incomingdata == "OFF")
  {
    digitalWrite(0,LOW);
  }
  
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
