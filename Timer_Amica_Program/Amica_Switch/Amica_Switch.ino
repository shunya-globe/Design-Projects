
unsigned long last_millis = 0;
unsigned long current_millis = 0;
long Set_Delay = 1500;
bool led_state = LOW;
int read_byte = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    read_byte = Serial.parseInt();
  }
    current_millis = millis();
    if (current_millis - last_millis >= read_byte)
    {
      long diff = current_millis - last_millis;
      last_millis = millis();
      Serial.print("delay = ");
      Serial.println(diff);
      if (led_state == LOW)
        led_state = HIGH;
      else
        led_state = LOW;
      digitalWrite(LED_BUILTIN, led_state);
    }
  }
