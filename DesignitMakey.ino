#include <CapacitiveSensor.h>

// Orange pin
CapacitiveSensor sensor1 = CapacitiveSensor( 10, 9 );
// Yellow
CapacitiveSensor sensor2 = CapacitiveSensor( 16, 8 );
// White pin
CapacitiveSensor sensor3 = CapacitiveSensor( 14, 7 );
// Blue pin
CapacitiveSensor sensor4 = CapacitiveSensor( 15, 6 );
                              
// Potentiometer - Threshold
int tValue = 8000;

void setup() {
  Serial.begin( 9600 );
  Keyboard.begin();
  
  // Initialize sensors/pins
  sensor1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  sensor2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  sensor3.set_CS_AutocaL_Millis(0xFFFFFFFF);
  sensor4.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
  // Value for sensors
  int value1 = sensor1.capacitiveSensor(50);
  int value2 = sensor2.capacitiveSensor(50);
  int value3 = sensor3.capacitiveSensor(50);
  int value4 = sensor4.capacitiveSensor(50);

  boolean sensor1Active = value1 > tValue;
  sensor1Action( sensor1Active );
  
  boolean sensor2Active = value2 > tValue;
  sensor2Action( sensor2Active );
  
  boolean sensor3Active = value3 > tValue;
  sensor3Action( sensor3Active );
  
  boolean sensor4Active = value4 > tValue;
  sensor4Action( sensor4Active );

  Serial.print( "tValue " );
  Serial.println( tValue );
  Serial.print( "sensor1 " );
  Serial.println( value1 );
  Serial.print( "sensor2 " );
  Serial.println( value2 );
  Serial.print( "sensor3 " );
  Serial.println( value3 );
  Serial.print( "sensor4 " );
  Serial.println( value4 );
  
  delay(10);   
}

void sensor1Action( boolean active ) {
  if( active ) {
    Mouse.press();
  } else {
    Mouse.release();
  }
}

void sensor2Action( boolean active ) {
  if( active ) {
    Keyboard.press( ' ' );
  } else {
    Keyboard.release( ' ' );
  }
}
void sensor3Action( boolean active ) {
  if( active ) {
    Keyboard.press( KEY_RIGHT_ARROW );
  } else {
    Keyboard.release( KEY_RIGHT_ARROW );
  }
}
void sensor4Action( boolean active ) {
  if( active ) {
    Keyboard.press( KEY_LEFT_ARROW );
  } else {
    Keyboard.release( KEY_LEFT_ARROW );
  }
}

