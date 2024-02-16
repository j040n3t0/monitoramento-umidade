
#define red 2
#define yellow 0
#define green 4

const int SensorPin = A0;
int soilMoistureValue = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(red,  OUTPUT);
  pinMode(yellow,  OUTPUT);
  pinMode(green,  OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

}

void ledVerde(){
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  Serial.println("Nivel de umidade -> OK");
}

void ledAmarelo(){
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  Serial.println("Nivel de umidade -> ATENCAO");
}

void ledVermelho(){
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  Serial.println("Nivel de umidade -> CRITICO");
}

void loop() {
  soilMoistureValue = analogRead(SensorPin);
  Serial.println(soilMoistureValue);
  if(soilMoistureValue < 450){ // Valor obtido com o sensor molhado
    ledVerde();
  }else if (soilMoistureValue > 600){ // Valor obtido com o sensor seco
    ledVermelho();
  } else {
    ledAmarelo();
  }
  delay(1000);
}
