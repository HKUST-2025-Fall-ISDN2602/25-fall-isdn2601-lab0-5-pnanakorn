// the number of the LED pin
const int vrPin = 36;  // 5 corresponds to GPIO5

// setting PWM properties
const int freq = 5000;
const int resolution = 8;
 
void setup(){
  //This function is used to setup LEDC pin with given frequency and resolution. 
  //LEDC channel will be selected automatically.
  //bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);
  //pin select LEDC pin.
  //freq select frequency of pwm.
  //resolution select resolution for LEDC channel. Range is 1-14 bits (1-20 bits for ESP32).
  //The LEDC channel will be selected automatically
  Serial.begin(115200);
  pinMode(vrPin, INPUT);
  ledcAttach(vrPin, freq, resolution);

}
 
void loop(){

  //bool ledcWrite(uint8_t pin, uint32_t duty);
  int vr_value = analogRead(vrPin);
  int dutyCycle = map(vr_value, 0, 4095, 0, 255);
  Serial.println(dutyCycle);

  ledcWrite(vrPin, dutyCycle);
  delay(100);
}
