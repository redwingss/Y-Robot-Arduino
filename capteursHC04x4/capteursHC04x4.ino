//work good

//declaration de pins
//--------------------------------------------
//capteur 1
#define trigPin1 52
#define echoPin1 53
//capteur 2
#define trigPin2 48
#define echoPin2 49
// capteur 3
#define trigPin3 44
#define echoPin3 45
// capteur 4
#define trigPin4 40
#define echoPin4 41

// declarationdes variables
long duration, distance, Capteur1,Capteur2,Capteur3,Capteur4;

void setup()
{
Serial.begin (9600);
// capteur 1
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
// capteur 2
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
// capteur 3
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
// capteur 4
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
}

void loop() {
// capteur 1
SonarSensor(trigPin1, echoPin1);
Capteur1 = distance;
// capteur 2
SonarSensor(trigPin2, echoPin2);
Capteur2 = distance;
// capteur 3
SonarSensor(trigPin3, echoPin3);
Capteur3 = distance;
// capteur 4
SonarSensor(trigPin4, echoPin4);
Capteur4 = distance;

// capteur 1
Serial.print("Capteur1 :");
Serial.println(Capteur1);
Serial.print("-----------");
// capteur 2
Serial.print("Capteur2 :");
Serial.println(Capteur2);
Serial.print("-----------");
// capteur 3
Serial.print("Capteur3 :");
Serial.println(Capteur3);
Serial.print("-----------");
// capteur 4
Serial.print("Capteur4 :");
Serial.println(Capteur4);
// mise en page
Serial.print("--------------------");
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
delay(200);

}
