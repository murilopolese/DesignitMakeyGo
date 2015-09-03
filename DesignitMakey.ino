#include <CapacitiveSensor.h>

// Orange pin
CapacitiveSensor sensor1 = CapacitiveSensor( 10, 9 );
// Yellow
CapacitiveSensor sensor2 = CapacitiveSensor( 16, 8 );
// White pin
CapacitiveSensor sensor3 = CapacitiveSensor( 14, 7 );
// Blue pin
CapacitiveSensor sensor4 = CapacitiveSensor( 15, 6 );

boolean sensor1Active = false;
boolean sensor2Active = false;
boolean sensor3Active = false;
boolean sensor4Active = false;
                              
// Global Threshold
// Use 8000 if you are using 5M ohms resistance
int ACTIVATION_THRESHOLD = 1000;
int RELEASE_THRESHOLD = 1000;  

void setup() {
  Serial.begin( 9600 );
  Keyboard.begin();
  
  // Initialize sensors/pins auto calibration 
  // To set autocalibration off use the value: 0xFFFFFFFF
  sensor1.set_CS_AutocaL_Millis( 5000 );
  sensor2.set_CS_AutocaL_Millis( 5000 );
  sensor3.set_CS_AutocaL_Millis( 5000 );
  sensor4.set_CS_AutocaL_Millis( 5000 );

  // If the sensors do not answer in 1 second, timeout them
  sensor1.set_CS_Timeout_Millis( 1000 );
  sensor2.set_CS_Timeout_Millis( 1000 );
  sensor3.set_CS_Timeout_Millis( 1000 );
  sensor4.set_CS_Timeout_Millis( 1000 );
}

void loop() {
  // Read value from sensors
  int value1 = sensor1.capacitiveSensor( 20 );
  int value2 = sensor2.capacitiveSensor( 20 );
  int value3 = sensor3.capacitiveSensor( 20 );
  int value4 = sensor4.capacitiveSensor( 20 );

  sensor1Action( value1 );
  sensor2Action( value2 );
  sensor3Action( value3 );
  sensor4Action( value4 );

  Serial.print( "ACTIVATION_THRESHOLD " );
  Serial.println( ACTIVATION_THRESHOLD );
  Serial.print( "RELEASE_THRESHOLD " );
  Serial.println( RELEASE_THRESHOLD );
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


void sensor1Action( int value ) {

  if( value > ACTIVATION_THRESHOLD ) {
    if( sensor1Active == false ) {
      sensor1Active = true;
      Mouse.press();
    }
  }

  if( value < RELEASE_THRESHOLD ) {
    sensor1Active = false;
    Mouse.release();
  }

}

void sensor2Action( int value ) {
  if( value > ACTIVATION_THRESHOLD ) {
    if( sensor2Active == false ) {
      sensor2Active = true;
      Keyboard.press( ' ' );
    }
  }

  if( value < RELEASE_THRESHOLD ) {
    sensor2Active = false;
    Keyboard.release( ' ' );
  }
  
}

void sensor3Action( int value ) {
  if( value > ACTIVATION_THRESHOLD ) {
    if( sensor3Active == false ) {
      sensor3Active = true;
      Keyboard.press( KEY_RIGHT_ARROW );
    }
  }

  if( value < RELEASE_THRESHOLD ) {
    if( sensor3Active == true ) {
      Keyboard.release( KEY_RIGHT_ARROW );
      sensor3Active = false;
    }
  }
  
}

void sensor4Action( int value ) {
  if( value > ACTIVATION_THRESHOLD ) {
    if( sensor4Active == false ) {
      sensor4Active = true;
      Keyboard.press( KEY_LEFT_ARROW );
    }
  }

  if( value < RELEASE_THRESHOLD ) {
    sensor4Active = false;
    Keyboard.release( KEY_LEFT_ARROW );
  }
  
}
