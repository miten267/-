#define PIN_LED 7
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT)
  ;Serial.begin(115200); //Initalize serial port
  while(!Serial) {
    ; // wait for serial port to connect.
  }
  toggle = 1;
  count = 0;
  digitalWrite(PIN_LED, toggle); // turn off LED.
  delay(1000);
}

void loop() {
  toggle = toggle_state(toggle); //toggle LED value.
  digitalWrite(PIN_LED, toggle); //update LED status.
  delay(200); //wait for 1,000 milliseconds
  if(count == 10){
    digitalWrite(PIN_LED, 0);
    while(1){}
  }
}

int toggle_state(int toggle) {
  if(toggle == 0){
    toggle = toggle + 1;
    count += 1;
  }
  else if(toggle == 1){
    toggle = 0;
    count += 1;
  }
  return toggle;
}
