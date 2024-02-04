//Library Inclusion
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <NewPing.h>

//Dimension of the SSD1306
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
//Pins for Ultrasonic Sensor + Max read distance
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200
//Pins for LED 
#define GREEN_LED_PIN 4
#define YELLOW_LED_PIN 5
#define RED_LED_PIN 6
//Pin for buzzer
#define BUZZER_PIN 3


//Initializing the SSD1306 library
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//Initializing the pins & max distance to NewPing
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//Function declarations
void initializeDisplay();
void setDisplay();
void printDistance(unsigned int distance);
void updateLED(unsigned int distance);
void updateBuzzer(unsigned int distance);

void setup() {
  //Intialize serial communication for easy debugging
  Serial.begin(9600);
  //Setting pins
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(GREEN_LED_PIN,OUTPUT);
  pinMode(YELLOW_LED_PIN,OUTPUT);
  pinMode(RED_LED_PIN,OUTPUT);
  initializeDisplay();

}

void loop() {
  unsigned int distance = getDistance();
  setDisplay();
  printDistance(distance);
  updateLED(distance);
  updateBuzzer(distance);


}

//Function to initialize the SSD1306 sisplay 
void initializeDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
}
//Function to set settings for display
void setDisplay() {
  delay(300);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);  
}
//Get distance
unsigned int getDistance() {
  delay(500); // Wait 500ms between pings (about 2 pings/sec). 29ms should be the shortest delay between pings.
  return sonar.ping_cm();
}
//Print distance
void printDistance(unsigned int distance) {
  if (distance == 0) {
    Serial.println("Out of range");
    display.setCursor(0,10);
    display.println("Out of range");
  } else {
    //Print in console
    Serial.print("Ping: ");
    Serial.print(distance); 
    Serial.println("cm");
    //Print on display
    display.setCursor(0,10);
    display.print("Ping: ");
    display.print(distance);
    display.println("cm");
  }
  display.display();
}
//Turn on LED depending on distance
void updateLED(unsigned int distance) {
  if (distance > 10 && distance < 20) {
    digitalWrite(GREEN_LED_PIN,HIGH);
    digitalWrite(YELLOW_LED_PIN,LOW);
    digitalWrite(RED_LED_PIN,LOW);
  } else if (distance > 5 && distance < 11) {
    digitalWrite(GREEN_LED_PIN,LOW);
    digitalWrite(YELLOW_LED_PIN,HIGH);
    digitalWrite(RED_LED_PIN,LOW);
  } else if (distance <= 5 && distance != 0) {
    digitalWrite(GREEN_LED_PIN,LOW);
    digitalWrite(YELLOW_LED_PIN,LOW);
    digitalWrite(RED_LED_PIN,HIGH);
  } else {
    digitalWrite(GREEN_LED_PIN,LOW);
    digitalWrite(YELLOW_LED_PIN,LOW);
    digitalWrite(RED_LED_PIN,LOW);
  }
}
//Buzzer sound based off distance
void updateBuzzer(unsigned int distance) {
  if (distance > 10 && distance < 20) {
    //Play a soft sound
    tone(BUZZER_PIN,1000,100);
  } else if (distance > 5 && distance < 11) {
    //Play a medium sound
    tone(BUZZER_PIN,2000,300);
  } else if (distance <= 5 && distance != 0){
    //Play a loud sound
    tone(BUZZER_PIN,3000,600);
  } else {
    //Play no sound @ >=20 and 0
    noTone(BUZZER_PIN);
  }
}