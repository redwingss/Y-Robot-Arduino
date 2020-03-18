//-------------------------
// Motors
//-------------------------
#include <AFMotor.h>
// moteur1
AF_DCMotor motor1(1);
// moteur2
AF_DCMotor motor2(2);
// moteur3
AF_DCMotor motor3(3);
// moteur4
AF_DCMotor motor4(4);
//-------------------------
// Capteurs
//-------------------------
//declaration des pins
//
//capteur 1 devant 
#define trigPin1 52
#define echoPin1 53
//capteur 2 droite
#define trigPin2 48
#define echoPin2 49
// capteur 3 gauche
#define trigPin3 44
#define echoPin3 45
// capteur 4 derriere
#define trigPin4 40
#define echoPin4 41
// declarationdes variables
long duration, distance, Capteur1,Capteur2,Capteur3,Capteur4;
//--------------------------
//    boolean 
bool capteur1 = true;
bool capteur2 = true;
bool capteur3 = true;
bool capteur4 = true;
// fin boolean
//-------------------------

void setup() 
{
  // initialisation des moteur
  //Set initial speed of the motor 0 to 255
        // moteur1
    motor1.setSpeed(255);
         // moteur2
    motor2.setSpeed(255);
         // moteur3
    motor3.setSpeed(255);
         // moteur4
    motor4.setSpeed(255);
  //-----------------------
  //  Capteurs
  //-----------------------
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
  capteur();
  // Now turn off motor
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE); 
    motor4.run(RELEASE);
  // fin motor   
  
  //---------------------test 
  if (Capteur1 < 20 ){
      stopMoteurs();
      delay(1000);
      capteur1 = false;
    if ((Capteur2 > 20) && (capteur1 == false ) )
    {
      stopMoteurs();
      delay(1000);
      gauche();
      capteur2 = false;
    }
    else if ((Capteur3 > 20) && (capteur1 == false ) && (capteur2 == false ))
    {
      stopMoteurs();
      delay(1000);
      droite();
      capteur3 = false;
    }
    else {
      stopMoteurs();
      delay(1000);
      // rotation 360° vers gauche ou droite ??
      rotation_droite(); // ou  rotation_gauche();
    }
  }
  else {
    avant();
  }
  reset();
}
//    debut boucle motors
void avant(){
           // AVANT  
      //moteur 1
  motor1.run(FORWARD); // turn it on going forward
      //moteur 2
  motor2.run(FORWARD); // turn it on going forward
      //moteur 3
  motor3.run(FORWARD); // turn it on going forward
      //moteur 4
  motor4.run(FORWARD); // turn it on going forward
}
void stopMoteurs(){
          // stop 
      //moteur 1
  motor1.run(RELEASE); // stopped / moteur  stop 
      //moteur 2
  motor2.run(RELEASE); // stopped / moteur  stop 
      //moteur 3
  motor3.run(RELEASE); // stopped / moteur  stop 
      //moteur 4
  motor4.run(RELEASE); // stopped / moteur  stop 
}
void retour(){
        //retour
      //moteur 1
  motor1.run(BACKWARD); // turn it on going forward
    //moteur 2
  motor2.run(BACKWARD); // turn it on going forward
    //moteur 3
  motor3.run(BACKWARD); // turn it on going forward
    //moteur 4
  motor4.run(BACKWARD); // turn it on going forward
}
void droite(){
    //droite
  //moteur 1
  motor1.run(BACKWARD);
    //moteur 2
  motor2.run(FORWARD); 
    //moteur 3
  motor3.run(BACKWARD); 
    //moteur 4
  motor4.run(FORWARD); 
}
void gauche(){
    //gauche
  //moteur 1
  motor1.run(FORWARD); 
    //moteur 2
  motor2.run(BACKWARD); 
    //moteur 3
  motor3.run(FORWARD); 
    //moteur 4
  motor4.run(BACKWARD); 
}
void avant_gauche(){
    //avant diagonale gauche
  //moteur 1
  motor1.run(FORWARD); 
  //moteur 2
  motor2.run(RELEASE);
    //moteur 3
  motor3.run(FORWARD); 
    //moteur 4
  motor4.run(RELEASE); 
}
void avant_droite(){
    //avant diagonale droite
  //moteur 1
  motor1.run(RELEASE); 
    //moteur 2
  motor2.run(FORWARD); 
    //moteur 3
  motor3.run(RELEASE); 
    //moteur 4
  motor4.run(FORWARD); 
}
void arriere_gauche(){
    //arriere diagonale gauche
    //moteur 1
  motor1.run(RELEASE); 
    //moteur 2
  motor2.run(BACKWARD); 
    //moteur 3
  motor3.run(RELEASE); 
    //moteur 4
  motor4.run(BACKWARD);
}
void arriere_droite(){
    //arriere diagonale droite
  //moteur 1
  motor1.run(BACKWARD); 
    //moteur 2
  motor2.run(RELEASE); 
    //moteur 3
  motor3.run(BACKWARD);
    //moteur 4
  motor4.run(RELEASE); 
}
void rotation_gauche(){
    //rotation 360° vers la gauche
  //moteur 1
  motor1.run(BACKWARD); 
    //moteur 2
  motor2.run(FORWARD); 
    //moteur 3
  motor3.run(FORWARD); 
    //moteur 4
  motor4.run(BACKWARD);
}
void rotation_droite(){
    //rotation 360° vers la droite
  //moteur 1
  motor1.run(FORWARD); 
    //moteur 2
  motor2.run(BACKWARD);
    //moteur 3
  motor3.run(BACKWARD);
    //moteur 4
  motor4.run(FORWARD); 
}
//    fin boucle motors

//    boucle capteur
void SonarSensor(int trigPin,int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  delay(200);
} 
void capteur(){
  // boucle pour 
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
  Serial.println("-----------");
  // capteur 2
  Serial.print("Capteur2 :");
  Serial.println(Capteur2);
  Serial.println("-----------");
  // capteur 3
  Serial.print("Capteur3 :");
  Serial.println(Capteur3);
  Serial.println("-----------");
  // capteur 4
  Serial.print("Capteur4 :");
  Serial.println(Capteur4);
  // mise en page
  Serial.println("--------------------");
}
//    fin boucle capteurs
//    function reset
void reset(){
  capteur1 = true;
  capteur2 = true;
  Capteur3 = true;
  capteur4 = true;
}
