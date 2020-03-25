
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
//-------------------------
// Capteurs Pince
//-------------------------
// capteur 5 pince
#define trigPin1 38
#define echoPin1 39
// declarationdes variables des capteurs
long duration, distance, Capteur1,Capteur2,Capteur3,Capteur4;
//--------------------------
//    boolean 
bool capteur1 = true;
bool capteur2 = true;
bool capteur3 = true;
bool capteur4 = true;
bool capteurPince = true;
// fin boolean
//
//-------------------------
// Motors Pince
//-------------------------
#include <Servo.h>
Servo myservo;  // création de l'objet myservo 
//
Servo monServomoteur1; //pince fermeture
// servo mouvement
int pin_servo = 10;       // Pin sur lequel est branché le servo
int pos = 0;              // variable permettant de conserver la position du servo
int angle_initial = 0;    //angle initial
int angle_final = 200;    //angle final
int increment = 1;        //incrément entre chaque position
bool angle_actuel = false;//Envoi sur le port série la position courante du servomoteur
//-------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);                       
  while(!Serial){;} 
  //   servo bras
  // attache le servo au pin spécifié sur l'objet myservo 
  myservo.attach(pin_servo);  
  // servo pince
  monServomoteur1.attach(38); // pin 38 pour le servo moteur pince
  // initialisation des moteur
  //-----------------------
  //  Motors
  //-----------------------
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
//----------------------------------------
// function loop bras
void pince_avant_vers_arriere() {
    for (pos = angle_initial; pos <= angle_final; pos += increment) { // Déplace le servo de 0 à 180 degréespar pas de 1 degrée 
    myservo.write(pos);              // Demande au servo de se déplacer à cette position angulaire
    delay(30);                       // Attend 30ms entre chaque changement de position
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
}
void pince_arriere_vers_avant () {
  for (pos = angle_final; pos >= angle_initial; pos -= increment) { // Fait le chemin inverse
    myservo.write(pos);              
    delay(30);   
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  } 
}
// fin function loop bras 
//----------------------------------------
// boucle pour pince
void ouverture() {
  Servo monServomoteur1;
    monServomoteur1.write(110);
}
void fermeture() {
  Servo monServomoteur1;
    monServomoteur1.write(175);
}
// fin boucle pour pince
//----------------------------------------
// boucle moteur 
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
  motor4.run(BACKWARD); //
}
// fin boucle moteur
//----------------------------------------
// boucle capteurs
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
//  reset 
void reset(){
  capteur1 = true;
  capteur2 = true;
  Capteur3 = true;
  capteur4 = true;
}
// fin reset
//
//----------------------------------------
//                                   _ 
//     \    /__  0 |\   |    __  __ | \ 
//      \  /|  | | | |  |   |  ||  ||_/
//       \/ |__| | |/   |__ |__||__||
//      
//-----------------------------------------
void loop() {  
  monServomoteur1.write(110); // ouverture de la pince
  myservo.write(0);           // bras de la pince devant
  //-----------------------
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
  else if (capteurPince < 5 ){
        stopMoteurs();
        capteurPince = true; // montre que l'objet est deja pris
        // if inutile mais fait du contenu 
    if (capteurPince == true ){
        ouverture(); //au cas ou la pince n'est pas ouverte
        avant(); // fait avancer le robot de 2cm pour que l'objet soit dans la portée de la pince
        delay(1000); 
        //
        stopMoteurs(); 
        //
        fermeture();  // normalement l'objet est dans la pince
        delay(1000); // la pince est fermer avec l'objet a l'interieur
        //
        pince_avant_vers_arriere(); // amene l'objet derriere
        delay(1000);
        //
        ouverture(); // ouvre pince afin de depose l'objet derriere
        delay(500);
        //
        pince_arriere_vers_avant(); // le bras revient devant  
        delay(500);
        //
        ouverture();// la pince se reouvre 
        delay(500);
    }
  }
  else {
    avant();
  }
  reset();
  
  //-------------------------
}
