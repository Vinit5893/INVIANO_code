#define BUZZER_PIN 4

void setup() {

pinMode(BUZZER_PIN, OUTPUT);

}

void loop() 
{

 beep(3000);
 beep(4000);

while (1) {

}

}

void beep(unsigned char delayms){
 analogWrite(BUZZER_PIN, 250);      // any value can be used except 0 and 255, try changing
 delay(delayms); 
 analogWrite(BUZZER_PIN, 0);       // off
 delay(delayms); 
}  
