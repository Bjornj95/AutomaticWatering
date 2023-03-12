// Plant.cpp
#include "Plant.h"

int MAX = 513; // Very dry
int DRY = 400;
int MEDIUM = 360; // Would be reasonable to water
int MOIST = 310;
int MIN = 215; // Very moist

int TOMATO_WATERING_LEVEL = 350; //370
int CHILLI_WATERING_LEVEL = 480;

Plant::Plant(const uint8_t& sensor_pin, int motor_pin, int plant_type, int start_time) {
  this -> sensor_pin = sensor_pin;
  this -> motor_pin = motor_pin;
  this -> plant_type = plant_type;
  this -> current_hour = start_time;
  this -> moist_level = 0;
  for ( int i = 0; i < 23; i++ ){
    this -> amount_last_24h[i] = 0;
  }
  if(this -> plant_type == 0){
    this -> water_at = TOMATO_WATERING_LEVEL;
  }else if(this -> plant_type == 1){
    this -> water_at = CHILLI_WATERING_LEVEL;
  }
  pinMode(motor_pin, OUTPUT);
  digitalWrite(motor_pin, HIGH);
  pinMode(sensor_pin, INPUT);
  //blink_light(1);
}
    
void Plant::check_and_water() {
  this -> moist_level = analogRead(sensor_pin);
  
  print_status();

  if(this -> moist_level > this -> water_at){
    Serial.println("Try to water");
    run_motor_for_seconds(4);
    
    
  }else{
    Serial.println(" Do nothing \n");
  }
    
  add_time();
}

void Plant::run_motor_for_seconds(int secs) {
  int total_watered = 0;
  for ( int i = 0; i < 23; i++ )
    total_watered += this -> amount_last_24h[i];
    Serial.println(total_watered);
  if(total_watered < 56){
    Serial.println("Watered");
    digitalWrite(this -> motor_pin, LOW);
    Serial.println("Watered");
    delay(secs*1000);
    Serial.println("Watered");
    digitalWrite(this -> motor_pin, HIGH);
    Serial.println("Watered");
    this -> amount_last_24h[current_hour-1] = secs;
  }else{
    this -> amount_last_24h[current_hour-1] = 0;
  }
  
}

void Plant::add_time(){
  //blink_light(5);
  if(this -> current_hour == 24){
    this -> current_hour = 1;
  }
  else{
    this -> current_hour++;
  }
}

void Plant::blink_light(int number_of_blinks){
  //int pin_state = digitalRead(13);
  digitalWrite(13, LOW);
  delay(1000);
  for(int i = 0; i < number_of_blinks; i++){
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  //digitalWrite(13, pin_state);
}

void Plant::print_status(){
  Serial.println();
  Serial.print("--------------------");
  Serial.println();
  Serial.print(this -> sensor_pin);
  Serial.println();

  Serial.print("Time: ");
  Serial.print(this -> current_hour);
  Serial.println();
  
  Serial.print("Moist level: ");
  Serial.print(this -> moist_level);
  Serial.println();

  Serial.print("Water at: ");
  Serial.print(this -> water_at);
  Serial.println();

  Serial.print("Watered last 24: ");
  for ( int i = 0; i < 23; i++ ){
    Serial.print(this -> amount_last_24h[i]);
    Serial.print(" ");
  }
  Serial.println();
}
