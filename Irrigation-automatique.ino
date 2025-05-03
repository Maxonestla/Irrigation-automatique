//Soil moisture sensors pins
#define SM1_PIN A0
#define SM2_PIN A1

//Relay pin
#define R_PIN D0

uint8_t get_humidity(uint8_t PIN);

//Boolean to know if the solenoid valve is open or close.
bool ev_open = false;

//Sensor calibration
uint8_t calib = 250;

//Moisture rate
const uint8_t sm1_rate = 50;
const uint8_t sm2_rate = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(SM1_PIN, INPUT);
  pinMode(SM2_PIN, INPUT);
  //pinMode(D0, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //If the solenoid valve is close, we recover data from up sensor.
  if(not ev_open){
    uint16_t sensorValue1 = get_humidity(SM1_PIN);
    uint16_t data = analogRead(SM1_PIN);
    Serial.print(sensorValue1);
    Serial.println("% d'humidité par le capteur du haut");
    Serial.print(data);
    Serial.println(" : valeur ADC");
    if( sensorValue1 < sm1_rate){
      ev_open = true;
      digitalWrite(R_PIN, HIGH);
      Serial.println("Pas assez d'humidité, on ouvre la vanne");
    }
  }
  //Else, we recover data from down sensor.
  else{
    uint16_t sensorValue2 = get_humidity(SM2_PIN);
    Serial.print(sensorValue2);
    Serial.println("% d'humidité par le capteur du bas");
    if( sensorValue2 > sm2_rate){
      ev_open=false;
      digitalWrite(R_PIN, LOW);
      Serial.println("Le sol est assez humide, on ferme la vanne");
    }
  }
  delay(2000);
}

uint8_t get_humidity(uint8_t PIN){
  return uint8_t(100 - ((float)( analogRead(PIN) - calib ) / (1023.0 - calib) ) * 100 );
}
