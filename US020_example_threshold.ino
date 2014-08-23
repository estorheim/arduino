/* YourDuino SKETCH UltraSonic Serial 2.0
 Runs HC-04 and SRF-06 and other Ultrasonic Modules
 Open Serial Monitor to see results
 Reference: http://playground.arduino.cc/Code/NewPing
 Questions?  terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <NewPing.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define  TRIGGER_PIN  11
#define  ECHO_PIN     10
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).
                         //Maximum sensor distance is rated at 400-500cm.
/*-----( Declare objects )-----*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
/*-----( Declare Variables )-----*/
int DistanceIn;
int DistanceCm;
int led = 13;
int led2 = 5;
int led3 = 6;
int threshold = 10;
int threshold2 = 40;
int threshold3 = 100;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  Serial.println("UltraSonic Distance Measurement");
  Serial.println("YourDuino.com  terry@yourduino.com");
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  //delay(100);// Wait 100ms between pings (about 10 pings/sec). 29ms should be the shortest delay between pings.
  //DistanceIn = sonar.ping_in();
  //Serial.print("Ping: ");
  //Serial.print(DistanceIn); // Convert ping time to distance and print result 
                            // (0 = outside set distance range, no ping echo)
  //Serial.print(" in     ");
  
  delay(100);// Wait 100ms between pings (about 10 pings/sec). 29ms should be the shortest delay between pings.
  DistanceCm = sonar.ping_cm();
  //Serial.print("Ping: ");
  //Serial.print(DistanceCm); 
  //Serial.println(" cm");  
   if (DistanceCm < threshold && DistanceCm > 0) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led,LOW);
  }

   if (DistanceCm < threshold2 && DistanceCm > threshold) {
    digitalWrite(led2, HIGH);
  }
  else {
    digitalWrite(led2,LOW);
  }
  
     if (DistanceCm < threshold3 && DistanceCm > threshold2) {
    digitalWrite(led3, HIGH);
  }
  else {
    digitalWrite(led3,LOW);
  }

}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

// None
//*********( THE END )***********
