int sensorMouse = 9;
int sensorSpace = 8;
int sensorRight = 7;
int sensorLeft = 6;

bool mouseOn = false;
bool spaceOn = false;
bool rightOn = false;
bool leftOn = false;

int threshold = 2;

void setup() {
  Serial.begin( 9600 );
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  int valueMouse = readCapacitivePin( sensorMouse );
  int valueSpace = readCapacitivePin( sensorSpace );
  int valueRight = readCapacitivePin( sensorRight );
  int valueLeft = readCapacitivePin( sensorLeft );

  if( valueMouse > threshold ) {
    if( mouseOn == false ) {
      mouseOn = true;
      Mouse.press();
    }
  } else {
    mouseOn = false;
    Mouse.release();
  }
  
  if( valueSpace > threshold ) {
    if( spaceOn == false ) {
      spaceOn = true;
      Keyboard.press( ' ' );
    }
  } else {
    spaceOn = false;
    Keyboard.release( ' ' );
  }
  
  if( valueRight > threshold ) {
    if( rightOn == false ) {
      rightOn = true;
      Keyboard.press( KEY_RIGHT_ARROW );
    }
  } else {
    rightOn = false;
    Keyboard.release( KEY_RIGHT_ARROW );
  }
  
  if( valueLeft > threshold ) {
    if( leftOn == false ) {
      leftOn = true;
      Keyboard.press( KEY_LEFT_ARROW );
    }
  } else {
    leftOn = false;
    Keyboard.release( KEY_LEFT_ARROW );
  }
  
  Serial.print("Mouse:");
  Serial.print(valueMouse);
  Serial.print(";");
  Serial.print("Space:");
  Serial.print(valueSpace);
  Serial.print(";");
  Serial.print("Right:");
  Serial.print(valueRight);
  Serial.print(";");
  Serial.print("Left:");
  Serial.print(valueLeft);
  Serial.println(";");

  delay(50);
}

