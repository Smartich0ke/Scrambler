#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     4 
#define BUTTON_1 8
#define BUTTON_2 7
#define BUTTON_3 6

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char setArray[6] = {'U', 'F', 'B', 'D', 'R', 'L'};
int i = 0;
char completedMove;
int totalNum;
int inputLength;
int button1State;
int button2State;
int button3State;
int scrambleType;

int randomNum() {

  //randomSeed(analogRead(A0));
  int a = random(1, 100);
  a = a + 1;
  return a;
}
void do3x3Scramble() {
    randomSeed(millis());
    while(i++ < inputLength) {
    bool doTwo = false;
    bool addOne = false;
    bool ignore = false;
    int r = randomNum();
    int initFirst = (r % 10);
    int initNon = ((int)(r / 10));
    if ((initNon) > 5){
      addOne = true;
    }
    if ((((initNon) * 3) % 10) > 3){
      doTwo = true;
}
    if (initFirst > 5){
      initFirst = initFirst / 2;
    }
    char turn;
    turn = setArray[initFirst];
    r /= 10;
    if (turn != completedMove){
      if (addOne == true && ignore == false){
        if (doTwo == true){
          
          Serial.print(turn);
          display.write(turn);
          Serial.print("2");
          display.write("2");
        }
        else {
          
          Serial.print(turn);
          display.write(turn);
          Serial.print ("'");
          display.write("'");
        }
      }
      else if (addOne != true && ignore == false){
        if (doTwo == true) {
          
          Serial.print(turn);
          display.write(turn);
          Serial.print("2");
          display.write("2");
        }
        else {
        Serial.print(turn);
        display.write(turn);
        
      }

      }
      if (ignore == false){
        display.write(" ");
        Serial.print(" ");
      }
    }

    completedMove = turn;


  }
  Serial.print("\n");

}
void runScramble(int t) {
switch (t) {
case 0:
    display.clearDisplay();
    display.setCursor(0, 4);
    display.setTextSize(1.8);
    display.write("scrambling...");
    display.display();
    delay(50);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.write("3x3");
    display.setCursor(0, 20);
    display.display();
    inputLength = 28;
    do3x3Scramble();
    display.display();
  break;
case 1:
    display.clearDisplay();
    display.setCursor(0, 4);
    display.setTextSize(1.8);
    display.write("scrambling...");
    display.display();
    delay(50);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.write("2x2");
    display.setCursor(0, 20);
    display.display();
    inputLength = 20;
    do3x3Scramble();
    display.display();
break;
default:
  break;
}
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.cp437(true);
  display.write(" Scrambler\n  v0.3.0"); 
  display.setCursor(0, 40);
  display.setTextSize(1.2);
  display.write("    By Artichoke");
  display.display();
}

void loop() {
button1State = digitalRead(BUTTON_1);
button2State = digitalRead(BUTTON_2);
button3State = digitalRead(BUTTON_3);
if(button3State == 0) {
  delay(50);
  scrambleType++;
  if (scrambleType > 1)  {
    scrambleType = 0;
  }
  runScramble(scrambleType);
}
if(button2State == 0) {
  delay(50);
  runScramble(scrambleType);
}
}