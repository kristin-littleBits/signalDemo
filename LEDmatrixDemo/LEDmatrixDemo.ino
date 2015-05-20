// include Adafruit libraries
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

// define pins
#define matrixPin 1
#define inputPin 0

Adafruit_NeoMatrix * matrix;
uint8_t rotation = 0;


void setup() {
  pinMode(inputPin, INPUT);
   matrix = new Adafruit_NeoMatrix(8, 8, matrixPin,
    NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
    NEO_RGB            + NEO_KHZ800);
  matrix->begin();
  matrix->setBrightness(30);
  matrix->setTextWrap(false);
}

const uint16_t textColors[] = { matrix->Color(255, 0, 0), matrix->Color(0, 255, 0), matrix->Color(0, 0, 255) }; 
int pinVal;
int pass = 0;
int x = matrix->width();


void loop() {
  pinVal = analogRead(inputPin);
  
  if(pinVal < 255 ){
    showLogo();
  }
  else if(pinVal > 255 && pinVal < 512){
    showEmail();
  }
  else if(pinVal > 512 && pinVal < 767){
    showFlashingLights();
  }
  else{
    drawPacman();
  }
}

// external functions
void showEmail(){
  matrix->fillScreen(0);
  matrix->show();
  matrix->setCursor(x, 0);
  matrix->print(F("kristin.salomon@littlebits.cc"));
  if (--x < -180){
    x = matrix->width();
    if (++pass >= 3){
      pass = 0;
    }
    matrix->setTextColor(textColors[pass]);
  }
  matrix->show();
  delay(100);
};


void showFlashingLights(){
  //from Sean
  delay(30);
  matrix->fillRoundRect(3,3,2,2,0,matrix->Color(0,255,0));
  matrix->show();
  
  delay(30);
  matrix->fillRoundRect(2,2,4,4,0,matrix->Color(0,255,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(1,1,6,6,0,matrix->Color(0,255,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(0,0,8,8,0,matrix->Color(0,255,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(3,3,2,2,0,matrix->Color(255,0,0));
  matrix->show();
  
  delay(30);
  matrix->fillRoundRect(2,2,4,4,0,matrix->Color(255,0,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(1,1,6,6,0,matrix->Color(255,0,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(0,0,8,8,0,matrix->Color(255,0,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(3,3,2,2,0,matrix->Color(0,0,255));
  matrix->show();
  
  delay(30);
  matrix->fillRoundRect(2,2,4,4,0,matrix->Color(0,0,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(1,1,6,6,0,matrix->Color(0,0,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(0,0,8,8,0,matrix->Color(0,0,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(3,3,2,2,0,matrix->Color(255,0,255));
  matrix->show();
  
  delay(30);
  matrix->fillRoundRect(2,2,4,4,0,matrix->Color(255,0,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(1,1,6,6,0,matrix->Color(255,0,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(0,0,8,8,0,matrix->Color(255,0,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(3,3,2,2,0,matrix->Color(255,255,0));
  matrix->show();
  
  delay(30);
  matrix->fillRoundRect(2,2,4,4,0,matrix->Color(255,255,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(1,1,6,6,0,matrix->Color(255,255,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(0,0,8,8,0,matrix->Color(255,255,0));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(3,3,2,2,0,matrix->Color(0,255,255));
  matrix->show();
  
  delay(30);
  matrix->fillRoundRect(2,2,4,4,0,matrix->Color(0,255,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(1,1,6,6,0,matrix->Color(0,255,255));
  matrix->show();
 
  delay(30);
  matrix->fillRoundRect(0,0,8,8,0,matrix->Color(0,255,255));
  matrix->show();  
}


void drawPacman(){
  matrix->fillScreen(0);
  
  int pacman_close[8][8] = {  
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 1, 1, 1, 0, 0, 0},
   {0, 1, 0, 0, 0, 1, 0, 0},
   {1, 0, 0, 0, 0, 0, 1, 0},
   {1, 0, 0, 1, 1, 1, 1, 0},
   {1, 0, 0, 0, 0, 0, 1, 0},
   {0, 1, 0, 0, 0, 1, 0, 0},
   {0, 0, 1, 1, 1, 0, 0, 0}
  };
  
  int pacman_open[8][8] = {  
   {0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 1, 1, 1, 1, 0, 0},
   {0, 1, 0, 0, 0, 0, 1, 0},
   {1, 0, 0, 0, 0, 1, 0, 0},
   {1, 0, 0, 0, 1, 0, 0, 0},
   {1, 0, 0, 0, 0, 1, 0, 0},
   {0, 1, 0, 0, 0, 0, 1, 0},
   {0, 0, 1, 1, 1, 1, 0, 0}
  };
 
  for(int row = 0; row < 8; row++) {
    for(int column = 0; column < 8; column++) {
     if(pacman_close[row][column] == 1) {
       matrix->drawPixel(column, row, matrix->Color(255,255,0));
     }
   }
  }
  matrix->show();
  delay(500);
  
  matrix->fillScreen(0);
  for(int row = 0; row < 8; row++) {
    for(int column = 0; column < 8; column++) {
     if(pacman_open[row][column] == 1) {
       matrix->drawPixel(column, row, matrix->Color(255,255,0));
     }
   }
  }
  matrix->show();
  delay(500);
  
}

void showLogo(){
  matrix->fillScreen(0);
  matrix->show();
  matrix->setCursor(x, 0);
  matrix->setTextColor(matrix->Color(0, 75, 130));
  matrix->print(F("littleBits"));
  if (--x < -60){
    x = matrix->width();
  }
  matrix->show();
  delay(100);
};
