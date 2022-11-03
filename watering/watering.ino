#include "Plant.h"

//int MAX = 513; // Very dry
//int MIN = 215; // Very moist

Plant plant1(A0, 2, 0); // Tomato
Plant plant2(A1, 4, 0); // Tomato
Plant plant3(A2, 7, 0); // Tomato
Plant plant4(A3, 8, 0); // Tomato


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  
  // put your main code here, to run repeatedly:
while(true){
  //delay(30)
  plant1.check_and_water();
  plant2.check_and_water();
  plant3.check_and_water();
  plant4.check_and_water();
  delay(3000);
  
  }
}
