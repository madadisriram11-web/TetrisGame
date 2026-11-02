#include <LedControl.h>

//Set up LED Matrix
LedControl lc = LedControl(12, 9, 10, 4);

//Set up buttons
const int pinStartStop = 2;
const int pinPause = 4;
const int pinStore = 5;

//Set up joystick
const int pinx = A0;
const int pin y = A1;

//bools
bool isPlaying = false;
bool isPaused = false;

void setup() {
  // put your setup code here, to run once:

  //Setting up all of the LED Matrix Settings
  Serial.begin(9600);
  int devices = lc.getDeviceCount();
  for (int i = 0; i<devices; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 6);
    lc.clearDisplay(i);
  }

  //Initializing the buttons
  pinmode(pinStartStop, INPUT_PULLUP);
  pinmode(pinPause, INPUT_PULLUP);
  pinmode(pinStore, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Always checks for buttons being clicked
  handlebuttons();

  if (isPlaying && !isPaused) {
    readJoystick();
    updateGameLogic();
    renderGame();
    delay(150)

  }
}

void handleButtons() {

  if (digitalRead(pinStartStop) == LOW) {
    isPlaying = !isPlaying;
    Serial.println(isPlaying ? "Game Started" : "Game Stopped");
    delay(250);
  }

  if (digitalRead(pinPause) == LOW && isPlaying) {
    isPaused = !isPaused;
    Serial.println(isPaused? "Game Paused" : "Game Resumed");
    delay(250);
  }

  if(digitalRead(pinStore) == LOW && isPlaying && !isPaused) {
    Serial.println("Store Action Triggered");
    delay(250);
  }
}

void readJoysticks() {

  int xVal = analogRead(pinx);
  int yVal = analogRead(piny);

  if (xVal < 250) {
    Serial.println("Move left");
  } else if (xVal > 750) {
    Serial.println("Move right");
  }

  if (yVal < 250) {
    Serial.println("Soft Drop (Down)");
  }

}

void updateGameLogic(){

}

void renderGame() {
  
}