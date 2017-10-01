char matrix[][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

void setup() {
  Serial.begin(9600);
  DDRA = 0xFF;
  DDRB = 0xFF;
}

void loop() {
  displayMatrix();
  if(Serial.available() >= 4){
    int a = Serial.parseInt();
    if(Serial.read() == 'X') matrix[(a / 100)][((a / 10) % 10)] = (a % 10);
  }  
}

void displayMatrix(){
  for(int i = 0; i < 8; i++){
    byte a;
    for(int j = 0; j < 8; j++) a += (matrix[i][j] << j);
    PORTB = _BV(i);
    PORTA = a;
  }
}
