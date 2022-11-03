int MAX = 513; // Very dry
int DRY = 400;
int MOIST = 310;
int MIN = 215; // Very moist

int i = 0;

int moist_sensor_one_value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
}

void loop() {

  
  // put your main code here, to run repeatedly:
while(true){
  moist_sensor_one_value = analogRead(A0);
  Serial.println(moist_sensor_one_value);
  
  }
}
